#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <string>
#include "managermainwindow.h"
#include "passengermainwindow.h"

using std::string;
namespace Ui {
class SignInDialog;
}

class SignInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignInDialog(QWidget *parent = 0);
    ~SignInDialog();

signals:
    void signin(string);

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignInDialog *ui;
    PassengerMainWindow *passengerwindow;
    ManagerMainWindow *managerwindow;
};

#endif // SIGNINDIALOG_H
