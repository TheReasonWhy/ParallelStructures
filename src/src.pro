QT += gui

CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -latomic

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    victim.cpp \
    binary_tree.cpp \
    threadpool.cpp \
    work_generator.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    victim.h \
    binary_tree.h \
    threadpool.h \
    parallel_set.hpp \
    parallel_queue.hpp \
    parallel_stack.hpp \
    node.hpp \
    parallel_container.hpp \
    mem_fun_traits.hpp \
    has_function.hpp \
    join_threads.hpp \
    work.hpp \
    work_generator.h \
    lock_free_queue.hpp
LIBS += -L/usr/lib/x86_64-linux-gnu/libatomic.so.1
