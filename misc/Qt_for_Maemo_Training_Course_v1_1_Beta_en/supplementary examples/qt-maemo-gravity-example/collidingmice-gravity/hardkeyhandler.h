#ifndef HARDKEYHANDLER_H
#define HARDKEYHANDLER_H

#include <QtCore>
#ifdef Q_WS_X11
#include <X11/Xlib.h>
#endif

//forward definition of private class
class HardkeyHandlerPrivate;

/**
  * Hardkey handler.
  *
  * Catches hardkey presses and events. Following keys and events are caught:
  * - Increase volume key
  * - Decrease volume key
  * - Power key
  * - Open/close sliding keyboard
  *
  */
class HardkeyHandler : public QObject
{
    Q_OBJECT

public:
    /**
     * Constructs new hardkey handler object and starts listening to key presses
     * and events
     *
     */
    explicit HardkeyHandler();

    /**
     * Destroys object and release all its resources.
     * and events
     */
    ~HardkeyHandler();

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


signals:

    /**
     * Emited when increase key has been pressed.
     */
    void increaseKeyPressed();

    /**
     * Emited when decrease key has been pressed.
     */
    void decreaseKeyPressed();
    
    /**
     * Emited when power key has been pressed.
     */
    void powerKeyPressed();
    
    /**
     * Emited when keyboard has been moved.
     *
     * @param open True if keyboard was opened, false if it was closed.
     */
    void keyboardSliderMoved(bool open);


private:
    //pointer to the private platform-specific handler
    HardkeyHandlerPrivate* d_ptr;
    friend class HardkeyHandlerPrivate;
};

#endif // HARDKEYHANDLER_H
