#-------------------------------------------------
#
# Project created by QtCreator 2019-07-12T18:44:48
#
#-------------------------------------------------

QT       -= gui

TARGET = factory_abstract
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

SOURCES +=

HEADERS += \
    factory_abstract.hpp \
    indexator.hpp \
    example.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../non_parallel_structures/release/ -lnon_parallel_structures
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../non_parallel_structures/debug/ -lnon_parallel_structures
else:unix: LIBS += -L$$OUT_PWD/../non_parallel_structures/ -lnon_parallel_structures

INCLUDEPATH += $$PWD/../non_parallel_structures
DEPENDPATH += $$PWD/../non_parallel_structures

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/release/libnon_parallel_structures.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/debug/libnon_parallel_structures.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/release/non_parallel_structures.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/debug/non_parallel_structures.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../non_parallel_structures/libnon_parallel_structures.a
