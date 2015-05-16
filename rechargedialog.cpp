#include "rechargedialog.h"
#include "ui_rechargedialog.h"
#include <QMessageBox>
#include <UserManager.h>

extern UserManager userManager;

RechargeDialog::RechargeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RechargeDialog)
{
    ui->setupUi(this);
}

RechargeDialog::~RechargeDialog()
{
    delete ui;
}

void RechargeDialog::on_pushButton_clicked()
{
    if (passenger->validateCreditCard(ui->lineEdit_3->text().toStdString(),ui->lineEdit_2->text().toStdString()) && passenger->recharge(ui->lineEdit->text().toInt()) && userManager.editUser(passenger->getName(),*passenger))
        QMessageBox::information(this,"成功","成功操作",QMessageBox::Ok);
    else
        QMessageBox::warning(this,"失败","操作失败",QMessageBox::Ok);
    this->accept();
}

void RechargeDialog::receivePassenger(Passenger pgr)
{
    passenger = new Passenger;
    userManager.findUserByName(pgr.getName(),*passenger);
}
