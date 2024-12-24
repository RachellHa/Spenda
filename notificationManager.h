#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

// NotificationManager.h
class NotificationManager {
private:
    static NotificationManager* instance;
    NotificationManager() {}

public:
    static NotificationManager* getInstance() {
        if (!instance) {
            instance = new NotificationManager();
        }
        return instance;
    }

    void sendNotification(const std::string& message) {
        //logic for sending notifications
    }
};

//initialize static member
NotificationManager* NotificationManager::instance = nullptr;


#endif
