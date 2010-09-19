TEMPLATE = lib
TARGET = devornot-qt-maemo
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += debug

# Add hildon scope to CONFIG if it is QT_CONFIG
maemo5 {
  CONFIG += hildon
}  

QT += dbus
CONFIG += link_pkgconfig

# Enable this to disable debugging
#DEFINES += QT_NO_DEBUG_OUTPUT

# Input
HEADERS += deviceorientationnotifier.h
SOURCES += deviceorientationnotifier.cpp


# Maemo Fremantle specific private classes, modify this on other systems
maemo5 {
  PKGCONFIG += mce
  HEADERS += deviceorientationnotifier_fremantle_p.h
  SOURCES += deviceorientationnotifier_fremantle_p.cpp
} else {
  HEADERS += deviceorientationnotifier_stub_p.h
  SOURCES += deviceorientationnotifier_stub_p.cpp
}


target.path += /usr/lib
devincludes.files = $$HEADERS
devincludes.path += /usr/include/$$TEMPLATE$$TARGET
INSTALLS += target devincludes
