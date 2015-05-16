#include "editinfodialog.h"
#include "ui_editinfodialog.h"
#include <QMessageBox>
#include "UserManager.h"

extern UserManager userManager;

EditInfoDialog::EditInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditInfoDialog)
{
    ui->setupUi(this);
}

EditInfoDialog::~EditInfoDialog()
{
    delete ui;
}

void EditInfoDialog::on_pushButton_clicked() // 保存身份修改的信息
{
    string password = ui->lineEdit_3->text().toStdString();
    string creditid = ui->lineEdit_2->text().toStdString();
    string creditpassword = ui->lineEdit->text().toStdString();
    passenger->editInfo(password,creditid,creditpassword);
    if(userManager.editUser(passenger->getName(),*passenger))
        QMessageBox::warning(this,"成功","操作成功",QMessageBox::Ok);
    else
        QMessageBox::warning(this,"失败","操作失败",QMessageBox::Ok);
    this->close();
}

void EditInfoDialog::receivePassenge(Passenger pgr) // 接受信号的槽
{
    passenger = new Passenger;
    userManager.findUserByName(pgr.getName(),*passenger);
}
