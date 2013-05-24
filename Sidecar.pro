#-------------------------------------------------
#
# Project created by QtCreator 2013-05-23T22:24:09
#
#-------------------------------------------------

QT       += core gui webkitwidgets

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sidecar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sourcewidget.cpp

HEADERS  += mainwindow.h \
    sourcewidget.h

FORMS    += mainwindow.ui \
    sourcewidget.ui

OTHER_FILES += \
    README.mkd \
    init.css

RESOURCES += \
    web.qrc
