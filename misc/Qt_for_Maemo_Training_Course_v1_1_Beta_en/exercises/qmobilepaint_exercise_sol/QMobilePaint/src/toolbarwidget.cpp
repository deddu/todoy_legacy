/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#include "toolbarwidget.h"
#include "toolbarbutton.h"
#include <QDebug>

ToolBarWidget::ToolBarWidget(QWidget *parent) :
    QWidget(parent)
{
    portraitBackground = 0;
    landscapeBackground = 0;

    // Create buttons
    b0 = new ToolBarButton(ToolBarButton::ENew, this);
    b1 = new ToolBarButton(ToolBarButton::EPen, this);
    b2 = new ToolBarButton(ToolBarButton::ELine, this);
    b3 = new ToolBarButton(ToolBarButton::ERectangle, this);
    b4 = new ToolBarButton(ToolBarButton::ECircle, this);
    b5 = new ToolBarButton(ToolBarButton::EUndo, this);
    b6 = new ToolBarColorButton(this);
    b7 = new ToolBarButton(ToolBarButton::ESave, this);
    b8 = new ToolBarButton(ToolBarButton::EExit, this);
    b9 = new ToolBarSizeButton(this);
    b10 = new ToolBarButton(ToolBarButton::EOpen, this);
    b11 = new ToolBarButton(ToolBarButton::EErase, this);
#ifdef Q_WS_MAEMO_5
    b12 = new ToolBarButton(ToolBarButton::EMinimize, this);
#endif    

    // Listen general button pressed
    QObject::connect(b0, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b1, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b2, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b3, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b4, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b5, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b6, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b7, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b8, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b9, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b10, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
    QObject::connect(b11, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
#ifdef Q_WS_MAEMO_5
    QObject::connect(b12, SIGNAL(buttonPressed(ToolBarButton::ButtonType)),this, SLOT(buttonPressed(ToolBarButton::ButtonType)));
#endif
    
    // Listen button pressed signal for these that have to rise up when other are down
    QObject::connect(this, SIGNAL(pressed(ToolBarButton::ButtonType)),b1, SLOT(someButtonPressed(ToolBarButton::ButtonType)));
    QObject::connect(this, SIGNAL(pressed(ToolBarButton::ButtonType)),b2, SLOT(someButtonPressed(ToolBarButton::ButtonType)));
    QObject::connect(this, SIGNAL(pressed(ToolBarButton::ButtonType)),b3, SLOT(someButtonPressed(ToolBarButton::ButtonType)));
    QObject::connect(this, SIGNAL(pressed(ToolBarButton::ButtonType)),b4, SLOT(someButtonPressed(ToolBarButton::ButtonType)));
    QObject::connect(this, SIGNAL(pressed(ToolBarButton::ButtonType)),b11, SLOT(someButtonPressed(ToolBarButton::ButtonType)));

    allowDocking = false;
}

void ToolBarWidget::setDownButton(ToolBarButton::ButtonType type)
{
    // Pressed down (all the time) only for these buttons
    switch (type) {
    case ToolBarButton::EPen:
    {
        b1->setPressed(true);
        pressedButton = type;
        break;
    }
    case ToolBarButton::ELine:
    {
        b2->setPressed(true);
        pressedButton = type;
        break;
    }
    case ToolBarButton::ERectangle:
    {
        b3->setPressed(true);
        pressedButton = type;
        break;
    }
    case ToolBarButton::ECircle:
    {
        b4->setPressed(true);
        pressedButton = type;
        break;
    }
    case ToolBarButton::EErase:
    {
        b11->setPressed(true);
        pressedButton = type;
        break;
    }
    default:
    {
        break;
    }
    };
}

void ToolBarWidget::setColor(QColor& c)
{
    b6->setColor(c);
    b6->update();
}

ToolBarButton::ButtonType ToolBarWidget::downButton()
{
    return pressedButton;
}

int ToolBarWidget::penSize()
{
    return b9->penSize();
}

void ToolBarWidget::updateToolbarPos(QSize s, int posIndex, bool hide)
{
    /* posIndex:
     * 1 = bottom
     * 2 = top
     * 3 = left
     * 4 = right
     */

    if (posIndex == 1) {
        // to TOP
        createLandscapeLayout();
        if (hide) {
            setGeometry((s.width() - LandscapeToolbarWidth) / 2, s.height(), LandscapeToolbarWidth,
                LandscapeToolbarHeight);
        }
        else {
            setGeometry((s.width() - LandscapeToolbarWidth) / 2, s.height()
                - LandscapeToolbarHeight - 10, LandscapeToolbarWidth, LandscapeToolbarHeight);
        }
    }
    else if (posIndex == 2) {
        // to BOTTOM
        createLandscapeLayout();
        if (hide) {
            setGeometry((s.width() - LandscapeToolbarWidth) / 2, LandscapeToolbarHeight * -1,
                LandscapeToolbarWidth, LandscapeToolbarHeight);
        }
        else {
            setGeometry((s.width() - LandscapeToolbarWidth) / 2, 10, LandscapeToolbarWidth,
                LandscapeToolbarHeight);
        }
    }
    else if (posIndex == 3) {
        // to LEFT
        createPortraitLayout();
        setGeometry(10, (s.height() - PortraitToolbarHeight) / 2, PortraitToolbarWidth,
            PortraitToolbarHeight);
    }
    else if (posIndex == 4) {
        // to RIGHT
        createPortraitLayout();
        setGeometry(s.width() - PortraitToolbarWidth - 10,
            (s.height() - PortraitToolbarHeight) / 2, PortraitToolbarWidth, PortraitToolbarHeight);
    }
}

void ToolBarWidget::createPortraitLayout()
{
    // Clean previous layout
    if (landscapeLayout) {
        for (int i = 0; i < landscapeLayout->count(); i++) {
            landscapeLayout->removeItem(landscapeLayout->itemAt(i));
        }
        delete landscapeLayout;
        landscapeLayout = 0;
    }

    // Create new one
    if (!portraitLayout) {
        portraitLayout = new QVBoxLayout(this);
        portraitLayout->setSpacing(2);
        // int left, int top, int right, int bottom
        portraitLayout->setContentsMargins(2, 6, 2, 6);

#ifndef Q_WS_HILDON 
        QHBoxLayout* l = new QHBoxLayout();
        l->addWidget(b0);
        l->setAlignment(b0, Qt::AlignCenter);
        l->addWidget(b1);
        l->setAlignment(b1, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b2);
        l->setAlignment(b2, Qt::AlignCenter);
        l->addWidget(b3);
        l->setAlignment(b3, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b4);
        l->setAlignment(b4, Qt::AlignCenter);
        l->addWidget(b11);
        l->setAlignment(b11, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b9);
        l->setAlignment(b9, Qt::AlignCenter);
        l->addWidget(b5);
        l->setAlignment(b5, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b6);
        l->setAlignment(b6, Qt::AlignCenter);
        l->addWidget(b7);
        l->setAlignment(b7, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b10);
        l->setAlignment(b10, Qt::AlignCenter);
        l->addWidget(b8);
        l->setAlignment(b8, Qt::AlignCenter);
        portraitLayout->addLayout(l);
#else
        QHBoxLayout* l = new QHBoxLayout();
        l->addWidget(b12);
        l->setAlignment(b12, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b0);
        l->setAlignment(b0, Qt::AlignCenter);
        l->addWidget(b1);
        l->setAlignment(b1, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b2);
        l->setAlignment(b2, Qt::AlignCenter);
        l->addWidget(b3);
        l->setAlignment(b3, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b4);
        l->setAlignment(b4, Qt::AlignCenter);
        l->addWidget(b11);
        l->setAlignment(b11, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b9);
        l->setAlignment(b9, Qt::AlignCenter);
        l->addWidget(b5);
        l->setAlignment(b5, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b6);
        l->setAlignment(b6, Qt::AlignCenter);
        l->addWidget(b7);
        l->setAlignment(b7, Qt::AlignCenter);
        portraitLayout->addLayout(l);

        l = new QHBoxLayout();
        l->addWidget(b10);
        l->setAlignment(b10, Qt::AlignCenter);
        l->addWidget(b8);
        l->setAlignment(b8, Qt::AlignCenter);
        portraitLayout->addLayout(l);
#endif
        
        setLayout(portraitLayout);
    }
    if (portraitBackground.isNull()) {
        landscapeBackground = 0;
        portraitBackground.load(":/gfx/graf_bar_portrait_fat.svg");
    }
}

void ToolBarWidget::createLandscapeLayout()
{
    // Clean previous layout
    if (portraitLayout) {
        for (int i = 0; i < portraitLayout->count(); i++) {
            portraitLayout->removeItem(portraitLayout->itemAt(i));
        }
        delete portraitLayout;
        portraitLayout = 0;
    }

    // Create new one
    if (!landscapeLayout) {
        landscapeLayout = new QHBoxLayout(this);
        landscapeLayout->setSpacing(2);
        // int left, int top, int right, int bottom
        landscapeLayout->setContentsMargins(2, 6, 2, 6);

#ifdef Q_WS_MAEMO_5
        landscapeLayout->addWidget(b12);
        landscapeLayout->setAlignment(b12, Qt::AlignCenter);
#endif   
        landscapeLayout->addWidget(b0);
        landscapeLayout->setAlignment(b0, Qt::AlignCenter);
        landscapeLayout->addWidget(b1);
        landscapeLayout->setAlignment(b1, Qt::AlignCenter);
        landscapeLayout->addWidget(b2);
        landscapeLayout->setAlignment(b2, Qt::AlignCenter);
        landscapeLayout->addWidget(b3);
        landscapeLayout->setAlignment(b3, Qt::AlignCenter);
        landscapeLayout->addWidget(b4);
        landscapeLayout->setAlignment(b4, Qt::AlignCenter);
        landscapeLayout->addWidget(b11);
        landscapeLayout->setAlignment(b11, Qt::AlignCenter);
        landscapeLayout->addWidget(b9);
        landscapeLayout->setAlignment(b9, Qt::AlignCenter);
        landscapeLayout->addWidget(b5);
        landscapeLayout->setAlignment(b5, Qt::AlignCenter);
        landscapeLayout->addWidget(b6);
        landscapeLayout->setAlignment(b6, Qt::AlignCenter);
        landscapeLayout->addWidget(b7);
        landscapeLayout->setAlignment(b7, Qt::AlignCenter);
        landscapeLayout->addWidget(b10);
        landscapeLayout->setAlignment(b10, Qt::AlignCenter);
        landscapeLayout->addWidget(b8);
        landscapeLayout->setAlignment(b8, Qt::AlignCenter);

        setLayout(landscapeLayout);
    }
    if (landscapeBackground.isNull()) {
        portraitBackground = 0;
        landscapeBackground.load(":/gfx/graf_bar_wide_landscape.svg");
    }
}

void ToolBarWidget::buttonPressed(ToolBarButton::ButtonType type)
{
    setDownButton(type);
    emit pressed(type);
}

ToolBarWidget::~ToolBarWidget()
{
}

void ToolBarWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    if (!landscapeBackground.isNull()) {
        landscapeBackground = landscapeBackground.scaled(size(), Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation);

        // Set background as a transparent
        QPixmap transparent(landscapeBackground.size());
        transparent.fill(Qt::transparent);
        QPainter p(&transparent);
        p.setCompositionMode(QPainter::CompositionMode_Source);
        p.drawPixmap(0, 0, landscapeBackground);
        p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        p.fillRect(transparent.rect(), QColor(0, 0, 0, 150));
        p.end();
        landscapeBackground = transparent;
    }
    else if (!portraitBackground.isNull()) {
        portraitBackground = portraitBackground.scaled(size(), Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation);

        // Set background as a transparent
        QPixmap transparent(portraitBackground.size());
        transparent.fill(Qt::transparent);
        QPainter p(&transparent);
        p.setCompositionMode(QPainter::CompositionMode_Source);
        p.drawPixmap(0, 0, portraitBackground);
        p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
        p.fillRect(transparent.rect(), QColor(0, 0, 0, 150));
        p.end();
        portraitBackground = transparent;
    }
}

void ToolBarWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    // Background for the toolbar
    if (!landscapeBackground.isNull())
        painter.drawPixmap(rect().topLeft(), landscapeBackground);
    else if (!portraitBackground.isNull())
        painter.drawPixmap(rect().topLeft(), portraitBackground);
}

void ToolBarWidget::mousePressEvent(QMouseEvent *event)
{
    event->accept(); // NOTE: Event does not go to main widget to do painting
    mousePress = mapToParent(event->pos());
    xOffset = mousePress.x() - pos().x();
    yOffset = mousePress.y() - pos().y();
    allowDocking = true;
}

void ToolBarWidget::setMainWidgetSize(QSize mainWidgetSize)
{
    this->mainWidgetSize = mainWidgetSize;
}

void ToolBarWidget::mouseMoveEvent(QMouseEvent *event)
{
    event->accept(); // NOTE: Event does not go to main widget to do painting

    if (allowDocking) {
        QPoint p = this->mapToParent(event->pos());
        p.setX(p.x() - xOffset);
        p.setY(p.y() - yOffset);
        setGeometry(QRect(p, size()));

        QRect r = geometry();
        if (r.topLeft().y() < 5) {
            // to Top
            updateToolbarPos(mainWidgetSize, 2);
            allowDocking = false;
        }
        else if (r.bottomRight().y() > mainWidgetSize.height() - 5) {
            // to Bottom
            updateToolbarPos(mainWidgetSize, 1);
            allowDocking = false;
        }
        else if (r.topLeft().x() < 5) {
            // to Left
            updateToolbarPos(mainWidgetSize, 3);
            allowDocking = false;
        }
        else if (r.bottomRight().x() > mainWidgetSize.width() - 5) {
            // to Right
            updateToolbarPos(mainWidgetSize, 4);
            allowDocking = false;
        }
    }
}

void ToolBarWidget::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept(); // NOTE: Event does not go to main widget to do painting
    allowDocking = true;
}
