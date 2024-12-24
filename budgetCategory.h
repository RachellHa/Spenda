#ifndef BUDGETCATEGORY_H
#define BUDGETCATEGORY_H

#include <vector>
#include "Observer.h"

class BudgetCategory {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notifyObservers(const std::string& message) {
        for (Observer* observer : observers) {
            observer->update(message);
        }
    }

    void checkBudgetLimit() {
        //logic for checking limits
        notifyObservers("Budget limit reached for category!");
    }
};

#endif
