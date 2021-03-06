QT       += core gui
QT       += sql
QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addtrainwindow.cpp \
    dbmanager.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    mytickets.cpp \
    registerdb.cpp \
    user.cpp \
    userdb.cpp

HEADERS += \
    addtrainwindow.h \
    dbmanager.h \
    loginwindow.h \
    mainwindow.h \
    mytickets.h \
    registerdb.h \
    user.h \
    userdb.h

FORMS += \
    addtrainwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    mytickets.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
