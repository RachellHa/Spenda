#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "signUp.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    //set the background color of the main window to #ffffcc
    this->setStyleSheet("background-color: #ffffcc;");

    //set all fonts to Cascadia Code

    //set font for the "Spenda" label to size 80
    QFont titleFont("Cascadia Code");
    titleFont.setPointSize(80);
    ui->label->setFont(titleFont);
    ui->label->setAlignment(Qt::AlignCenter);

    //set font for the "Login" and "Sign Up" buttons to size 34
    QFont buttonFont("Cascadia Code");
    buttonFont.setPointSize(34);
    ui->pushButton->setFont(buttonFont);
    ui->pushButton_2->setFont(buttonFont);

    //connect buttons to their slots
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onSignUpClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

//slot for Login button
void MainWindow::onLoginClicked() {
    login *loginWindow = new login();
    loginWindow->show();
    this->hide();
}

//slot for Sign-up button
void MainWindow::onSignUpClicked() {
    signUp *signUpWindow = new signUp();
    signUpWindow->show();
    this->hide();
}
