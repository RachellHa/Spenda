#include "vBudget.h"
#include "ui_vBudget.h"
#include "menu.h"
#include "cBudget.h"
#include <QFont>

vBudget::vBudget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vBudget)
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set fonts
    QFont budgetFont("Cascadia Code");
    budgetFont.setPointSize(40);
    ui->label->setFont(budgetFont);

    QFont otherLabelFont("Cascadia Code");
    otherLabelFont.setPointSize(12);
    ui->label_2->setFont(otherLabelFont);
    ui->label_3->setFont(otherLabelFont);
    ui->label_4->setFont(otherLabelFont);
    ui->label_5->setFont(otherLabelFont);
    ui->label_6->setFont(otherLabelFont);

    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton_2->setFont(buttonFont);

    //line edits and push button have a white background
    ui->pushButton_2->setStyleSheet("background-color: white;");

    //populate label_6 with saved budgets
    QString allBudgets;
    for (const auto &budget : cBudget::budgetList) {
        allBudgets += budget + "\n";
    }
    ui->label_6->setText(allBudgets);

    //connect the back button to its slot
    connect(ui->pushButton_2, &QPushButton::clicked, this, &vBudget::on_backButton_clicked);
}

vBudget::~vBudget() {
    delete ui;
}

void vBudget::on_backButton_clicked() {
    //navigate back to the menu
    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}
