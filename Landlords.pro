QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    card.cpp \
    cardpenal.cpp \
    cards.cpp \
    gamecontrol.cpp \
    main.cpp \
    gamepanel.cpp \
    player.cpp \
    robot.cpp \
    scorepanel.cpp \
    userplayer.cpp

HEADERS += \
    card.h \
    cardpenal.h \
    cards.h \
    gamecontrol.h \
    gamepanel.h \
    player.h \
    robot.h \
    scorepanel.h \
    userplayer.h

FORMS += \
    gamepanel.ui \
    scorepanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
