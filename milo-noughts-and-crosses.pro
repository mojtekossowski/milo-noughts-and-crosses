TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    tictacengine.cpp \
    tictacplayer.cpp \
    tictacboard.cpp

RESOURCES += qml.qrc \
    resources.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    tictacengine.h \
    tictacplayer.h \
    tictacboard.h

DISTFILES += \
    fireworks.js
