QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DESTDIR = $$PWD/../bin

include($$PWD/cell/cell.pri)
include($$PWD/lib/lib.pri)

RESOURCES += \
    res/res.qrc

RC_FILE = $$PWD/res/app.rc
