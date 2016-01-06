TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Vector.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Vector.h

