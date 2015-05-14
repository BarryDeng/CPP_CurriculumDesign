#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include <QStandardItemModel>
#include "FlightInfo.h"
#include "FlightManager.h"

extern FlightManager flightManager;
ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
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
    vector<FlightInfo>::iterator it;
    int i = 0;
    for (it = flightManager.flightlist.begin(); it != flightManager.flightlist.end(); ++it)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(it->getNo())));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(it->getStartCity())));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(it->getEndCity())));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(it->getStartDate())));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(it->getStartTime())));
        model->setItem(i,5,new QStandardItem(QString::fromStdString(it->getEndTime())));
        model->setItem(i,6,new QStandardItem(QString::number(it->getFirstTicket(),10)));
        model->setItem(i,7,new QStandardItem(QString::number(it->getFirstPrice(),10)));
        model->setItem(i,8,new QStandardItem(QString::number(it->getSecondTicket(),10)));
        model->setItem(i,9,new QStandardItem(QString::number(it->getSecondPrice(),10)));
        ++i;
    }
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}
