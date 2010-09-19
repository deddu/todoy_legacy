
TARGET = qmobilepaint
TEMPLATE = app

VERSION = 1.0.0

Qt += core \
      gui

# EXERCISE DBUS:
# You are going to use D-Bus, is something missing from the project file?
# Remember that D-Bus is not available on all platforms!


RESOURCES = resources.qrc

SOURCES += main.cpp \
           widget.cpp \
           mainwindow.cpp \
           toolbarwidget.cpp \
           toolbarbutton.cpp

HEADERS  += widget.h \
            mainwindow.h \
            toolbarwidget.h \
            toolbarbutton.h


# Symbian specific
symbian: { 
    ICON = icon.svg
    TARGET.UID3 = 0xEd0cc810
    TARGET.EPOCHEAPSIZE = 0x100000 0x2000000
    TARGET.EPOCSTACKSIZE = 0x14000
    LIBS += -lcone -leikcore -lavkon
}            

# Maemo specific
maemo5: {
    # Variables
    isEmpty(PREFIX):PREFIX = /usr/local
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share
    DEFINES += DATADIR=\\\"$$DATADIR\\\" \
        PKGDATADIR=\\\"$$PKGDATADIR\\\"


    # EXERCISE DESKTOPFILE:
	# How to add support for a desktop file?
    INSTALLS += target \
        iconxpm \
        icon26 \
        icon40 \
        icon64

    target.path = $$BINDIR

    # EXERCISE DESKTOPFILE:
    # How to add support for a desktop file?
    
    iconxpm.path = $$DATADIR/pixmap
    iconxpm.files += ../icon/maemo/qmobilepaint.xpm

    icon26.path = $$DATADIR/icons/hicolor/26x26/apps
    icon26.files += ../icon/26x26/qmobilepaint.png

    icon40.path = $$DATADIR/icons/hicolor/40x40/apps
    icon40.files += ../icon/40x40/qmobilepaint.png

    icon64.path = $$DATADIR/icons/hicolor/64x64/apps
    icon64.files += ../icon/64x64/qmobilepaint.png
}
