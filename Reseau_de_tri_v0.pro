QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../shared/qstd.cpp \
        connecteur.cpp \
        evolutionaryprocess.cpp \
        gene.cpp \
        individual.cpp \
        main.cpp \
        myrandom.cpp \
        parameters.cpp \
        reseaudetri.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../shared/qstd.h \
    connecteur.h \
    evolutionaryprocess.h \
    gene.h \
    individual.h \
    myrandom.h \
    parameters.h \
    reseaudetri.h
