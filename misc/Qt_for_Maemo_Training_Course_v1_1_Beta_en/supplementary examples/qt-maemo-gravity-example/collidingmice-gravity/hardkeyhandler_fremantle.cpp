#include <QWidget>
#include <QX11Info>
#include <X11/Xatom.h>

#include "hardkeyhandler_fremantle.h"

#define M_FILE "/sys/devices/platform/gpio-switch/slide/state"
/*"/sys/devices/platform/gpio-switch/cam_shutter/state";
"/sys/devices/platform/gpio-switch/cam_focus/state";
"/sys/devices/platform/gpio-switch/cam_launch/state";
"/sys/devices/platform/gpio-switch/headphone/state";*/
    

HardkeyHandlerPrivate::HardkeyHandlerPrivate( HardkeyHandler *handler )
        : m_bus(QDBusConnection::systemBus())
{
    publicHandler = handler;

    // ** Connect power key D-bus signal to a slot **
    m_bus.connect("",
                  "/org/freedesktop/Hal/devices/computer_logicaldev_input",
                  "org.freedesktop.Hal.Device", "Condition",
                  this,
                  SLOT(handlePowerKey(QString,QString)));

    // Set filename (default keyboard slider), check that file exists, and open file
    m_file.setFileName(M_FILE);
    if (m_file.exists() && m_file.open(QIODevice::ReadOnly))
    {
        m_file_data = m_file.readAll();
        
        // Everything ok, set up notifier
        m_notifier = new QSocketNotifier(m_file.handle(), QSocketNotifier::Read);
        connect(m_notifier, SIGNAL(activated(int)), this, SLOT(handleFileActivity(int)));
        m_notifier->setEnabled(true);
    }

}

HardkeyHandlerPrivate::~HardkeyHandlerPrivate()
{
    if ( m_notifier )
    {
        m_notifier->setEnabled(false);
        delete m_notifier;
        m_notifier = 0;
    }

    m_file.close();
}

void HardkeyHandlerPrivate::handlePowerKey(QString, QString)
{
    emit publicHandler->powerKeyPressed();
}

void HardkeyHandlerPrivate::handleFileActivity(int /*socket*/)
{
    // Just read all data from file and reset it
    m_file.reset();
    QByteArray data = m_file.readAll();
    if (data != m_file_data) {//file changed
      m_file_data = data;
      emit publicHandler->keyboardSliderMoved(data.contains("open"));
    }  
}

bool HardkeyHandlerPrivate::processX11Event(XEvent* event)
{
    if ( event->type == KeyPress )
    {
        if (event->xkey.keycode == 73 || event->xkey.keycode == QKeySequence::ZoomOut)
        {
            emit publicHandler->decreaseKeyPressed();
            return true;
        }
        else if (event->xkey.keycode == 74  || event->xkey.keycode == QKeySequence::ZoomIn)
        {
            emit publicHandler->increaseKeyPressed();
            return true;
        }
    }

    return false;
}

void HardkeyHandlerPrivate::grabIncreaseDecreaseKeys(QWidget* window, bool grab)
{
    // Tell maemo-status-volume to grab/ungrab increase/decrease keys
    unsigned long val = (grab==true)?1:0;
    Atom atom;
    atom = XInternAtom( QX11Info::display(), "_HILDON_ZOOM_KEY_ATOM", 0);
    XChangeProperty (QX11Info::display(),
                     window->winId(),
                     atom,
                     XA_INTEGER,
                     32,
                     PropModeReplace,
                     (unsigned char *) &val,
                     1);

    if ( grab )
    {
        XGrabKey(QX11Info::display(),
                  QKeySequence::ZoomOut,
                  AnyModifier,
                  window->winId(),
                  True,
                  GrabModeAsync,
                  GrabModeAsync);

        XGrabKey(QX11Info::display(),
                  QKeySequence::ZoomIn,
                  AnyModifier,
                  window->winId(),
                  True,
                  GrabModeAsync,
                  GrabModeAsync);
    }
    else
    {
        /*XUngrabKey(QX11Info::display(),
                  73,
                  window->winId());

        XUngrabKey(QX11Info::display(),
                  74,
                  window->winId());*/
    }
}
