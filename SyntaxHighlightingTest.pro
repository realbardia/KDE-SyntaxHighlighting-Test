QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

!win: !android {
    DEFINES += KSYNTAX_HIGHLIGHTER
    linux {
        INCLUDEPATH += /usr/include/KF5/KSyntaxHighlighting
        LIBS += -lKF5SyntaxHighlighting
    }
    macx {
        INCLUDEPATH += $$[QT_INSTALL_HEADERS]/KF5SyntaxHighlighting
        LIBS += -L$$[QT_INSTALL_LIBS] -lKF5SyntaxHighlighting
    }
}

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
