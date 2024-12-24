#ifndef CBUDGET_H
#define CBUDGET_H

#include <QMainWindow>
#include "budgetCategory.h"

namespace Ui {
class cBudget;
}

class vBudget;
class menu;

class cBudget : public QMainWindow
{
    Q_OBJECT

public:
    void onSaveClicked();     //slot for handling "Save" button click
    static std::vector<QString> budgetList;  //declare as static

public:
    explicit cBudget(QWidget *parent = nullptr);
    ~cBudget();

private slots:
    void onBackClicked();  //slot for handling "Back" button click

private:
    Ui::cBudget *ui;
    vBudget *budgetView;
    BudgetCategory* budgetCategory;
};

#endif
