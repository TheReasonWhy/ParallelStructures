#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T13:47:35
#
#-------------------------------------------------

QT       -= gui

TARGET = layered_data
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
        layered_data.cpp \
    up_data.cpp \
    middle_data.cpp \
    low_data.cpp \
    low_data_t1.cpp \
    low_data_t2.cpp \
    middle_data_t1.cpp \
    middle_data_t2.cpp \
    up_data_t1.cpp \
    up_data_t2.cpp

HEADERS += \
        layered_data.h \
    up_data.h \
    middle_data.h \
    low_data.h \
    low_data_t1.h \
    low_data_t2.h \
    middle_data_t1.h \
    middle_data_t2.h \
    up_data_t1.h \
    up_data_t2.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/release/ -linterval_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/debug/ -linterval_system
else:unix: LIBS += -L$$OUT_PWD/../../Interval_system/interval_system/ -linterval_system

INCLUDEPATH += $$PWD/../../Interval_system/interval_system
DEPENDPATH += $$PWD/../../Interval_system/interval_system

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/release/libinterval_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/debug/libinterval_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/release/interval_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/debug/interval_system.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Interval_system/interval_system/libinterval_system.a
