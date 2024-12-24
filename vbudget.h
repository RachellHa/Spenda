#ifndef VBUDGET_H
#define VBUDGET_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "observer.h"

namespace Ui {
class vBudget;
}

class vBudget : public QMainWindow
{
    Q_OBJECT

public:
    explicit vBudget(QWidget *parent = nullptr);
    ~vBudget();

    void update(const std::string& message) ;

private slots:

    void on_backButton_clicked();      //slot for the "back" button

private:
    Ui::vBudget *ui;
};

#endif
