/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#ifndef ToolBarWidget_h
#define ToolBarWidget_h

#include <QtGui>
#include "toolbarbutton.h"

// Toolbar size consts
#ifdef Q_OS_SYMBIAN
const int LandscapeToolbarHeight = 60;
const int LandscapeToolbarButtonHeight = 40;
const int PortraitToolbarWidth = 110;
const int PortraitToolbarButtonHeight = 40;
#else
const int LandscapeToolbarHeight = 65;
const int LandscapeToolbarButtonHeight = 45;
const int PortraitToolbarWidth = 120;
const int PortraitToolbarButtonHeight = 45;
#endif

#ifdef Q_WS_MAEMO_5
const int ButtonCount = 13;
#else
const int ButtonCount = 12;
#endif

const int LandscapeToolbarWidth = LandscapeToolbarButtonHeight * (ButtonCount+1);
const int PortraitToolbarHeight = (PortraitToolbarButtonHeight * (ButtonCount+1)) * 0.55;


class ToolBarWidget: public QWidget
{
Q_OBJECT

public:
    ToolBarWidget(QWidget *parent = 0);
    ~ToolBarWidget();

    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

    void createLandscapeLayout();
    void createPortraitLayout();
    void updateToolbarPos(QSize s, int posIndex, bool hide = false);

    void setDownButton(ToolBarButton::ButtonType);
    ToolBarButton::ButtonType downButton();

    int penSize();
    void setMainWidgetSize(QSize mainWidgetSize);
    void setColor(QColor&);

public slots:
    void buttonPressed(ToolBarButton::ButtonType);

    signals:
    void pressed(ToolBarButton::ButtonType);

private:
    QPoint mousePress;
    int xOffset;
    int yOffset;

    QPointer<QHBoxLayout> landscapeLayout;
    QPointer<QVBoxLayout> portraitLayout;

    ToolBarButton* b0;
    ToolBarButton* b1;
    ToolBarButton* b2;
    ToolBarButton* b3;
    ToolBarButton* b4;
    ToolBarButton* b5;
    ToolBarColorButton* b6;
    ToolBarButton* b7;
    ToolBarButton* b8;
    ToolBarSizeButton* b9;
    ToolBarButton* b10;
    ToolBarButton* b11;
    ToolBarButton* b12;

    ToolBarButton::ButtonType pressedButton;

    QPixmap landscapeBackground;
    QPixmap portraitBackground;

    QSize mainWidgetSize;
    bool allowDocking;
};

#endif // ToolBarWidget_h
