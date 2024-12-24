#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H

#include <QMainWindow>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QFont>

namespace Ui {
class notifications;
}

class notifications : public QMainWindow
{
    Q_OBJECT

public:
    explicit notifications(QWidget *parent = nullptr);
    ~notifications();

private slots:
    void on_backButton_clicked();            //slot for Back button
    void on_saveButton_clicked();            //slot for Save button
    void on_clearButton_clicked();           //slot for Clear button
    void on_checkBox_toggled(bool checked);  //slot for handling checkbox toggling

private:
    Ui::notifications *ui;

    void saveCheckboxStates();     //save checkbox states
    void loadCheckboxStates();     //load checkbox states
};

#endif //NOTIFICATIONS_H
