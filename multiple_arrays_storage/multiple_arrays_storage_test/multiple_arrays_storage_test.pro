QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_multiple_arrays_storage_test.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Multiple_arrays_storage/release/ -lMultiple_arrays_storage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Multiple_arrays_storage/debug/ -lMultiple_arrays_storage
else:unix: LIBS += -L$$OUT_PWD/../Multiple_arrays_storage/ -lMultiple_arrays_storage

INCLUDEPATH += $$PWD/../Multiple_arrays_storage
DEPENDPATH += $$PWD/../Multiple_arrays_storage

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Multiple_arrays_storage/release/libMultiple_arrays_storage.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Multiple_arrays_storage/debug/libMultiple_arrays_storage.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Multiple_arrays_storage/release/Multiple_arrays_storage.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Multiple_arrays_storage/debug/Multiple_arrays_storage.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Multiple_arrays_storage/libMultiple_arrays_storage.a
