#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H

#include <QMainWindow>
#include <string>
using std::string;

namespace Ui {
class ManagerMainWindow;
}

class ManagerMainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void showInfo(string);

    void on_actionAbout_triggered();

    void on_actionExit_O_triggered();

    void on_actionNew_Flight_Info_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

public:
    explicit ManagerMainWindow(QWidget *parent = 0);
    ~ManagerMainWindow();

private:
    Ui::ManagerMainWindow *ui;
};

#endif // MANAGERMAINWINDOW_H
