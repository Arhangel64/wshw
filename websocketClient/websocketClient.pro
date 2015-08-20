#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T16:12:02
#
#-------------------------------------------------

QT       += core gui widgets websockets

TARGET = websocketClient
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogue.cpp \
    clientcore.cpp \
    clientlistmodel.cpp \
    clientsettingsdialogue.cpp

HEADERS  += mainwindow.h \
    dialogue.h \
    clientcore.h \
    clientlistmodel.h \
    clientsettingsdialogue.h

unix|win32: LIBS += -L$$PWD/../WEvent/build/ -lWEvent

INCLUDEPATH += $$PWD/../WEvent
DEPENDPATH += $$PWD/../WEvent

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../WEvent/build/WEvent.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../WEvent/build/libWEvent.a
