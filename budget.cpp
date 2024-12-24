#include "budget.h"
#include "ui_budget.h"

budget::budget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::budget)
{
    ui->setupUi(this);
}

budget::~budget()
{
    delete ui;
}
