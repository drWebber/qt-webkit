QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_webkittest.cpp \
    webkit/tag/a.cpp \
    webkit/tag/body.cpp \
    webkit/tag/button.cpp \
    webkit/tag/div.cpp \
    webkit/tag/h1.cpp \
    webkit/tag/head.cpp \
    webkit/tag/header.cpp \
    webkit/tag/html.cpp \
    webkit/tag/img.cpp \
    webkit/tag/li.cpp \
    webkit/tag/span.cpp \
    webkit/tag/table.cpp \
    webkit/tag/tag.cpp \
    webkit/domain.cpp \
    filereader/filereader.cpp \
    util/regexp.cpp \
    webkit/tag/htmldom.cpp \
    webkit/tag/retrievable.cpp \
    webkit/tag/ul.cpp \
    webkit/tag/ol.cpp \
    webkit/tag/h2.cpp \
    webkit/tag/h3.cpp \
    webkit/tag/h4.cpp \
    webkit/tag/h5.cpp \
    webkit/tag/h6.cpp

HEADERS += \
    webkit/tag/a.h \
    webkit/tag/body.h \
    webkit/tag/button.h \
    webkit/tag/div.h \
    webkit/tag/h1.h \
    webkit/tag/head.h \
    webkit/tag/header.h \
    webkit/tag/html.h \
    webkit/tag/img.h \
    webkit/tag/li.h \
    webkit/tag/span.h \
    webkit/tag/table.h \
    webkit/tag/tag.h \
    webkit/domain.h \
    filereader/filereader.h \
    util/regexp.h \
    webkit/tag/htmldom.h \
    webkit/tag/retrievable.h \
    webkit/tag/ul.h \
    webkit/tag/ol.h \
    webkit/tag/h2.h \
    webkit/tag/h3.h \
    webkit/tag/h4.h \
    webkit/tag/h5.h \
    webkit/tag/h6.h

DISTFILES += \
    sources/html.html
