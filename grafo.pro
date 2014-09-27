TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Nodo.cpp \
    ListaEnlazada.cpp \
    Grafo.cpp \
    clasificadordefiguras.cpp \
    NodoGrafo.cpp \
    ListaDeAdyacencia.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Nodo.h \
    ListaEnlazada.h \
    Grafo.h \
    clasificadordefiguras.h \
    NodoGrafo.h \
    ListaDeAdyacencia.h

INCLUDEPATH += /usr/local/include/opencv

LIBS += -L/usr/local/lib

LIBS += -lopencv_core

LIBS += -lopencv_imgproc

LIBS += -lopencv_highgui

LIBS += -lopencv_ml

LIBS += -lopencv_video

LIBS += -lopencv_features2d

LIBS += -lopencv_calib3d

LIBS += -lopencv_objdetect

LIBS += -lopencv_contrib

LIBS += -lopencv_legacy

LIBS += -lopencv_flann

LIBS += -lopencv_nonfree

# -L represents for Directory

# -l represents for file

