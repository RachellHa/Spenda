#ifndef MBUDGET_H
#define MBUDGET_H

#include <QMainWindow>

namespace Ui {
class mBudget;
}

class mBudget : public QMainWindow
{
    Q_OBJECT

public:
    explicit mBudget(QWidget *parent = nullptr);
    ~mBudget();

private:
    Ui::mBudget *ui;
};

#endif // MBUDGET_H
