#ifndef RETRYDIALOG_H
#define RETRYDIALOG_H

#include <QDialog>

namespace Ui {
class RetryDialog;
}

class RetryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RetryDialog(QWidget *parent = 0);
    ~RetryDialog();

private:
    Ui::RetryDialog *ui;
};

#endif // RETRYDIALOG_H
