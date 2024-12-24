#include "transaction.h"
#include "ui_transaction.h"
#include "menu.h"
#include "atransaction.h"
#include <QFont>

std::vector<QString> transaction::transactionList; // Initialize the static list

transaction::transaction(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::transaction) {

    ui->setupUi(this);

    // Set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    // Set all font to Cascadia Code

    // Set font for "Back" and "Add Transaction" buttons to size 8
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);

    // Set font for the "Transaction History" label to size 40
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(40);
    ui->label->setFont(labelFont);

    // Set font for the "Merchant", "Category", and "Cost" labels to size 12
    QFont standardFont("Cascadia Code");
    standardFont.setPointSize(12);
    ui->label_2->setFont(standardFont);
    ui->label_3->setFont(standardFont);
    ui->label_4->setFont(standardFont);
    ui->label_5->setFont(standardFont);

    //line edits and push button have a white background
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");

    //connect "Back" button to return to the menu window
    connect(ui->pushButton, &QPushButton::clicked, this, &transaction::onBackClicked);

    //connect "Add Transaction" button to navigate to atransaction window
    connect(ui->pushButton_2, &QPushButton::clicked, this, &transaction::onAddTransactionClicked);

    //display all transactions in label_5
    QString allTransactions;
    for (const auto &trans : transactionList) {
        allTransactions += trans + "\n";
    }
    ui->label_5->setText(allTransactions);
}

transaction::~transaction() {
    delete ui;
}

//slot for the "Back" button
void transaction::onBackClicked() {
    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}

//slot for the "Add Transaction" button
void transaction::onAddTransactionClicked() {
    atransaction *transactionWindow = new atransaction();
    transactionWindow->show();
    this->close();
}
