TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    genetic.cpp \
    opencv.cpp \
    Lista_simple.cpp \
    NodoG.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    genetic.h \
    opencv.h \
    Lista_simple.h \
    NodoG.h

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
