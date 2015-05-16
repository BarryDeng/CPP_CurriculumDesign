#ifndef EDITINFODIALOG_H
#define EDITINFODIALOG_H

#include <QDialog>
#include "Passenger.h"
namespace Ui {
class EditInfoDialog;
}

class EditInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditInfoDialog(QWidget *parent = 0);
    ~EditInfoDialog();

private slots:
    void on_pushButton_clicked();
    void receivePassenge(Passenger);//传递Passage对象，方便Dialog调用

private:
    Ui::EditInfoDialog *ui;
    Passenger *passenger;
};

#endif // EDITINFODIALOG_H
