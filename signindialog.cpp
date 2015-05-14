#include "signindialog.h"
#include "ui_signindialog.h"
#include <QMessageBox>
#include "UserManager.h"

extern UserManager userManager;

SignInDialog::SignInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
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
            accept();
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
            accept();
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
