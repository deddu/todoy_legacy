#ifndef HARDKEYHANDLERPRIVATE_H
#define HARDKEYHANDLERPRIVATE_H

#include <QtCore>
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif


#include "hardkeyhandler.h"

/**
  * Hardkey handler.
  *
  * Catches hardkey presses and events. Following keys and events are caught:
  * - Increase volume key
  * - Decrease volume key
  * - Power key
  * - Open/close sliding keyboard
  */
class HardkeyHandlerPrivate : public QObject
{
    Q_OBJECT

public:
    /**
     * Constructs new hardkey handler object and starts listening to key presses
     * and events
     *
     */
    explicit HardkeyHandlerPrivate( HardkeyHandler *handler );

    /**
     * Destroys object and release all its resources.
     * and events
     */
    ~HardkeyHandlerPrivate();

    /**
     * Grabs or ungrabs increase and decrease keys. Note: in order to receive 
     * signals increaseKeyPressed() and decreaseKeyPressed(), you must feed 
     * function processX11Event() with X11 events. Otherwise these
     * events can be caught in QWidget::keyPressEvent() function.
     * @param window Window which captures the keys.
     * @param grab Set this flag to true in order to grab keys and to false in 
     * order to ungrab keys.
     */
    void grabIncreaseDecreaseKeys(QWidget* window, bool grab = true);
    
#ifdef Q_WS_X11
    /**
     * Processes hardkey related X11 key events. Note: in order to receive 
     * signals increaseKeyPressed() and decreaseKeyPressed(), you must feed 
     * function processX11Event() with X11 events. Otherwise these
     * events can be caught in QWidget::keyPressEvent() function.
     * @param event X11 event
     * @return True if event was processed, false if not.
     */
    bool processX11Event(XEvent* event);
#endif

private:
    
    //pointer to the public handler
    HardkeyHandler *publicHandler;
};

#endif // HARDKEYHANDLERPRIVATE_H
