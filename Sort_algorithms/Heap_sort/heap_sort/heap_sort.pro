#-------------------------------------------------
#
# Project created by QtCreator 2019-07-14T16:17:41
#
#-------------------------------------------------

QT       -= gui

TARGET = heap_sort
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
    heap_sort.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/ -lbinary_heap
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/ -lbinary_heap
else:unix: LIBS += -L$$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/ -lbinary_heap

INCLUDEPATH += $$PWD/../../../Non_parallel_structures/Binary_heap/binary_heap
DEPENDPATH += $$PWD/../../../Non_parallel_structures/Binary_heap/binary_heap

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/libbinary_heap.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/libbinary_heap.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/release/binary_heap.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/debug/binary_heap.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../Non_parallel_structures/Binary_heap/binary_heap/libbinary_heap.a
