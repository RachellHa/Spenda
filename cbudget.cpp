#include "cBudget.h"
#include "ui_cBudget.h"
#include "vBudget.h"
#include "menu.h"
#include <QMessageBox>
#include "budgetCategory.h"
#include "observer.h"
#include "user.h"

//static list to store created budgets
std::vector<QString> cBudget::budgetList;

cBudget::cBudget(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::cBudget), budgetView(new vBudget(this))
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set font for the title to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label_4->setFont(titleFont);

    //set font for the labels to size 12
    QFont standardFont("Cascadia Code");
    standardFont.setPointSize(12);
    ui->label->setFont(standardFont);
    ui->label_2->setFont(standardFont);
    ui->label_3->setFont(standardFont);

    //set font for the buttons to size 8
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);

    //line edits and push button have a white background
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit_3->setStyleSheet("background-color: white;");
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");

    budgetCategory = new BudgetCategory();

    //create and add a User observer
    User* user = new User();
    budgetCategory->addObserver(user);

    //connect the buttons
    connect(ui->pushButton, &QPushButton::clicked, this, &cBudget::onBackClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &cBudget::onSaveClicked);
}

cBudget::~cBudget() {
    delete ui;
    delete budgetCategory;
}

//slot for handling the "Back" button click
void cBudget::onBackClicked() {
    menu *mainMenu = new menu();
    mainMenu->show();
    this->close();
}

void cBudget::onSaveClicked() {
    QString category = ui->lineEdit->text();
    QString limit = ui->lineEdit_2->text();
    QString reminder = ui->lineEdit_3->text();

    //check if the required fields are filled out
    if (category.isEmpty() || limit.isEmpty() || reminder.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in the required fields");
        return;
    }

    //validate that limit is a number
    bool ok;
    double limitValue = limit.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a numeric value for the limit");
        return;
    }

    //validate that reminder is a number
    double reminderValue = reminder.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Input Error", "Please enter a numeric value for the reminder");
        return;
    }

    //check that the reminder is not greater than the limit
    if (reminderValue > limitValue) {
        QMessageBox::warning(this, "Input Error", "Reminder cannot be greater than the limit");
        return;
    }

    //format the budget data and save it
    QString budgetEntry = QString(" %1          Not reached limit          %2              %3")
                              .arg(category, limit, reminder);

    //save to the static list
    cBudget::budgetList.push_back(budgetEntry);

    //notify observers about the new budget
    std::string message = "New budget created for category: " + category.toStdString();
    budgetCategory->notifyObservers(message);

    //navigate back to the menu
    menu *mainMenu = new menu();
    mainMenu->show();
    this->close();
}
