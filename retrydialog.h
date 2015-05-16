#ifndef RETRYDIALOG_H
#define RETRYDIALOG_H

#include <QDialog>
#include <string>
#include "Passenger.h"
using std::string;

namespace Ui {
class RetryDialog;
}

class RetryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RetryDialog(QWidget *parent = 0);
    ~RetryDialog();

private slots:
    void retry(FlightInfo,Passenger);

    void on_buttonBox_accepted();

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

private:
    Ui::RetryDialog *ui;
    Passenger *passenger;
    FlightInfo *flightinfo;
};

#endif // RETRYDIALOG_H
