#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <string>

//base Transaction class
class Transaction {
public:
    virtual void process() = 0;
    virtual ~Transaction() {}
};

//income Transaction class
class IncomeTransaction : public Transaction {
public:
    void process() override {
    }
};

//expense Transaction class
class ExpenseTransaction : public Transaction {
public:
    void process() override {
    }
};

//factory class
class TransactionFactory {
public:
    static Transaction* createTransaction(const std::string& type) {
        if (type == "income") {
            return new IncomeTransaction();
        } else if (type == "expense") {
            return new ExpenseTransaction();
        }
        return nullptr;
    }
};

#endif
