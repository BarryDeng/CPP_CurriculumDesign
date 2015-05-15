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

public:
    explicit ManagerMainWindow(QWidget *parent = 0);
    ~ManagerMainWindow();

private:
    Ui::ManagerMainWindow *ui;
};

#endif // MANAGERMAINWINDOW_H
