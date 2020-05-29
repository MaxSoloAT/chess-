TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        board.cpp \
        main.cpp \
        piece.cpp \
        square.cpp

HEADERS += \
    board.h \
    piece.h \
    square.h
