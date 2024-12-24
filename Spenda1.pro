QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agoals.cpp \
    atransaction.cpp \
    cbudget.cpp \
    goals.cpp \
    gtest.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    notifications.cpp \
    report.cpp \
    signup.cpp \
    transaction.cpp \
    vbudget.cpp

HEADERS += \
    agoals.h \
    atransaction.h \
    budgetCategory.h \
    cbudget.h \
    goals.h \
    login.h \
    mainwindow.h \
    menu.h \
    notificationManager.h \
    notifications.h \
    observer.h \
    report.h \
    signup.h \
    transaction.h \
    transactionFactory.h \
    user.h \
    vbudget.h

FORMS += \
    agoals.ui \
    atransaction.ui \
    cbudget.ui \
    goals.ui \
    login.ui \
    mainwindow.ui \
    menu.ui \
    notifications.ui \
    report.ui \
    signup.ui \
    transaction.ui \
    vbudget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
