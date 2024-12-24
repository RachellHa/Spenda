#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoginClicked();   //slot for the "Login" button
    void onSignUpClicked();  //slot for the "Sign up" button

private:
    Ui::MainWindow *ui;
};

#endif //MAINWINDOW_H
