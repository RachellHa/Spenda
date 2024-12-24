#include "goals.h"
#include "ui_goals.h"
#include "menu.h"
#include "agoals.h"
#include <QMessageBox>

//static list to store created gosls
std::vector<QString> goals::goalList;

goals::goals(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::goals)
{
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Goals" title label to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label->setFont(titleFont);

    //set font for other labels to size 12
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(12);
    ui->label_2->setFont(labelFont);
    ui->label_3->setFont(labelFont);
    ui->label_4->setFont(labelFont);
    ui->label_5->setFont(labelFont);
    ui->label_6->setFont(labelFont);

    //set font for buttons to size 8
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);

    //line edits and push button have a white background
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");

    //connect buttons to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &goals::onBackClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &goals::onAddGoalsClicked);
}

goals::~goals()
{
    delete ui;
}

void goals::onBackClicked()
{
    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}

void goals::onAddGoalsClicked()
{
    agoals *addGoalsWindow = new agoals();
    addGoalsWindow->show();
    this->close();
}


//method to add goal to label_5
void goals::addGoalToLabel(const QString &name, const QString &targetAmount, const QString &deadline)
{
    //convert targetAmount to double and check if it's valid
    bool ok;
    double target = targetAmount.toDouble(&ok);

    //if the conversion fails, show an error message
    if (!ok || target <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a positive number for the target amount.");
        return;
    }

    //create the goal entry string
    QString goalEntry = QString("%1               %2                       Not reached             %3")
                            .arg(name, targetAmount, deadline);

    // Add to static goalList
    goalList.push_back(goalEntry);

    //update label_5 with all goals from the goalList
    QString allGoals;
    for (const auto &goal : goalList) {
        allGoals += goal + "\n";
    }
    ui->label_5->setText(allGoals);
}
