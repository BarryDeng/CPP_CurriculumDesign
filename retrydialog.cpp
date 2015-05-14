#include "retrydialog.h"
#include "ui_retrydialog.h"

RetryDialog::RetryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RetryDialog)
{
    ui->setupUi(this);
}

RetryDialog::~RetryDialog()
{
    delete ui;
}
