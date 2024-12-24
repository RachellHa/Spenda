#ifndef USER_H
#define USER_H

#include "Observer.h"
#include <QMessageBox>

class User : public Observer {
public:
    void update(const std::string& message) override {
        //logic for user notification
        QMessageBox::information(nullptr, "Notification", QString::fromStdString(message));
    }
};

#endif
