#include "UserManager.h"
#include <QApplication>
#include "mainwindow.h"
#include "FlightManager.h"

UserManager userManager;
FlightManager flightManager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwindow; // 主窗口类执行
    mainwindow.show();
    return a.exec();
}
