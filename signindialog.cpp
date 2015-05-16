#include "signindialog.h"
#include "ui_signindialog.h"
#include <QMessageBox>
#include "UserManager.h"
#include "passengermainwindow.h"
#include "managermainwindow.h"

extern UserManager userManager;

SignInDialog::SignInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
    passengerwindow = new PassengerMainWindow(this);
    managerwindow = new ManagerMainWindow(this);
    connect(this,SIGNAL(signin(string)),passengerwindow,SLOT(showInfo(string)));
    connect(this,SIGNAL(signin(string)),managerwindow,SLOT(showInfo(string)));
}

SignInDialog::~SignInDialog()
{
    delete ui;
}

void SignInDialog::on_pushButton_clicked()
{
    if (ui->radioButton->isChecked())
    {
        if (userManager.validate(ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString()))
        {
            QMessageBox::warning(this,"OK","Login completely",QMessageBox::Yes);
            emit signin(ui->lineEdit->text().toStdString());
            this->accept();
            passengerwindow->show();
        }
        else
        {
            QMessageBox::warning(this,"Fail","Login failed",QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
        }
    }
    else if (ui->radioButton_2->isChecked())
    {
        if (ui->lineEdit->text() == "admin" && ui->lineEdit_2->text() == "admin")
        {
            QMessageBox::warning(this,"OK","Login completely",QMessageBox::Yes);
            emit signin(ui->lineEdit->text().toStdString());
            this->accept();
            managerwindow->show();
        }
        else
        {
            QMessageBox::warning(this,"Fail","Login failed",QMessageBox::Yes);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit->setFocus();
        }
    }
    else
    {
        QMessageBox::warning(this,"Fail","未选择用户类型",QMessageBox::Yes);
    }
}
