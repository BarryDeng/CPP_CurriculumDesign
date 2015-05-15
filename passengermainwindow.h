#ifndef PASSENGERMAINWINDOW_H
#define PASSENGERMAINWINDOW_H
#include <string>
#include <QMainWindow>
#include <QAction>
#include "Passenger.h"
using std::string;

namespace Ui {
class PassengerMainWindow;
}

class PassengerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassengerMainWindow(QWidget *parent = 0);
    ~PassengerMainWindow();

private slots:
    void showInfo(string);

    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::PassengerMainWindow *ui;
    Passenger *passenger;
};

#endif // PASSENGERMAINWINDOW_H
