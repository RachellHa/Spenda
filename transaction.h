#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>

namespace Ui {
class transaction;
}

class transaction : public QMainWindow
{
    Q_OBJECT

public:
    explicit transaction(QWidget *parent = nullptr);
    ~transaction();

    static std::vector<QString> transactionList; //static list to hold transactions

private slots:
    void onBackClicked(); //slot for the "Back" button
    void onAddTransactionClicked(); //slot for the "Add Transaction" button

private:
    Ui::transaction *ui;
};

#endif
