#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T23:40:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CPP_Curriculum_Design
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Manager.cpp \
    FlightInfo.cpp \
    UserManager.cpp \
    FlightManager.cpp \
    Passenger.cpp \
    User.cpp \
    signindialog.cpp \
    passengermainwindow.cpp \
    selectdialog.cpp \
    retrydialog.cpp \
    managermainwindow.cpp

HEADERS  += mainwindow.h \
    FlightManager.h \
    FlightInfo.h \
    UserManager.h \
    Manager.h \
    Passenger.h \
    User.h \
    signindialog.h \
    passengermainwindow.h \
    selectdialog.h \
    retrydialog.h \
    managermainwindow.h

FORMS    += mainwindow.ui \
    signindialog.ui \
    passengermainwindow.ui \
    selectdialog.ui \
    retrydialog.ui \
    managermainwindow.ui
