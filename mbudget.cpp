#include "mbudget.h"
#include "ui_mbudget.h"

mBudget::mBudget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mBudget)
{
    ui->setupUi(this);
}

mBudget::~mBudget()
{
    delete ui;
}
