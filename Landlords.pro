QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    card.cpp \
    cardpenal.cpp \
    cards.cpp \
    main.cpp \
    gamepanel.cpp \
    player.cpp

HEADERS += \
    card.h \
    cardpenal.h \
    cards.h \
    gamepanel.h \
    player.h

FORMS += \
    gamepanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
