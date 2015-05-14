#include "selectdialog.h"
#include "ui_selectdialog.h"
#include <QStandardItemModel>

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
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
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    model->setItem(0,0,new QStandardItem("CA8888"));
    model->setItem(0,1,new QStandardItem("南京"));
    model->setItem(0,2,new QStandardItem("北京"));
    model->setItem(0,3,new QStandardItem("2015-07-05"));
    model->setItem(0,4,new QStandardItem("19:00"));
    model->setItem(0,5,new QStandardItem("20:00"));
    model->setItem(0,6,new QStandardItem(QObject::trUtf8("￥2000")));
    model->setItem(0,7,new QStandardItem("50"));
    model->setItem(0,8,new QStandardItem(QObject::trUtf8("￥1000")));
    model->setItem(0,9,new QStandardItem("200"));
}

SelectDialog::~SelectDialog()
{
    delete ui;
}
