#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signindialog.h"
#include "passengermainwindow.h"
#include "signupdialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SignInDialog *signin = new SignInDialog(this); // 按”登录“按钮打开登录对话框
    signin->show();
}

void MainWindow::on_pushButton_2_clicked()
{
        SignUpDialog *signup = new SignUpDialog(this); // 按”注册“按钮打开注册对话框
        signup->show();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"关于","民航订票系统 C++课程设计 161420220邓理",QMessageBox::Ok); // 关于信息
}
