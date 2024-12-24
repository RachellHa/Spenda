#include "signUp.h"
#include "ui_signUp.h"
#include "menu.h"
#include <QMessageBox>

signUp::signUp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::signUp) {

    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Sign Up" title label to size 40
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(40);
    ui->label_2->setFont(titleFont);

    //set font for all other labels to size 12
    QFont standardFont("Cascadia Code");
    standardFont.setPointSize(12);

    ui->label->setFont(standardFont);
    ui->label_3->setFont(standardFont);
    ui->label_4->setFont(standardFont);
    ui->label_5->setFont(standardFont);
    ui->label_6->setFont(standardFont);

    //set font for all line edits
    ui->lineEdit->setFont(standardFont);
    ui->lineEdit_2->setFont(standardFont);
    ui->lineEdit_3->setFont(standardFont);
    ui->lineEdit_4->setFont(standardFont);
    ui->lineEdit_5->setFont(standardFont);

    //line edits and push button have a white background
    ui->lineEdit->setStyleSheet("background-color: white;");
    ui->lineEdit_2->setStyleSheet("background-color: white;");
    ui->lineEdit_3->setStyleSheet("background-color: white;");
    ui->lineEdit_4->setStyleSheet("background-color: white;");
    ui->lineEdit_5->setStyleSheet("background-color: white;");
    ui->pushButton->setStyleSheet("background-color: white;");

    //connect Continue button to its slot
    connect(ui->pushButton, &QPushButton::clicked, this, &signUp::onContinueClicked);
}

signUp::~signUp() {
    delete ui;
}

//slot for the Continue button
void signUp::onContinueClicked() {
    //check if required fields are empty
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all required fields.");
        return;
    }

    menu *menuWindow = new menu();
    menuWindow->show();
    this->close();
}
