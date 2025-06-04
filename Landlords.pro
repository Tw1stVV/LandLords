QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    buttongroup.cpp \
    card.cpp \
    cardpanel.cpp \
    cards.cpp \
    gamecontrol.cpp \
    main.cpp \
    gamepanel.cpp \
    mybutton.cpp \
    player.cpp \
    playhand.cpp \
    robot.cpp \
    scorepanel.cpp \
    userplayer.cpp

HEADERS += \
    buttongroup.h \
    card.h \
    cardpanel.h \
    cards.h \
    gamecontrol.h \
    gamepanel.h \
    mybutton.h \
    player.h \
    playhand.h \
    robot.h \
    scorepanel.h \
    userplayer.h

FORMS += \
    buttongroup.ui \
    gamepanel.ui \
    scorepanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
