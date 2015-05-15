#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signindialog.h"
#include "passengermainwindow.h"
#include "signupdialog.h"

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
    SignInDialog *signin = new SignInDialog(this);
    signin->show();
}

void MainWindow::on_pushButton_2_clicked()
{
        SignUpDialog *signup = new SignUpDialog(this);
        signup->show();
}
