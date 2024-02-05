#-------------------------------------------------
#
# Project created by QtCreator 2023-04-22T13:17:33
#
#-------------------------------------------------

QT       += core gui
RC_ICONS += sdust.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExamSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        logindialog.cpp \
    examdialog.cpp \
    examdx.cpp \
    examdu.cpp \
    moudledialog.cpp \
    notimeexamdu.cpp \
    notimeexamdx.cpp \
    notimeexamdialog.cpp \
    exampd.cpp \
    examwd.cpp \
    examjs.cpp

HEADERS += \
        logindialog.h \
    examdialog.h \
    examdialog.h \
    examdx.h \
    examdu.h \
    moudledialog.h \
    notimeexamdu.h \
    notimeexamdx.h \
    notimeexamdialog.h \
    exampd.h \
    examwd.h \
    examjs.h

FORMS += \
        logindialog.ui \
    moudledialog.ui

RESOURCES += \
    imglogin.qrc \
    sdust.qrc

DISTFILES += \
    sdust.png
    msvc {
        QMAKE_CFLAGS += /utf-8
        QMAKE_CXXFLAGS += /utf-8
    }
