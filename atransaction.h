#ifndef ATRANSACTION_H
#define ATRANSACTION_H

#include <QMainWindow>

namespace Ui {
class atransaction;
}

class transaction;

class atransaction : public QMainWindow
{
    Q_OBJECT

public:
    explicit atransaction(QWidget *parent = nullptr);
    ~atransaction();

private slots:
    void onBackClicked();       //slot for the "Back" button
    void onSaveClicked();       //slot for the "Save" button
    void onDepositChecked(int state);  //slot for "Deposit" checkbox
    void onPurchasesChecked(int state); //slot for "Purchases" checkbox

private:
    Ui::atransaction *ui;
};

#endif //ATRANSACTION_H
