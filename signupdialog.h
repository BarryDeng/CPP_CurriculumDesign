#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>

namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = 0);
    ~SignUpDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignUpDialog *ui;

};

#endif // SIGNUPDIALOG_H
