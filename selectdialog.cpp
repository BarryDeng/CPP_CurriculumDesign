#include "selectdialog.h"
#include "ui_selectdialog.h"
#include <QStandardItemModel>
#include <QString>
#include "FlightManager.h"
#include "retrydialog.h"

extern FlightManager flightManager;

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);
}

SelectDialog::~SelectDialog()
{
    delete ui;
}

void SelectDialog::showFlightInfoByPlace(QString begin, QString end, QString date,Passenger pgr)
{
    passenger = new Passenger(pgr);
    vector<FlightInfo> temp;
    flightManager.findFlightByPlace(begin.toStdString(),end.toStdString(),date.toStdString(),temp);
    vector<FlightInfo>::iterator it;
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("No")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Depart")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Arrival")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Date")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("TakeOff")));
    model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Land")));
    model->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("First Class")));
    model->setHorizontalHeaderItem(7,new QStandardItem(QObject::tr("Reserved")));
    model->setHorizontalHeaderItem(8,new QStandardItem(QObject::tr("Second Class")));
    model->setHorizontalHeaderItem(9,new QStandardItem(QObject::tr("Reserved")));
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    int i = 0;
    for (it = temp.begin(); it != temp.end(); it++)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(it->getNo())));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(it->getStartCity())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(it->getEndCity())));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(it->getStartDate())));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(it->getStartTime())));
        model->setItem(i,5,new QStandardItem(QString::fromStdString(it->getEndTime())));
        model->setItem(i,6,new QStandardItem(QString::number(it->getFirstPrice())));
        model->setItem(i,7,new QStandardItem(QString::number(it->getFirstTicket())));
        model->setItem(i,8,new QStandardItem(QString::number(it->getSecondPrice())));
        model->setItem(i,9,new QStandardItem(QString::number(it->getSecondTicket())));
        i++;
    }
    ui->tableView->setModel(model);
}

void SelectDialog::showFlightInfoByNo(QString no,QString date,Passenger pgr)
{
    vector<FlightInfo> temp;
    flightManager.findFlightByNo(no.toStdString(),date.toStdString(),temp);
    vector<FlightInfo>::iterator it;
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("No")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Depart")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Arrival")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("Date")));
    model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("TakeOff")));
    model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("Land")));
    model->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("First Class")));
    model->setHorizontalHeaderItem(7,new QStandardItem(QObject::tr("Reserved")));
    model->setHorizontalHeaderItem(8,new QStandardItem(QObject::tr("Second Class")));
    model->setHorizontalHeaderItem(9,new QStandardItem(QObject::tr("Reserved")));
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    int i = 0;
    for (it = temp.begin(); it != temp.end(); it++)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(it->getNo())));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(it->getStartCity())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(it->getEndCity())));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(it->getStartDate())));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(it->getStartTime())));
        model->setItem(i,5,new QStandardItem(QString::fromStdString(it->getEndTime())));
        model->setItem(i,6,new QStandardItem(QString::number(it->getFirstPrice())));
        model->setItem(i,7,new QStandardItem(QString::number(it->getFirstTicket())));
        model->setItem(i,8,new QStandardItem(QString::number(it->getSecondPrice())));
        model->setItem(i,9,new QStandardItem(QString::number(it->getSecondTicket())));
        i++;
    }
    ui->tableView->setModel(model);
    passenger = new Passenger(pgr);
}

void SelectDialog::on_pushButton_clicked()
{
    QAbstractItemModel *model = ui->tableView->model();
    int row = ui->tableView->currentIndex().row();
    QModelIndex indexNo = model->index(row,0);
    QModelIndex indexStartCity = model->index(row,1);
    QModelIndex indexEndCity = model->index(row,2);
    QModelIndex indexDate = model->index(row,3);
    QModelIndex indexBegin = model->index(row,4);
    QModelIndex indexEnd = model->index(row,5);
    QModelIndex indexFP = model->index(row,6);
    QModelIndex indexFT = model->index(row,7);
    QModelIndex indexSP = model->index(row,8);
    QModelIndex indexST = model->index(row,9);
    string no = model->data(indexNo).toString().toStdString();
    string startcity = model->data(indexStartCity).toString().toStdString();
    string endcity = model->data(indexEndCity).toString().toStdString();
    string date = model->data(indexDate).toString().toStdString();
    string begintime = model->data(indexBegin).toString().toStdString();
    string endtime = model->data(indexEnd).toString().toStdString();
    int ft = model->data(indexFT).toInt();
    int fp = model->data(indexFP).toInt();
    int st = model->data(indexST).toInt();
    int sp = model->data(indexSP).toInt();
    FlightInfo temp;
    temp.setNo(no);
    temp.setBaseInfo(startcity,endcity);
    temp.setDateTime(date,begintime,endtime);
    temp.setFirstPrice(fp,ft);
    temp.setSecondPrice(sp,st);
    RetryDialog *retry = new RetryDialog(this);
    connect(this,SIGNAL(chooseFlight(FlightInfo,Passenger)),retry,SLOT(retry(FlightInfo,Passenger)));
    emit chooseFlight(temp,*passenger);
    retry->show();
}
