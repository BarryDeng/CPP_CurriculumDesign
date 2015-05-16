#ifndef RECHARGEDIALOG_H
#define RECHARGEDIALOG_H

#include <QDialog>
#include "Passenger.h"
namespace Ui {
class RechargeDialog;
}

class RechargeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RechargeDialog(QWidget *parent = 0);
    ~RechargeDialog();

private slots:
    void on_pushButton_clicked();
    void receivePassenger(Passenger);

private:
    Ui::RechargeDialog *ui;
    Passenger *passenger;
};

#endif // RECHARGEDIALOG_H
