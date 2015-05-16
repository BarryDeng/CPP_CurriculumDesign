#ifndef PASSENGERMAINWINDOW_H
#define PASSENGERMAINWINDOW_H
#include <QMainWindow>
#include <QAction>
#include "Passenger.h"
#include "selectdialog.h"
#include "rechargedialog.h"
#include "editinfodialog.h"
#include "bookedlistdialog.h"

namespace Ui {
class PassengerMainWindow;
}

class PassengerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassengerMainWindow(QWidget *parent = 0);
    ~PassengerMainWindow();

signals:
    void findFlightInfoByPlace(QString,QString,QString,Passenger);
    void findFlightInfoByNo(QString,QString,Passenger);
    void passPassenger(Passenger);

private slots:
    void showInfo(string);

    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_actionRecharge_triggered();

    void on_actionEdit_Personal_Info_triggered();

    void on_actionBooked_Flight_List_triggered();

    void on_refresh_clicked();

private:
    Ui::PassengerMainWindow *ui;
    SelectDialog *select;
    Passenger *passenger;
    RechargeDialog *recharge;
    EditInfoDialog *edit;
    BookedListDialog *bookedlist;
};

#endif // PASSENGERMAINWINDOW_H
