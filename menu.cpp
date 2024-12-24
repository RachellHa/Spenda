#include "menu.h"
#include "ui_menu.h"
#include "cBudget.h"
#include "vBudget.h"
#include "transaction.h"
#include "report.h"
#include "goals.h"
#include "notifications.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu) {
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Main Menu" label to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label->setFont(titleFont);

    //set font for all buttons to size 14
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(14);

    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);
    ui->pushButton_3->setFont(buttonFont);
    ui->pushButton_4->setFont(buttonFont);
    ui->pushButton_5->setFont(buttonFont);
    ui->pushButton_6->setFont(buttonFont);

    //line edits and push button have a white background
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");
    ui->pushButton_3->setStyleSheet("background-color: white;");
    ui->pushButton_4->setStyleSheet("background-color: white;");
    ui->pushButton_5->setStyleSheet("background-color: white;");
    ui->pushButton_6->setStyleSheet("background-color: white;");

    //connect buttons to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &menu::onCreateBudgetClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &menu::onViewBudgetClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &menu::onViewTransactionHistoryClicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &menu::onGenerateReportClicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &menu::onSetGoalsClicked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &menu::onNotificationsClicked);
}

menu::~menu() {
    delete ui;
}

//slot implementations for each button
void menu::onCreateBudgetClicked() {
    cBudget *createBudgetWindow = new cBudget();
    createBudgetWindow->show();
    this->close();
}

void menu::onViewBudgetClicked() {
    vBudget *viewBudgetWindow = new vBudget();
    viewBudgetWindow->show();
    this->close();
}

void menu::onViewTransactionHistoryClicked() {
    transaction *transactionWindow = new transaction();
    transactionWindow->show();
    this->close();
}

void menu::onGenerateReportClicked() {
    report *reportWindow = new report();
    reportWindow->show();
    this->close();
}

void menu::onSetGoalsClicked() {
    goals *goalsWindow = new goals();
    goalsWindow->show();
    this->close();
}

void menu::onNotificationsClicked() {
    notifications *notificationsWindow = new notifications();
    notificationsWindow->show();
    this->close();
}
