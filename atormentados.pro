QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/jogador.cpp \
    sources/jogoscene.cpp \
    sources/jogoview.cpp \
    sources/main.cpp \
    sources/background.cpp \
    sources/dialog.cpp \
    sources/windowprincipal.cpp

INCLUDEPATH += \
    $$PWD/includes/

HEADERS += \
    includes/definicoes.h \
    includes/background.h \
    includes/dialog.h \
    includes/windowprincipal.h \
    includes/jogoview.h \
    includes/jogoscene.h \
    includes/jogador.h

FORMS += \
    ui/windowprincipal.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES += \
#    resources/wordart.png

RESOURCES += \
    resources.qrc

