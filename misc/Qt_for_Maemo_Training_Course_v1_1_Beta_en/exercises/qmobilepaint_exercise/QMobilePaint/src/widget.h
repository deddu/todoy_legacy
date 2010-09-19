/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include "toolbarbutton.h"

class ToolBarWidget;

class Widget: public QWidget
{
Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void timerEvent(QTimerEvent *);

public slots:
    void pressed(ToolBarButton::ButtonType);
    void colorSelected(const QColor&);

private:
    void paintToPixmap();
    void paintLine(QPainter&);
    void paintRect(QPainter&);
    void paintCircle(QPainter&);
    void paintPoint(QPainter&);

    void saveForUndo();
    void undo();

    void startToolbarAnimation();
    void toolbarAnimation();
    QRect dirtyRect();

private:
    QPoint p1;
    QPoint p2;

    QPixmap pixmap;
    QPixmap undoPixmap;

    QSize screenSize;

    QPen pen;
    QPen draftPen;
    QColor color;

    QPointer<QColorDialog> colorDialog;
    QPointer<QMessageBox> messageBox;

    ToolBarWidget* toolbar;

    int startToolbarAnimationTimerId;
    int animToolbarTimerId;
    int animDirectionFrame;
    int animEndFrame;
    int animFrame;
    int animationStep;
};

#endif // WIDGET_H
