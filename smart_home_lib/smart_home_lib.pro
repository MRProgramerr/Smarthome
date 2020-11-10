#-------------------------------------------------
#
# Project created by QtCreator 2020-10-05T01:30:13
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = smart_home_lib
TEMPLATE = lib
CONFIG += c++17 staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        abstractmeasurement.cpp \
        controller.cpp \
        csvfile.cpp \
        device.cpp \
        deviceabstractfactory.cpp \
        devicefactory.cpp \
        deviceinfo.cpp \
        lightswitch.cpp \
        lightswitchdevicefactory.cpp \
        lightswitchproxy.cpp \
        lightswitchproxyfactory.cpp \
        mainmenu.cpp \
        measurementtemplate.cpp \
        proxyabstractfactory.cpp \
        proxyfactory.cpp \
        proxyinterface.cpp \
        smart_home_lib.cpp \
        sprinklerdevicefactory.cpp \
        sprinklersystem.cpp \
        sprinklersystemproxy.cpp \
        sprinklersystemproxyfactory.cpp \
        sprinklersystemproxyinterface.cpp \
        thermostat.cpp \
        thermostatdevicefactory.cpp \
        thermostatproxy.cpp \
        thermostatproxyfactory.cpp \
        thermostatproxyinterface.cpp

HEADERS += \
        LightSwitchProxyInterface.h \
        abstractmeasurement.h \
        controller.h \
        csvfile.h \
        device.h \
        deviceabstractfactory.h \
        devicefactory.h \
        deviceinfo.h \
        lightswitch.h \
        lightswitchdevicefactory.h \
        lightswitchproxy.h \
        lightswitchproxyfactory.h \
        mainmenu.h \
        measurementtemplate.h \
        proxyabstractfactory.h \
        proxyfactory.h \
        proxyinterface.h \
        smart_home_lib.h \
        sprinklerdevicefactory.h \
        sprinklersystem.h \
        sprinklersystemproxy.h \
        sprinklersystemproxyfactory.h \
        sprinklersystemproxyinterface.h \
        thermostat.h \
        thermostatdevicefactory.h \
        thermostatproxy.h \
        thermostatproxyfactory.h \
        thermostatproxyinterface.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../xbin/ -lqhttp-embed
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../xbin/ -lqhttp-embed
else:unix: LIBS += -L$$OUT_PWD/../xbin/ -lqhttp-embed

INCLUDEPATH += $$PWD/../qhttp-embed
DEPENDPATH += $$PWD/../qhttp-embed
