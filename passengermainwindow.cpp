#include "passengermainwindow.h"
#include "ui_passengermainwindow.h"
#include <QString>
#include "selectdialog.h"

PassengerMainWindow::PassengerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PassengerMainWindow)
{
    ui->setupUi(this);
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

void PassengerMainWindow::on_pushButton_clicked()
{

}
