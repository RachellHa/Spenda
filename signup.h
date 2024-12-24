#ifndef SIGNUP_H
#define SIGNUP_H

#include <QMainWindow>

namespace Ui {
class signUp;
}

class signUp : public QMainWindow
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

private slots:

    void onContinueClicked();   //slot for the "Continue" button

private:
    Ui::signUp *ui;
};

#endif
