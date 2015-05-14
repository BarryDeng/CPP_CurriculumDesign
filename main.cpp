#include "UserManager.h"
#include <QApplication>
#include "mainwindow.h"
#include "FlightManager.h"

UserManager userManager;
FlightManager flightManager;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwindow;
    //userManager.addUser("123","123");
    //userManager.addUser("321","123");
    FlightInfo t("AA0000","2015-07-05");
    flightManager.addFlight(t);
    mainwindow.show();
    return a.exec();
}
