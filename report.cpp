#include "report.h"
#include "ui_report.h"
#include <QMessageBox>
#include "menu.h"
#include "transaction.h"

report::report(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::report),
    generatedReport("")
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Report" label to size 40
    QFont reportFont("Cascadia Code");
    reportFont.setPointSize(40);
    ui->label->setFont(reportFont);

    //set font for the labels and buttons
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(12);
    ui->label_2->setFont(labelFont);
    ui->label_3->setFont(labelFont);

    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton->setFont(buttonFont);  //back button
    ui->pushButton_2->setFont(buttonFont); //generate Report button
    ui->pushButton_3->setFont(buttonFont); //view Report button

    //line edits and push button have a white background
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");
    ui->pushButton_3->setStyleSheet("background-color: white;");

    //connect buttons to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &report::onBackClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &report::onGenerateReportClicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &report::onViewReportClicked);
}

report::~report()
{
    delete ui;
}

void report::onBackClicked()
{
    menu *mainMenu = new menu();
    mainMenu->show();
    this->close();
}

void report::onGenerateReportClicked()
{
    //generate a report from transactionList
    generatedReport.clear();
    generatedReport += "Transaction Report:\n";
    generatedReport += "---------------------------------------------\n";

    for (const auto &transaction : transaction::transactionList) {
        generatedReport += transaction + "\n";
    }

    generatedReport += "---------------------------------------------\n";

    //notify the user that the report has been generated
    QMessageBox::information(this, "Report Generated", "The transaction report has been successfully generated!");
}

void report::onViewReportClicked()
{
    if (generatedReport.isEmpty()) {
        QMessageBox::warning(this, "No Report", "No report has been generated yet. Please generate a report first.");
        return;
    }

    //display the generated report in a message box
    QMessageBox::information(this, "View Report", generatedReport);
}
