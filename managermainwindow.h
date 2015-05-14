#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManagerMainWindow;
}

class ManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerMainWindow(QWidget *parent = 0);
    ~ManagerMainWindow();

private:
    Ui::ManagerMainWindow *ui;
};

#endif // MANAGERMAINWINDOW_H
