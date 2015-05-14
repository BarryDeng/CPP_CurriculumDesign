#ifndef PASSENGERMAINWINDOW_H
#define PASSENGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class PassengerMainWindow;
}

class PassengerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PassengerMainWindow(QWidget *parent = 0);
    ~PassengerMainWindow();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::PassengerMainWindow *ui;
};

#endif // PASSENGERMAINWINDOW_H
