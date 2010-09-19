
LIBS += -ldevornot-qt-maemo -L/usr/local/lib 

# Add hildon scope to CONFIG if it is QT_CONFIG
maemo5 {
  CONFIG += hildon
}  

HEADERS += \
	mouse.h \
    hardkeyhandler.h \
    myapplication.h \
	scenetuner.h
SOURCES += \
	main.cpp \
    hardkeyhandler.cpp \
    myapplication.cpp \
	mouse.cpp

# Platform-specific private hw key handlers
maemo5 {
  QT += dbus
  HEADERS += hardkeyhandler_fremantle.h
  SOURCES += hardkeyhandler_fremantle.cpp
} else {
  HEADERS += hardkeyhandler_stub.h
  SOURCES += hardkeyhandler_stub.cpp
}

RESOURCES += \
	mice.qrc

# install
target.path = /usr/bin
INSTALLS += target

desktop.files=collidingmice-gravity.desktop
desktop.path=/usr/share/applications/hildon/
INSTALLS += desktop
