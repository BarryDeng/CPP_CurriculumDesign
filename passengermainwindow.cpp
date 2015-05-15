#include "passengermainwindow.h"
#include "ui_passengermainwindow.h"
#include <QString>
#include <QAction>
#include "selectdialog.h"
#include "UserManager.h"

extern UserManager userManager;

PassengerMainWindow::PassengerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassengerMainWindow)
{
    ui->setupUi(this);
    ui->actionAbout
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
    SelectDialog *select = new SelectDialog(this);
    select->show();
}

void PassengerMainWindow::showInfo(string s)
{
    ui->Name->setText(QString::fromStdString(s));
    passenger = new Passenger(userManager.findUserByName(s));
    ui->Money->setText("Money: " + QString::number(passenger->getCreditCardMoney() / 100,10));
}

void PassengerMainWindow::on_pushButton_clicked()
{

}
