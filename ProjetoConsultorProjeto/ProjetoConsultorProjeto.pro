QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    consultor.cpp \
    consultordao.cpp \
    endereco.cpp \
    main.cpp \
    projeto.cpp \
    projetodao.cpp \
    telaalteracaop.cpp \
    telaconsultor.cpp \
    teladealteracoes.cpp \
    telainclusao.cpp \
    telainclusaop.cpp \
    telaprincipal.cpp \
    telaprojeto.cpp \
    telefone.cpp

HEADERS += \
    IConsultorCRUD.h \
    IProjetoCRUD.h \
    consultor.h \
    consultordao.h \
    endereco.h \
    projeto.h \
    projetodao.h \
    telaalteracaop.h \
    telaconsultor.h \
    teladealteracoes.h \
    telainclusao.h \
    telainclusaop.h \
    telaprincipal.h \
    telaprojeto.h \
    telefone.h

FORMS += \
    telaalteracaop.ui \
    telaconsultor.ui \
    teladealteracoes.ui \
    telainclusao.ui \
    telainclusaop.ui \
    telaprincipal.ui \
    telaprojeto.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ArquivoDeRecursos.qrc

DISTFILES += \
    ../../Users/Pedro/Downloads/USADOS/INFO.png \
    imagens/INFO.png
