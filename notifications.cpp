#include "notifications.h"
#include "ui_notifications.h"
#include "menu.h"
#include <QMessageBox>
#include <QSettings>
#include "notificationManager.h"

notifications::notifications(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notifications)
{
    ui->setupUi(this);

    // Set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Notifications" label to size 40
    QFont labelFont("Cascadia Code");
    labelFont.setPointSize(40);
    ui->label->setFont(labelFont);

    //set font for the "budget limit" and "achieving goal" labels to size 12
    QFont otherLabelFont("Cascadia Code");
    otherLabelFont.setPointSize(12);
    ui->label_2->setFont(otherLabelFont);
    ui->label_3->setFont(otherLabelFont);

    //set font for the "back", "save", and "clear" label to size 40
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(8);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);
    ui->pushButton_3->setFont(buttonFont);

    //line edits and push button have a white background
    ui->pushButton->setStyleSheet("background-color: white;");
    ui->pushButton_2->setStyleSheet("background-color: white;");
    ui->pushButton_3->setStyleSheet("background-color: white;");


    //connect buttons to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &notifications::on_backButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &notifications::on_saveButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &notifications::on_clearButton_clicked);

    //connect checkboxes to toggle handling function
    connect(ui->checkBox, &QCheckBox::toggled, this, &notifications::on_checkBox_toggled);
    connect(ui->checkBox_2, &QCheckBox::toggled, this, &notifications::on_checkBox_toggled);
    connect(ui->checkBox_3, &QCheckBox::toggled, this, &notifications::on_checkBox_toggled);
    connect(ui->checkBox_4, &QCheckBox::toggled, this, &notifications::on_checkBox_toggled);

    //load saved checkbox states
    loadCheckboxStates();
}

notifications::~notifications()
{
    delete ui;
}

void notifications::on_backButton_clicked()
{
    //navigate back to the menu
    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}

void notifications::on_saveButton_clicked() {
    //save checkbox states when the "Save" button is clicked
    saveCheckboxStates();

    //send a notification about the action
    NotificationManager::getInstance()->sendNotification("Settings saved successfully.");

    //navigate back to the menu
    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}


void notifications::on_clearButton_clicked() {
    //clear all checkboxes
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);

    //send a notification when clearing checkboxes
    NotificationManager::getInstance()->sendNotification("All checkboxes have been cleared.");
}

void notifications::on_checkBox_toggled(bool checked)
{
    //mutual exclusivity of the checkboxes in each set
    if (checked) {
        if (sender() == ui->checkBox || sender() == ui->checkBox_2) {
            if (sender() == ui->checkBox) {
                ui->checkBox_2->setChecked(false);
            } else {
                ui->checkBox->setChecked(false);
            }
        }
        if (sender() == ui->checkBox_3 || sender() == ui->checkBox_4) {
            if (sender() == ui->checkBox_3) {
                ui->checkBox_4->setChecked(false);
            } else {
                ui->checkBox_3->setChecked(false);
            }
        }
    }
}

//save checkboxes states
void notifications::saveCheckboxStates()
{
    QSettings settings("MyApp", "MySettings");

    settings.setValue("checkbox1", ui->checkBox->isChecked());
    settings.setValue("checkbox2", ui->checkBox_2->isChecked());
    settings.setValue("checkbox3", ui->checkBox_3->isChecked());
    settings.setValue("checkbox4", ui->checkBox_4->isChecked());
}

//load the checkboxes states when reopenning notifications
void notifications::loadCheckboxStates()
{
    QSettings settings("MyApp", "MySettings");

    ui->checkBox->setChecked(settings.value("checkbox1", false).toBool());
    ui->checkBox_2->setChecked(settings.value("checkbox2", false).toBool());
    ui->checkBox_3->setChecked(settings.value("checkbox3", false).toBool());
    ui->checkBox_4->setChecked(settings.value("checkbox4", false).toBool());
}
