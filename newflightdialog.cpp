#include "newflightdialog.h"
#include "ui_newflightdialog.h"
#include "FlightInfo.h"
#include "FlightManager.h"
#include <QMessageBox>
extern FlightManager flightManager;

NewFlightDialog::NewFlightDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewFlightDialog)
{
    ui->setupUi(this);
    for (int i = 0; i < 500; i++)
    {
        ui->firstticket->addItem(QString::number(i));
        ui->secondticket->addItem(QString::number(i));
    }
}

NewFlightDialog::~NewFlightDialog()
{
    delete ui;
}

void NewFlightDialog::on_pushButton_clicked() // 创建新航班
{
    string no = ui->no->text().toStdString();
    string startcity = ui->startcity->text().toStdString();
    string endcity = ui->endcity->text().toStdString();
    string startdate = ui->startdate->text().toStdString();
    string begintime = ui->begintime->text().toStdString();
    string endtime = ui->endtime->text().toStdString();
    int firstprice = ui->firstprice->text().toInt();
    int firstticket = ui->firstticket->currentText().toInt();
    int secondprice = ui->secondprice->text().toInt();
    int secondticket = ui->secondticket->currentText().toInt();
    FlightInfo temp(no,startdate);
    temp.setBaseInfo(startcity,endcity);
    temp.setDateTime(startdate,begintime,endtime);
    temp.setFirstPrice(firstprice,firstticket);
    temp.setSecondPrice(secondprice,secondticket);
    if (no.empty() || startdate.empty() || startcity.empty() || endcity.empty())
        QMessageBox::warning(this,"错误","航班必要信息不全",QMessageBox::Ok);
    if(flightManager.addFlight(temp))
    {
        QMessageBox::information(this,"成功","成功添加",QMessageBox::Ok);
        this->close();
    }
    else
        QMessageBox::information(this,"失败","存在相同航班信息",QMessageBox::Ok);
}
