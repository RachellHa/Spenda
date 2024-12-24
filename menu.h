#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class menu;
}

class menu : public QMainWindow {
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void onCreateBudgetClicked();            //slot for the "cBudget" button
    void onViewBudgetClicked();              //slot for the "vBudget" button
    void onViewTransactionHistoryClicked();  //slot for the "transaction" button
    void onGenerateReportClicked();          //slot for the "report" button
    void onSetGoalsClicked();                //slot for the "goals" button
    void onNotificationsClicked();          //slot for the "notifications" button

private:
    Ui::menu *ui;
};

#endif
