TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    dictionary.cpp \
    word.cpp \
    filerecord.cpp \
    Parser.cpp \
    porter2_stemmer.cpp

HEADERS += \
    avlnode.h \
    avltree.h \
    dictionary.h \
    word.h \
    filerecord.h \
    Parser.h \
    porter2_stemmer.h \
    rapidxml.hpp \
    rapidxml_iterators.hpp \
    rapidxml_print.hpp \
    rapidxml_utils.hpp

OTHER_FILES += \
    Parser.h.gch \
    porter2_stemmer.h.gch

