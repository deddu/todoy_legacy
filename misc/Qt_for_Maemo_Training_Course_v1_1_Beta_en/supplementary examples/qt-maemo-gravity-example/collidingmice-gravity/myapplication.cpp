#include "myapplication.h"

#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif

MyApplication::MyApplication(int& argc, char** argv)
        :QApplication(argc,argv)
{
        m_keyHandler = new HardkeyHandler();
}

HardkeyHandler* MyApplication::keyHandler()
{
    return m_keyHandler;
}

#ifdef Q_WS_X11
bool MyApplication::x11EventFilter(XEvent* event)
{
    if ( m_keyHandler->processX11Event(event) )
    {
        return true;
    }
    return false;
}
#endif

void MyApplication::increaseKeyPressed()
{
    qDebug("MyApplication::increaseKeyPressed");
    view.showFullScreen();

}

void MyApplication::decreaseKeyPressed()
{
    qDebug("MyApplication::decreaseKeyPressed");
    view.showNormal();
}
