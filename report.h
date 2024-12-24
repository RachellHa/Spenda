#ifndef REPORT_H
#define REPORT_H

#include <QMainWindow>
#include <vector>
#include <QString>

namespace Ui {
class report;
}

class menu;

class report : public QMainWindow
{
    Q_OBJECT

public:
    explicit report(QWidget *parent = nullptr);
    ~report();

private slots:
    void onBackClicked(); //slot for the "Back" button
    void onGenerateReportClicked(); //slot for generating a report
    void onViewReportClicked(); //slot for viewing the generated report

private:
    Ui::report *ui;
    QString generatedReport; //stores the generated report
};

#endif
