#-------------------------------------------------
#
# Project created by QtCreator 2019-07-15T02:39:58
#
#-------------------------------------------------

QT       -= gui

TARGET = parallel_set
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
    parallel_set.hpp \
    parallel_set_packaged.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$PWD/../../Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../Parallel_binary_tree/parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Parallel_binary_tree/parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../Parallel_binary_tree/parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../Parallel_binary_tree/parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../Parallel_binary_tree/parallel_binary_tree/libparallel_binary_tree.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/ -llock_free_queue
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/ -llock_free_queue
else:unix: LIBS += -L$$OUT_PWD/../../Lock_free_queue/lock_free_queue/ -llock_free_queue

INCLUDEPATH += $$PWD/../../Lock_free_queue/lock_free_queue
DEPENDPATH += $$PWD/../../Lock_free_queue/lock_free_queue

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/liblock_free_queue.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/liblock_free_queue.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/release/lock_free_queue.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/debug/lock_free_queue.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Lock_free_queue/lock_free_queue/liblock_free_queue.a
