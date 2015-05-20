#ifndef NEWFLIGHTDIALOG_H
#define NEWFLIGHTDIALOG_H

#include <QDialog>

namespace Ui {
class NewFlightDialog;
}

class NewFlightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewFlightDialog(QWidget *parent = 0);
    ~NewFlightDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewFlightDialog *ui;
};

#endif // NEWFLIGHTDIALOG_H
