TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    dictionary.cpp \
    word.cpp \
    filerecord.cpp

HEADERS += \
    avlnode.h \
    avltree.h \
    dictionary.h \
    word.h \
    filerecord.h

