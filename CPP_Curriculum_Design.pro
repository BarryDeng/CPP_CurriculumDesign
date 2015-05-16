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
    managermainwindow.cpp \
    signupdialog.cpp \
    newflightdialog.cpp \
    rechargedialog.cpp \
    editinfodialog.cpp \
    bookedlistdialog.cpp

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
    managermainwindow.h \
    signupdialog.h \
    newflightdialog.h \
    rechargedialog.h \
    editinfodialog.h \
    bookedlistdialog.h

FORMS    += mainwindow.ui \
    signindialog.ui \
    passengermainwindow.ui \
    selectdialog.ui \
    retrydialog.ui \
    managermainwindow.ui \
    signupdialog.ui \
    newflightdialog.ui \
    rechargedialog.ui \
    editinfodialog.ui \
    bookedlistdialog.ui
