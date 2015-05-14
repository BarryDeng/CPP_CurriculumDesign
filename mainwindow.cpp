#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signindialog.h"
#include "passengermainwindow.h"
#include "managermainwindow.h"

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
    if (signin->exec() == QDialog::Accepted)
    {
        PassengerMainWindow *passengerMainWindow = new PassengerMainWindow(this);
        passengerMainWindow->setWindowTitle("订票");
        passengerMainWindow->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ManagerMainWindow *managerMainWindow = new ManagerMainWindow(this);
    managerMainWindow->show();
}
