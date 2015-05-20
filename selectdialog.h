#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H
#include <QString>
#include <QDialog>
#include <string>
#include "Passenger.h"

using std::string;

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = 0);
    ~SelectDialog();

signals:
    void chooseFlight(FlightInfo,Passenger);

private slots:
    void showFlightInfoByPlace(QString,QString,QString,Passenger);
    void showFlightInfoByNo(QString,QString,Passenger);

    void on_pushButton_clicked();

private:
    Ui::SelectDialog *ui;
    Passenger *passenger;
};

#endif // SELECTDIALOG_H
