QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
  ../typeprogresscontroller.cpp \
    tst_testtypeprogresscontroller.cpp

HEADERS += ../typeprogresscontroller.h


INCLUDEPATH += ..


