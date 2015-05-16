#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include <QStandardItemModel>
#include "FlightInfo.h"
#include "FlightManager.h"
#include <QMessageBox>
#include "newflightdialog.h"

extern FlightManager flightManager;

ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    on_pushButton_clicked();
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}

void ManagerMainWindow::showInfo(string s)
{
    ui->Name->setText(QString::fromStdString(s)); // 接受信号的槽
}

void ManagerMainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"关于","民航订票系统 C++课程设计 161420220邓理",QMessageBox::Ok); // 关于信息
}

void ManagerMainWindow::on_actionExit_O_triggered()
{
    this->close(); // 关闭按钮
}

void ManagerMainWindow::on_actionNew_Flight_Info_triggered()
{
    NewFlightDialog *newflight = new NewFlightDialog(this); // 菜单栏中的构建新航班功能
    newflight->show();
}

void ManagerMainWindow::on_pushButton_4_clicked()   // 先查找当前选择的记录，再进行删除
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
    int fp = model->data(indexFP).toInt();
    int ft = model->data(indexFT).toInt();
    int sp = model->data(indexSP).toInt();
    int st = model->data(indexST).toInt();
    FlightInfo temp;
    temp.setNo(no);
    temp.setBaseInfo(startcity,endcity);
    temp.setDateTime(date,begintime,endtime);
    temp.setFirstPrice(fp,ft);
    temp.setSecondPrice(sp,st);
    if(flightManager.editFlight(no,date,temp))
        QMessageBox::information(this,"成功","修改成功",QMessageBox::Ok);
    else
        QMessageBox::warning(this,"失败","修改失败",QMessageBox::Ok);
    on_pushButton_clicked();
}

void ManagerMainWindow::on_pushButton_3_clicked()
{
    QAbstractItemModel *model = ui->tableView->model();
    int row = ui->tableView->currentIndex().row();
    QModelIndex indexNo = model->index(row,0);
    QModelIndex indexDate = model->index(row,3);
    string no = model->data(indexNo).toString().toStdString();
    string date = model->data(indexDate).toString().toStdString();
    if(flightManager.deleteFlight(no,date))
        QMessageBox::information(this,"成功","删除成功",QMessageBox::Ok);
    else
        QMessageBox::warning(this,"失败","删除失败",QMessageBox::Ok);
    on_pushButton_clicked();
}

void ManagerMainWindow::on_pushButton_clicked() // 刷新显示记录
{
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
        model->setItem(i,6,new QStandardItem(QString::number(it->getFirstPrice(),10)));
        model->setItem(i,7,new QStandardItem(QString::number(it->getFirstTicket(),10)));
        model->setItem(i,8,new QStandardItem(QString::number(it->getSecondPrice(),10)));
        model->setItem(i,9,new QStandardItem(QString::number(it->getSecondTicket(),10)));
        ++i;
    }
}
