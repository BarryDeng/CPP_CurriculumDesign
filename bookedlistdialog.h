#ifndef BOOKEDLISTDIALOG_H
#define BOOKEDLISTDIALOG_H

#include <QDialog>
#include "Passenger.h"

namespace Ui {
class BookedListDialog;
}

class BookedListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookedListDialog(QWidget *parent = 0);
    ~BookedListDialog();

private slots:
    void on_pushButton_clicked();
    void receiverPassenger(Passenger);//传递Passage对象，方便Dialog调用

private:
    Ui::BookedListDialog *ui;
    Passenger *passenger;
};

#endif // BOOKEDLISTDIALOG_H
