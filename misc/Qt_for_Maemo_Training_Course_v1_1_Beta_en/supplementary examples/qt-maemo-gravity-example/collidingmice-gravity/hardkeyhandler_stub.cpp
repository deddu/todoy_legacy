#include <QWidget>
#include "hardkeyhandler_stub.h"

HardkeyHandlerPrivate::HardkeyHandlerPrivate( HardkeyHandler *handler )
{
    publicHandler = handler;

}

HardkeyHandlerPrivate::~HardkeyHandlerPrivate()
{
}

#ifdef Q_WS_X11
bool HardkeyHandlerPrivate::processX11Event(XEvent* event)
{
    return false;
}
#endif

void HardkeyHandlerPrivate::grabIncreaseDecreaseKeys(QWidget* window, bool grab)
{
    
}
