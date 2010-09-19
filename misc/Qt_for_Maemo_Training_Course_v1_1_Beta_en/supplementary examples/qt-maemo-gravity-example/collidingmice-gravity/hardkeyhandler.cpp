#include <QWidget>
#include "hardkeyhandler.h"

#ifdef Q_WS_MAEMO_5
#include "hardkeyhandler_fremantle.h"
#else
#include "hardkeyhandler_stub.h"
#endif


HardkeyHandler::HardkeyHandler()
{
    d_ptr = new HardkeyHandlerPrivate( this );

}

HardkeyHandler::~HardkeyHandler()
{
    delete d_ptr;
}


#ifdef Q_WS_X11
bool HardkeyHandler::processX11Event(XEvent* event)
{
    return d_ptr->processX11Event(event);
}
#endif

void HardkeyHandler::grabIncreaseDecreaseKeys(QWidget* window, bool grab)
{
    d_ptr->grabIncreaseDecreaseKeys(window, grab);
}
