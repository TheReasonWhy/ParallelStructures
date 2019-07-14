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
    threadpool.cpp \
    work_generator.cpp \
    timer.cpp \
    indexer.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    threadpool.h \
    join_threads.hpp \
    work.hpp \
    work_generator.h \
    timer.h \
    indexer.h

LIBS += -L/usr/lib/x86_64-linux-gnu/libatomic.so.1

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../victim/release/ -lvictim
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../victim/debug/ -lvictim
else:unix: LIBS += -L$$OUT_PWD/../victim/ -lvictim

INCLUDEPATH += $$PWD/../victim
DEPENDPATH += $$PWD/../victim


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_structures/release/ -lparallel_structures
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_structures/debug/ -lparallel_structures
else:unix: LIBS += -L$$OUT_PWD/../parallel_structures/ -lparallel_structures

INCLUDEPATH += $$PWD/../parallel_structures
DEPENDPATH += $$PWD/../parallel_structures

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/release/libparallel_structures.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/debug/libparallel_structures.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/release/parallel_structures.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/debug/parallel_structures.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_structures/libparallel_structures.a

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
