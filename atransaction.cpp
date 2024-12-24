#include "atransaction.h"
#include "ui_atransaction.h"
#include "transaction.h"
#include <QMessageBox>
#include "transactionfactory.h"

atransaction::atransaction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::atransaction)
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "add transaction" label to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label_4->setFont(titleFont);

    //set font for the other labels to size 12
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(12);
    ui->label->setFont(labelFont);
    ui->label_2->setFont(labelFont);
    ui->label_3->setFont(labelFont);
    ui->label_5->setFont(labelFont);

    //set font for the checkboxes and buttons to size 8
    ui->checkBox->setFont(labelFont);
    ui->checkBox_2->setFont(labelFont);
    ui->checkBox_3->setFont(labelFont);
    QFont buttonFont("Cascadia Code", 8);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);

    //line edits and push button have a white background
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit_3->setStyleSheet("background-color: white;");
    ui->lineEdit_4->setStyleSheet("background-color: white;");
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");

    //connect the buttons and checkboxes to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &atransaction::onBackClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &atransaction::onSaveClicked);
    connect(ui->checkBox_2, &QCheckBox::checkStateChanged, this, &atransaction::onDepositChecked);
    connect(ui->checkBox_3, &QCheckBox::checkStateChanged, this, &atransaction::onPurchasesChecked);
}

atransaction::~atransaction()
{
    delete ui;
}

void atransaction::onDepositChecked(int state)
{
    if (state == Qt::Checked) {
        ui->checkBox_3->setChecked(false); //uncheck Purchases
    }
}

void atransaction::onPurchasesChecked(int state)
{
    if (state == Qt::Checked) {
        ui->checkBox_2->setChecked(false); //uncheck Deposit
    }
}

void atransaction::onBackClicked()
{
    transaction *transactionWindow = new transaction();
    transactionWindow->show();
    this->close();
}

void atransaction::onSaveClicked()
{
    //validate input fields based on the selection
    if (ui->checkBox_2->isChecked()) {

        //check if "Add to Goal" is selected and validate the goal category
        if (ui->checkBox->isChecked() && ui->lineEdit_4->text().isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please fill in the goal category for Add to Goal.");
            return;
        }

        //ensure the amount fields only contain numeric values
        bool amountValid = false;
        double amount = ui->lineEdit_2->text().toDouble(&amountValid);
        if (!amountValid || amount <= 0) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid amount for the deposit.");
            return;
        }

        //use the factory to create a Deposit transaction
        Transaction* transaction = TransactionFactory::createTransaction("income");
        if (transaction) {
            //add the transaction to the list in transaction.cpp
            QString transactionDetails = QString("Deposit:   %1                        %3                         %2")
                                             .arg(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text());
            transaction::transactionList.push_back(transactionDetails);

            transaction->process();
            delete transaction;
        }
    } else if (ui->checkBox_3->isChecked()) {
        //check if purchase fields are valid
        if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please fill in all required fields for purchases.");
            return;
        }

        //ensure the amount fields only contain numeric values
        bool amountValid = false;
        double amount = ui->lineEdit_2->text().toDouble(&amountValid);
        if (!amountValid || amount <= 0) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid amount for the purchase.");
            return;
        }

        //check if "Add to Goal" is selected and validate the goal category for purchases
        if (ui->checkBox->isChecked() && ui->lineEdit_4->text().isEmpty()) {
            QMessageBox::warning(this, "Input Error", "Please fill in the goal category for Add to Goal.");
            return;
        }

        //use the factory to create a Purchase transaction
        Transaction* transaction = TransactionFactory::createTransaction("expense");
        if (transaction) {
            //add the transaction to the list in transaction.cpp
            QString transactionDetails = QString("Purchase:  %1                          %3                         %2")
                                             .arg(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text());
            transaction::transactionList.push_back(transactionDetails);

            transaction->process();
            delete transaction;
        }
    } else {
        QMessageBox::warning(this, "Input Error", "Please select either Deposit or Purchases.");
        return;
    }

    //navigate back to the transaction window
    transaction* transactionWindow = new transaction();
    transactionWindow->show();
    this->close();
}
