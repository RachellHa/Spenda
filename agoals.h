#ifndef AGOALS_H
#define AGOALS_H

#include <QMainWindow>

namespace Ui {
class agoals;
}

class agoals : public QMainWindow {
    Q_OBJECT

public:
    explicit agoals(QWidget *parent = nullptr);
    ~agoals();

private slots:
    void on_backButton_clicked();   //slot for the "Back" button
    void on_saveButton_clicked();   //slot for the "Save" button

private:
    Ui::agoals *ui;
};

#endif //AGOALS_H
