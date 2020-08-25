
TARGET = krono-calculo
BUILD_ROOT=../..
COMPONENT_NAME=krono
include($${BUILD_ROOT}/sdk/build/qmake/qt-module.pri)

SOURCES += \
    emotspace.cc \
    init.cc \
    intlspace.cc \
    kronoscope.cc \
    phisspace.cc \
    qkronosummary.cc

HEADERS += \
    defs.h \
    emotspace.h \
    init.h \
    intlspace.h \
    kronoscope.h \
    kronospace.h \
    phisspace.h \
    qkronosummary.h \
    setup.h

RESOURCES += \
    krono-calculo.qrc

LIBS += $$moduleDep(sdk,arch)
LIBS += $$moduleDep(sdk,controls)
