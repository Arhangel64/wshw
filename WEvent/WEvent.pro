#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T13:28:53
#
#-------------------------------------------------

QT       -= core

TARGET = WEvent
TEMPLATE = lib
CONFIG += staticlib

SOURCES += wevent.cpp \
    wmessage.cpp \
    wsetid.cpp \
    wnickrequest.cpp \
    wnickresponse.cpp \
    wclientlist.cpp

HEADERS += wevent.h\
    wmessage.h \
    wsetid.h \
    wnickrequest.h \
    wnickresponse.h \
    wclientlist.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
