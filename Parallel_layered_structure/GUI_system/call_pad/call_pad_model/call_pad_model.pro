#-------------------------------------------------
#
# Project created by QtCreator 2019-09-14T12:21:33
#
#-------------------------------------------------

QT       += gui

TARGET = call_pad_model
TEMPLATE = lib
CONFIG += staticlib

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
        call_pad_model.cpp

HEADERS += \
        call_pad_model.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Handler_system/handler_system/release/ -lhandler_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Handler_system/handler_system/debug/ -lhandler_system
else:unix: LIBS += -L$$OUT_PWD/../../../Handler_system/handler_system/ -lhandler_system

INCLUDEPATH += $$PWD/../../../Handler_system/handler_system
DEPENDPATH += $$PWD/../../../Handler_system/handler_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Handler_system/handler_system/release/libhandler_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Handler_system/handler_system/debug/libhandler_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Handler_system/handler_system/release/handler_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Handler_system/handler_system/debug/handler_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Handler_system/handler_system/libhandler_system.a



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Level_system/level_system/release/ -llevel_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Level_system/level_system/debug/ -llevel_system
else:unix: LIBS += -L$$OUT_PWD/../../../Level_system/level_system/ -llevel_system

INCLUDEPATH += $$PWD/../../../Level_system/level_system
DEPENDPATH += $$PWD/../../../Level_system/level_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Level_system/level_system/release/liblevel_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Level_system/level_system/debug/liblevel_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Level_system/level_system/release/level_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Level_system/level_system/debug/level_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Level_system/level_system/liblevel_system.a
