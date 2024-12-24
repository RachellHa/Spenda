#include "agoals.h"
#include "ui_agoals.h"
#include "goals.h"
#include <QMessageBox>

agoals::agoals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::agoals)
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all font to Cascadia Code
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(40);
    ui->label->setFont(labelFont);

    //set font for "Name", "Target amount", and "Deadline" labels
    QFont otherLabelFont("Cascadia Code");
    otherLabelFont.setPointSize(12);
    ui->label_2->setFont(otherLabelFont);
    ui->label_3->setFont(otherLabelFont);
    ui->label_4->setFont(otherLabelFont);

    //set font for "Back" and "Save" buttons
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

    //connect buttons to slots
    connect(ui->pushButton, &QPushButton::clicked, this, &agoals::on_backButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &agoals::on_saveButton_clicked);
}

agoals::~agoals()
{
    delete ui;
}

void agoals::on_backButton_clicked()
{
    //navigate back to goals
    goals *goalsWindow = new goals();
    goalsWindow->show();
    this->close();
}

void agoals::on_saveButton_clicked()
{
    //check if required fields are empty
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    //get the goal data
    QString name = ui->lineEdit->text();
    QString targetAmount = ui->lineEdit_2->text();
    QString deadline = ui->lineEdit_3->text();

    //pass the goal data to the goals window
    goals *goalsWindow = new goals();
    goalsWindow->addGoalToLabel(name, targetAmount, deadline);
    goalsWindow->show();
    this->close();
}
