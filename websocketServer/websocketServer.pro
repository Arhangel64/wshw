#-------------------------------------------------
#
# Project created by QtCreator 2015-06-03T16:22:15
#
#-------------------------------------------------

QT       += core gui widgets websockets


TARGET = websocketServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    client.cpp \
    servercore.cpp \
    nickstoragemodel.cpp \
    nickmodel.cpp

HEADERS  += mainwindow.h \
    controller.h \
    client.h \
    servercore.h \
    nickstoragemodel.h \
    nickmodel.h

unix|win32: LIBS += -L$$PWD/../WEvent/build/ -lWEvent

INCLUDEPATH += $$PWD/../WEvent
DEPENDPATH += $$PWD/../WEvent

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../WEvent/build/WEvent.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../WEvent/build/libWEvent.a
