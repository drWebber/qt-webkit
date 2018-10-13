QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_webkittest.cpp \
    network/tag/a.cpp \
    network/tag/body.cpp \
    network/tag/button.cpp \
    network/tag/div.cpp \
    network/tag/h1.cpp \
    network/tag/head.cpp \
    network/tag/header.cpp \
    network/tag/html.cpp \
    network/tag/img.cpp \
    network/tag/li.cpp \
    network/tag/span.cpp \
    network/tag/table.cpp \
    network/tag/tag.cpp \
    network/domain.cpp \
    filereader/filereader.cpp \
    util/regexp.cpp \
    network/tag/htmldom.cpp \
    network/tag/retrievable.cpp

HEADERS += \
    network/tag/a.h \
    network/tag/body.h \
    network/tag/button.h \
    network/tag/div.h \
    network/tag/h1.h \
    network/tag/head.h \
    network/tag/header.h \
    network/tag/html.h \
    network/tag/img.h \
    network/tag/li.h \
    network/tag/span.h \
    network/tag/table.h \
    network/tag/tag.h \
    network/domain.h \
    filereader/filereader.h \
    util/regexp.h \
    network/tag/htmldom.h \
    network/tag/retrievable.h
