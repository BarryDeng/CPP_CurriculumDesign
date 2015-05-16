#include "bookedlistdialog.h"
#include "ui_bookedlistdialog.h"
#include "Passenger.h"
#include "FlightInfo.h"
#include "FlightManager.h"
#include "UserManager.h"
#include <QStandardItemModel>
#include <QMessageBox>

extern FlightManager flightManager;
extern UserManager userManager;

BookedListDialog::BookedListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookedListDialog)
{
    ui->setupUi(this);
}

BookedListDialog::~BookedListDialog()
{
    delete ui;
}

void BookedListDialog::on_pushButton_clicked() // 根据购买记录信息来列出信息，并根据位置删除指定数据
{
    QAbstractItemModel *model = ui->tableView->model();
    int row = ui->tableView->currentIndex().row();
    QModelIndex indexNo = model->index(row,0);
    QModelIndex indexDate = model->index(row,1);
    string no = model->data(indexNo).toString().toStdString();
    string date = model->data(indexDate).toString().toStdString();
    vector<FlightInfo>::iterator it;
    for (it = passenger->bookInfo.begin(); it != passenger->bookInfo.end(); ++it)
        if (it->getNo() == no && it->getStartDate() == date)
        {
            passenger->bookInfo.erase(it);
            QMessageBox::information(this,"成功","操作成功",QMessageBox::Ok);
            receiverPassenger(*passenger);
            return;
        }
    QMessageBox::warning(this,"失败","操作失败",QMessageBox::Ok);
}

void BookedListDialog::receiverPassenger(Passenger pgr) // 接受信号的槽，获得passenger对象
{
    passenger = new Passenger;
    userManager.findUserByName(pgr.getName(),*passenger);
    vector<FlightInfo>::iterator it;
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("No")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Date")));
    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QTableView::NoEditTriggers);
    qDebug(QString::number(passenger->bookInfo.size()).toStdString().c_str());
    int i = 0;
    for (it = passenger->bookInfo.begin(); it != passenger->bookInfo.end(); it++)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(it->getNo())));
        model->setItem(i,1,new QStandardItem(QString::fromStdString(it->getStartDate())));
        i++;
    }
    ui->tableView->setModel(model);
}
