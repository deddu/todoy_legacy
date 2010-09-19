/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#include "toolbarbutton.h"
#include "toolbarwidget.h"
#include <QDebug>

/*****************************************************************************
 * ToolBarButton
 */
ToolBarButton::ToolBarButton(ToolBarButton::ButtonType type, QWidget *parent) :
    QWidget(parent)
{
    this->type = type;
    pressed = false;
    acceptMouseMove = false;
    acceptMouseMoveTimer = -1;
    downPixmap = 0;
    upPixmap = 0;
    setMinimumSize(LandscapeToolbarButtonHeight, LandscapeToolbarButtonHeight);
}

ToolBarButton::~ToolBarButton()
{
}

void ToolBarButton::someButtonPressed(ToolBarButton::ButtonType btnType)
{
    // If some else drawing button is pressed, 
    // and we are drawing and down, we have to rice
    if (isToolButton(btnType)) {
        if (isToolButton()) {
            if (btnType != type && pressed) {
                pressed = false;
                update();
            }
        }
    }
}

bool ToolBarButton::isToolButton(ToolBarButton::ButtonType t)
{
    if (t == ToolBarButton::ENoType) {
        t = this->type;
    }

    if (t == ToolBarButton::EPen || t == ToolBarButton::ELine || t == ToolBarButton::ECircle || t
        == ToolBarButton::ERectangle || t == ToolBarButton::EErase) {
        return true;
    }
    else {
        return false;
    }
}

bool ToolBarButton::isDialogButton()
{
    if (type == ToolBarButton::EOpen || type == ToolBarButton::ESave || type
        == ToolBarButton::EColor || type == ToolBarButton::EMinimize) {
        return true;
    }
    else {
        return false;
    }
}

bool ToolBarButton::isPressed()
{
    return pressed;
}

void ToolBarButton::setPressed(bool p)
{
    pressed = p;
}

void ToolBarButton::resizeEvent(QResizeEvent *event)
{
    if (downPixmap.isNull() && upPixmap.isNull()) {

        // Load right button svg image
        switch (type) {
        case ToolBarButton::ENew:
        {
            upPixmap.load(":/gfx/icon_new_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_new_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EPen:
        {
            upPixmap.load(":/gfx/icon_pen_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_pen_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::ELine:
        {
            upPixmap.load(":/gfx/icon_line_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_line_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::ERectangle:
        {
            upPixmap.load(":/gfx/icon_rectangle_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_rectangle_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::ECircle:
        {
            upPixmap.load(":/gfx/icon_circle_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_circle_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EUndo:
        {
            upPixmap.load(":/gfx/icon_undo_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_undo_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::ESave:
        {
            upPixmap.load(":/gfx/icon_save_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_save_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EExit:
        {
            upPixmap.load(":/gfx/icon_exit_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_exit_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EColor:
        {
            upPixmap.load(":/gfx/icon_color_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_color_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EOpen:
        {
            upPixmap.load(":/gfx/icon_open_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_open_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EErase:
        {
            upPixmap.load(":/gfx/icon_eraser_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_eraser_pressed_38x38.svg");
            break;
        }
        case ToolBarButton::EMinimize:
        {
            upPixmap.load(":/gfx/icon_switch_unpressed_38x38.svg");
            downPixmap.load(":/gfx/icon_switch_pressed_38x38.svg");
            break;
        }
        default:
        {
            return;
        }
        };

        // Scale it
        upPixmap = upPixmap.scaled(event->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        downPixmap
            = downPixmap.scaled(event->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
}

void ToolBarButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if (!downPixmap.isNull() && !upPixmap.isNull()) {
        if (pressed) {
            painter.drawPixmap(this->rect().topLeft(), downPixmap);
        }
        else {
            painter.drawPixmap(this->rect().topLeft(), upPixmap);
        }
    }
}

ToolBarButton::ButtonType ToolBarButton::btnType()
{
    return type;
}

void ToolBarButton::timerEvent(QTimerEvent *event)
{
    if (acceptMouseMoveTimer == event->timerId()) {
        acceptMouseMove = true;
        killTimer(acceptMouseMoveTimer);
        acceptMouseMoveTimer = -1;
    }
}

void ToolBarButton::mousePressEvent(QMouseEvent *event)
{
    acceptMouseMove = false;
    pressed = true;
    repaint();

    if (!isDialogButton() && type != ToolBarButton::EUndo && type != ToolBarButton::ENew) {
        // Send button pressed signal
        // For dialog buttons and undo/new signal is sended in mouseReleaseEvent 
        emit buttonPressed(type);
    }

    QWidget::mousePressEvent(event);

    // Start timer for accepting mouse move
    if (acceptMouseMoveTimer != -1) {
        killTimer(acceptMouseMoveTimer);
        acceptMouseMoveTimer = -1;
    }
    acceptMouseMoveTimer = startTimer(500);
}

void ToolBarButton::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    // If user has keeped mouse pressed 500ms we accept mouse move
    if (acceptMouseMove) {
        event->ignore(); // Move event goes to ToolBarWidget
    }
    else {
        event->accept(); // Event does not go to ToolBarWidget
    }
}

void ToolBarButton::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept(); // Event does not go to parent ToolBarWidget

    if (isToolButton()) {
        // Leave tool buttons pressed
    }
    else {
        // Lift other buttons back to up
        pressed = false;
        repaint();

        if (acceptMouseMove) {
            // User was only moving toolbar, do not open dialogs
            acceptMouseMove = false;
        }
        else {
            // Open dialogs
            // Send button pressed signal for dialog and undo/new buttons
            if (isDialogButton() || type == ToolBarButton::EUndo || type == ToolBarButton::ENew) {
                emit buttonPressed(type);
            }
        }
    }
}

/*****************************************************************************
 * ToolBarSizeButton
 */
ToolBarSizeButton::ToolBarSizeButton(QWidget *parent) :
    ToolBarButton(ToolBarButton::ESize, parent)
{
    pSize = MIN_PEN_SIZE;
}

ToolBarSizeButton::~ToolBarSizeButton()
{
}

int ToolBarSizeButton::penSize()
{
    return this->pSize;
}

void ToolBarSizeButton::setNextPenSize()
{
    if (pSize < MAX_PEN_SIZE) {
        pSize = pSize + PEN_APPEND_SIZE;
    }
    else {
        pSize = MIN_PEN_SIZE;
    }
}

void ToolBarSizeButton::loadSvg()
{
    upPixmap = 0;
    downPixmap = 0;

    if (pSize == MIN_PEN_SIZE) {
        upPixmap.load(":/gfx/icon_line_up_1st_selected_38x38.svg");
        downPixmap.load(":/gfx/icon_line_down_1st_selected_38x38.svg");
    }
    else if (pSize == MIN_PEN_SIZE + PEN_APPEND_SIZE) {
        upPixmap.load(":/gfx/icon_line_up_2nd_selected_38x38.svg");
        downPixmap.load(":/gfx/icon_line_down_2nd_selected_38x38.svg");
    }
    else {
        upPixmap.load(":/gfx/icon_line_up_3rd_selected_38x38.svg");
        downPixmap.load(":/gfx/icon_line_down_3rd_selected_38x38.svg");
    }

    if (!downPixmap.isNull() && !upPixmap.isNull()) {
        upPixmap = upPixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        downPixmap = downPixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }
}

void ToolBarSizeButton::resizeEvent(QResizeEvent *)
{
    loadSvg();
}

void ToolBarSizeButton::mousePressEvent(QMouseEvent *event)
{
    setNextPenSize();
    loadSvg();

    // Call base class implementation
    ToolBarButton::mousePressEvent(event);
}

/*****************************************************************************
 * ToolBarColorButton
 */
ToolBarColorButton::ToolBarColorButton(QWidget *parent) :
    ToolBarButton(ToolBarButton::EColor, parent)
{
    color = Qt::black;
    setColor(color);
}

ToolBarColorButton::~ToolBarColorButton()
{
}

void ToolBarColorButton::resizeEvent(QResizeEvent *event)
{
    ToolBarButton::resizeEvent(event);
    colorRect = QRect(QPoint(rect().width() * 0.4, rect().height() * 0.15), QSize(rect().width()
        * 0.40, rect().height() * 0.40));
}

void ToolBarColorButton::paintEvent(QPaintEvent *event)
{
    ToolBarButton::paintEvent(event);

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(colorRect);
}

void ToolBarColorButton::setColor(QColor& c)
{
    color = c;
    pen.setColor(Qt::gray);
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
}

QColor ToolBarColorButton::Color()
{
    return color;
}

