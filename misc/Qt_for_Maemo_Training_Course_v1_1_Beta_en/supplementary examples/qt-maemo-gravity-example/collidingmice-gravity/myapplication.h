#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QGraphicsView>
#include "hardkeyhandler.h"

class MyApplication : public QApplication
{
    Q_OBJECT
public:
    QGraphicsView view;
    MyApplication(int& argc, char** argv);
    
#ifdef Q_WS_X11
    virtual bool x11EventFilter(XEvent* event);
#endif
    
    HardkeyHandler* keyHandler();

public slots:
    void increaseKeyPressed();
    void decreaseKeyPressed();

private:
    HardkeyHandler* m_keyHandler;
    
};

#endif // MYAPPLICATION_H
