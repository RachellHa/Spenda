#include "login.h"
#include "ui_login.h"
#include "menu.h"
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login) {

    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Login" title label to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label->setFont(titleFont);

    //set font for other labels, line edits, and the Continue button to size 12
    QFont standardFont("Cascadia Code");
    standardFont.setPointSize(12);

    ui->label_2->setFont(standardFont);  //email label
    ui->label_3->setFont(standardFont);  //password label
    ui->lineEdit->setFont(standardFont); //email input field
    ui->lineEdit_2->setFont(standardFont); //password input field

    //line edits and push button have a white background
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->pushButton->setStyleSheet("background-color: white;");


    //connect Continue button to its slot
    connect(ui->pushButton, &QPushButton::clicked, this, &login::onContinueClicked);
}

login::~login() {
    delete ui;
}

//slot for the Continue button
void login::onContinueClicked() {
    //check if required fields are empty
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both email and password.");
        return;
    }

    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}
