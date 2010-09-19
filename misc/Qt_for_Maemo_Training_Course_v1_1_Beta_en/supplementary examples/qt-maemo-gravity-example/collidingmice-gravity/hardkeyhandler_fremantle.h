#ifndef HARDKEYHANDLERPRIVATE_H
#define HARDKEYHANDLERPRIVATE_H

#include <QtDBus>
#include <X11/Xlib.h>

#include "hardkeyhandler.h"

/**
  * Hardkey handler.
  *
  * Catches hardkey presses and events. Following keys and events are caught:
  * - Increase volume key: by using xevents
  * - Decrease volume key: by using xevents
  * - Power key: by monitoring D-Bus
  * - Open/close sliding keyboard: by monitoring a file
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
     * Grabs or ungrabs increase and decrease keys from maemo-statusmenu-volume 
     * application. Note: in order to receive signals
     * increaseKeyPressed() and decreaseKeyPressed(), you must feed function 
     * processX11Event() with X11 events. Otherwise these
     * events can be caught in QWidget::keyPressEvent() function.
     * @param window Window which captures the keys.
     * @param grab Set this flag to true in order to grab keys and to false in 
     * order to ungrab keys.
     */
    void grabIncreaseDecreaseKeys(QWidget* window, bool grab = true);

    /**
     * Processes hardkey related X11 key events. Note: in order to receive 
     * signals increaseKeyPressed() and decreaseKeyPressed(), you must feed 
     * function processX11Event() with X11 events. Otherwise these
     * events can be caught in QWidget::keyPressEvent() function.
     * @param event X11 event
     * @return True if event was processed, false if not.
     */
    bool processX11Event(XEvent* event);

private slots:
    void handlePowerKey(QString arg1, QString arg2);
    void handleFileActivity(int);

signals:
/**
     * Emited when contents of the file has been changed.
     *
     * @param data Contents of the file.
     */
    void activated(QByteArray data);
    
    
private:
    QFile m_file;
    QSocketNotifier* m_notifier;
    QDBusConnection m_bus;
    QByteArray m_file_data;
    
    //pointer to the public handler
    HardkeyHandler *publicHandler;
};

#endif // HARDKEYHANDLERPRIVATE_H
