/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#ifndef ToolBarButton_h
#define ToolBarButton_h

#include <QtGui>

class ToolBarSizeButton;

/*****************************************************************************
 * ToolBarButton
 */
class ToolBarButton: public QWidget
{
Q_OBJECT

public:
    enum ButtonType
    {
        ENoType,
        ENew,
        EPen,
        ERectangle,
        ELine,
        ECircle,
        EUndo,
        ESave,
        EOpen,
        EExit,
        EColor,
        ESize,
        EErase,
        EMinimize
    };

public:
    ToolBarButton(ToolBarButton::ButtonType type = ToolBarButton::ENoType, QWidget *parent = 0);
    virtual ~ToolBarButton();

    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

    virtual void resizeEvent(QResizeEvent *);
    virtual void timerEvent(QTimerEvent *);

    virtual void paintEvent(QPaintEvent *);
    virtual bool isPressed();
    virtual void setPressed(bool);

    virtual ToolBarButton::ButtonType btnType();

    virtual bool isToolButton(ToolBarButton::ButtonType = ENoType);
    virtual bool isDialogButton();

public slots:
    virtual void someButtonPressed(ToolBarButton::ButtonType);

    signals:
    void buttonPressed(ToolBarButton::ButtonType);

protected:
    ButtonType type;
    QPixmap upPixmap;
    QPixmap downPixmap;
    bool pressed;
    bool acceptMouseMove;
    int acceptMouseMoveTimer;
};

/*****************************************************************************
 * ToolBarSizeButton
 */
const int MIN_PEN_SIZE = 2;
const int PEN_APPEND_SIZE = 2;
const int MAX_PEN_SIZE = 6;
class ToolBarSizeButton: public ToolBarButton
{
Q_OBJECT

public:
    ToolBarSizeButton(QWidget *parent = 0);
    ~ToolBarSizeButton();

    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *);

    int penSize();
    void setNextPenSize();

private:
    void loadSvg();

private:
    int pSize;
};

/*****************************************************************************
 * ToolBarColorButton
 */
class ToolBarColorButton: public ToolBarButton
{
Q_OBJECT

public:
    ToolBarColorButton(QWidget *parent = 0);
    ~ToolBarColorButton();

    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

    void setColor(QColor&);
    QColor Color();

private:
    QColor color;
    QPen pen;
    QBrush brush;
    QRect colorRect;
};

#endif // ToolBarButton_h
