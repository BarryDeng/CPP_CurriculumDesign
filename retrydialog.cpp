#include "retrydialog.h"
#include "ui_retrydialog.h"
#include "FlightInfo.h"
#include "Passenger.h"
#include "FlightManager.h"
#include "UserManager.h"
#include <QMessageBox>

extern FlightManager flightManager;
extern UserManager userManager;

RetryDialog::RetryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RetryDialog)
{
    ui->setupUi(this);
}

RetryDialog::~RetryDialog()
{
    delete ui;
}

void RetryDialog::retry(FlightInfo fli, Passenger pgr)
{
    QString info;
    info.sprintf("%s %s\n%s 飞往 %s",fli.getNo(),fli.getStartDate(),fli.getStartCity(),fli.getEndCity());
    ui->Ticket->setText(info);
    passenger = new Passenger(pgr);
    flightinfo = new FlightInfo(fli);
}

void RetryDialog::on_buttonBox_accepted()
{
    int before = passenger->getCreditCardMoney();
    int use, after;
    if (ui->radioButton->isChecked())
    {
        use = flightinfo->getFirstPrice();
        after = before - use;
        if (after < 0)
        {
            QMessageBox::warning(this,"错误","余额不足",QMessageBox::Ok);
            return;
        }
        if (flightinfo->getFirstTicket() < 0)
        {
            QMessageBox::warning(this,"错误","余票不足",QMessageBox::Ok);
            return;
        }
        flightinfo->setFirstPrice(use,flightinfo->getFirstTicket()-1);
    }
    else if (ui->radioButton_2->isChecked())
    {
        use = flightinfo->getSecondPrice();
        after = before - use;
        if (after < 0)
        {
            QMessageBox::warning(this,"错误","余额不足",QMessageBox::Ok);
            return;
        }
        if (flightinfo->getSecondTicket() < 0)
        {
            QMessageBox::warning(this,"错误","余票不足",QMessageBox::Ok);
            return;
        }
        flightinfo->setSecondPrice(use,flightinfo->getSecondTicket()-1);
    }
    else
    {
        QMessageBox::warning(this,"错误","请选择座位类型",QMessageBox::Ok);
        return;
    }
    passenger->setCreditCardMoney(after);
    passenger->bookInfo.push_back(*flightinfo);
    if (userManager.editUser(passenger->getName(),*passenger) && flightManager.editFlight(flightinfo->getNo(),flightinfo->getStartDate(),*flightinfo))
    {
        QMessageBox::information(this,"成功","订票成功",QMessageBox::Ok);
        this->close();
    }
    else
        QMessageBox::information(this,"失败","订票失败",QMessageBox::Ok);
}

void RetryDialog::on_radioButton_2_toggled(bool checked)
{
    if (checked)
    {
        QString money;
        int before = passenger->getCreditCardMoney();
        int use = flightinfo->getSecondPrice();
        int after = before - use;
        money.sprintf("%d - %d = %d",before,use,after);
        ui->Money->setText(money);
    }
}

void RetryDialog::on_radioButton_toggled(bool checked)
{
    if (checked)
    {
        QString money;
        int before = passenger->getCreditCardMoney();
        int use = flightinfo->getFirstPrice();
        int after = before - use;
        money.sprintf("%d - %d = %d",before,use,after);
        ui->Money->setText(money);
    }
}
