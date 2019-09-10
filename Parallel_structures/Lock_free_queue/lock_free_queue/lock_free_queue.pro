#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T02:20:48
#
#-------------------------------------------------
QT       -= gui

TARGET = lock_free_queue
TEMPLATE = lib
CONFIG += staticlib
LIBS += -latomic
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
    lock_free_queue.hpp \
    lock_free_queue_packaged_task.hpp \
    lock_free_queue_unique_lock.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../parallel_container/release/ -lparallel_container
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../parallel_container/debug/ -lparallel_container
else:unix: LIBS += -L$$OUT_PWD/../../parallel_container/ -lparallel_container

INCLUDEPATH += $$PWD/../../parallel_container
DEPENDPATH += $$PWD/../../parallel_container

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../parallel_container/release/libparallel_container.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../parallel_container/debug/libparallel_container.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../parallel_container/release/parallel_container.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../parallel_container/debug/parallel_container.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../parallel_container/libparallel_container.a
