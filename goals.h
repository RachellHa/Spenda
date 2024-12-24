#ifndef GOALS_H
#define GOALS_H

#include <QMainWindow>
#include <QString>
#include <vector>

namespace Ui {
class goals;
}

class goals : public QMainWindow
{
    Q_OBJECT

public:
    explicit goals(QWidget *parent = nullptr);
    ~goals();

    void addGoalToLabel(const QString &name, const QString &targetAmount, const QString &deadline);

    static std::vector<QString> goalList; //static list to store goals

private slots:
    void onBackClicked();
    void onAddGoalsClicked();

private:
    Ui::goals *ui;
};

#endif
