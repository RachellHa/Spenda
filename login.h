#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow {
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void onContinueClicked();  //slot for the "Continue" button

private:
    Ui::login *ui;
};

#endif //LOGIN_H
