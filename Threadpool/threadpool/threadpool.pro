#-------------------------------------------------
#
# Project created by QtCreator 2019-07-14T20:51:33
#
#-------------------------------------------------

QT       -= gui

TARGET = threadpool
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
    threadpool_base.hpp \
    threadpool_binary_tree.hpp
unix {
    target.path = /usr/lib
    INSTALLS += target
}

LIBS += -latomic

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/release/ -lparallel_container
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/debug/ -lparallel_container
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/parallel_container/ -lparallel_container

INCLUDEPATH += $$PWD/../../Parallel_structures/parallel_container
DEPENDPATH += $$PWD/../../Parallel_structures/parallel_container

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/release/libparallel_container.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/debug/libparallel_container.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/release/parallel_container.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/debug/parallel_container.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/parallel_container/libparallel_container.a


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree
DEPENDPATH += $$PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Parallel_structures/Parallel_binary_tree/parallel_binary_tree/libparallel_binary_tree.a


