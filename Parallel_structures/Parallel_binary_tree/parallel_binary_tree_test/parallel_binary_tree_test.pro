QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -latomic

SOURCES +=  tst_parallel_binary_tree_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../parallel_binary_tree/release/ -lparallel_binary_tree
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../parallel_binary_tree/debug/ -lparallel_binary_tree
else:unix: LIBS += -L$$OUT_PWD/../parallel_binary_tree/ -lparallel_binary_tree

INCLUDEPATH += $$PWD/../parallel_binary_tree
DEPENDPATH += $$PWD/../parallel_binary_tree

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_binary_tree/release/libparallel_binary_tree.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_binary_tree/debug/libparallel_binary_tree.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_binary_tree/release/parallel_binary_tree.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../parallel_binary_tree/debug/parallel_binary_tree.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../parallel_binary_tree/libparallel_binary_tree.a




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/release/ -lworkables
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/debug/ -lworkables
else:unix: LIBS += -L$$PWD/../../../Work_Generator/Workables/workables/ -lworkables

INCLUDEPATH += $$PWD/../../../Work_Generator/Workables/workables
DEPENDPATH += $$PWD/../../../Work_Generator/Workables/workables
