#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "UserManager.h"
#include <QMessageBox>

extern UserManager userManager;

SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}

void SignUpDialog::on_pushButton_clicked()
{
    string name = ui->lineEdit->text().toStdString();
    string password = ui->lineEdit_2->text().toStdString();
    if(userManager.addUser(name,password))
        QMessageBox::warning(this,"Success","Succeed!",QMessageBox::Ok);
    else
        QMessageBox::warning(this,"Fail","Failed!",QMessageBox::Ok);
    close();
}
