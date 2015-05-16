#include "passengermainwindow.h"
#include "ui_passengermainwindow.h"
#include <QString>
#include <QAction>
#include "selectdialog.h"
#include "UserManager.h"
#include "QMessageBox"
#include "rechargedialog.h"
#include "editinfodialog.h"
#include "bookedlistdialog.h"

extern UserManager userManager;

PassengerMainWindow::PassengerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassengerMainWindow)
{
    ui->setupUi(this);
    select = new SelectDialog(this);
    connect(this,SIGNAL(findFlightInfoByPlace(QString,QString,QString,Passenger)),select,SLOT(showFlightInfoByPlace(QString,QString,QString,Passenger)));
    connect(this,SIGNAL(findFlightInfoByNo(QString,QString,Passenger)),select,SLOT(showFlightInfoByNo(QString,QString,Passenger)));
    recharge = new RechargeDialog(this);
    connect(this,SIGNAL(passPassenger(Passenger)),recharge,SLOT(receivePassenger(Passenger)));
    edit = new EditInfoDialog(this);
    connect(this,SIGNAL(passPassenger(Passenger)),edit,SLOT(receivePassenge(Passenger)));
    bookedlist = new BookedListDialog(this);
    connect(this,SIGNAL(passPassenger(Passenger)),bookedlist,SLOT(receiverPassenger(Passenger)));
}

PassengerMainWindow::~PassengerMainWindow()
{
    delete ui;
}

void PassengerMainWindow::on_toolButton_clicked()
{
    QString temp;
    temp = ui->lineEdit->text();
    ui->lineEdit->setText(ui->lineEdit_2->text());
    ui->lineEdit_2->setText(temp);
}

void PassengerMainWindow::on_pushButton_2_clicked()
{
    QString no = ui->lineEdit_3->text();
    QString date = ui->dateEdit->text();
    if (no.isEmpty())
    {
        QMessageBox::warning(this,"错误","还未输入信息",QMessageBox::Ok);
        return;
    }
    emit findFlightInfoByNo(no,date,*passenger);
    select->show();
}

void PassengerMainWindow::showInfo(string s)
{
    passenger = new Passenger;
    ui->Name->setText(QString::fromStdString(s));
    userManager.findUserByName(s,*passenger);
    ui->Money->setText("Money: " + QString::number(passenger->getCreditCardMoney(),10));
}

void PassengerMainWindow::on_pushButton_clicked()
{
    QString begin = ui->lineEdit->text();
    QString end = ui->lineEdit_2->text();
    QString date = ui->dateEdit->text();
    if (begin.isEmpty() || end.isEmpty())
    {
        QMessageBox::warning(this,"错误","还未输入地点信息",QMessageBox::Ok);
        return;
    }
    emit findFlightInfoByPlace(begin,end,date,*passenger);
    select->show();
}

void PassengerMainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"关于","民航订票系统 C++课程设计 161420220邓理",QMessageBox::Ok);
}

void PassengerMainWindow::on_actionExit_triggered()
{
    this->close();
}

void PassengerMainWindow::on_actionRecharge_triggered()
{
    emit passPassenger(*passenger);
    recharge->show();
}

void PassengerMainWindow::on_actionEdit_Personal_Info_triggered()
{
    emit passPassenger(*passenger);
    edit->show();
}

void PassengerMainWindow::on_actionBooked_Flight_List_triggered()
{
    emit passPassenger(*passenger);
    bookedlist->show();
}

void PassengerMainWindow::on_refresh_clicked()
{
    showInfo(passenger->getName());
}
