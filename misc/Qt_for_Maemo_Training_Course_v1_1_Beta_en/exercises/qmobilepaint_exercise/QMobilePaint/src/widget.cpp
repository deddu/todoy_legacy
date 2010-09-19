/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#include "widget.h"
#include "toolbarwidget.h"
#include <QDebug>
#include <QApplication>
// EXERCISE DBUS: What needs to be added when using D-Bus?


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    animToolbarTimerId = -1;
    startToolbarAnimationTimerId = -1;
    p1 = QPoint(-1, -1);
    p2 = QPoint(-1, -1);

    // Create default pens
    color = QColor(Qt::black);
    pen.setColor(color);
    pen.setStyle(Qt::SolidLine);
    draftPen.setColor(Qt::black);
    draftPen.setStyle(Qt::DashLine);
    draftPen.setWidth(1);

    // Create custom toolbar
    toolbar = new ToolBarWidget(this);
    toolbar->setDownButton(ToolBarButton::EPen);
    pen.setWidth(toolbar->penSize());
    QObject::connect(toolbar, SIGNAL(pressed(ToolBarButton::ButtonType)),this, SLOT(pressed(ToolBarButton::ButtonType)));
}

Widget::~Widget()
{
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    toolbar->setVisible(false);
    repaint();

    p1 = event->pos();
    p2 = QPoint(-1, -1);

    // Save current image for undo
    saveForUndo();

    // Opaque paint when using EPen. We paint only dirty area of the screen
    if (toolbar->downButton() == ToolBarButton::EPen)
        setAttribute(Qt::WA_OpaquePaintEvent, true);

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (toolbar->downButton() == ToolBarButton::EPen || toolbar->downButton()
        == ToolBarButton::EErase) {
        // Pen is drawed direct to pixmap in mouseMoveEvent
        if (p2.x() == -1) {
            p2 = event->pos();
        }
        else {
            p1 = p2;
            p2 = event->pos();
        }
        // Paint to pixmap and then pixmap on screen
        paintToPixmap();
    }
    else {
        // Other tools are drawed on pixmap in mouseReleaseEvent
        // Draw ongoing drawing
        p2 = event->pos();
        // Update screen
        update();
    }

}

void Widget::mouseReleaseEvent(QMouseEvent *)
{
    // Stop using opaque paint
    if (toolbar->downButton() == ToolBarButton::EPen)
        setAttribute(Qt::WA_OpaquePaintEvent, false);

    // Drawing finished. Update pixmap (paper)
    // Paint to pixmap and then pixmap on screen
    paintToPixmap();

    p1 = QPoint(-1, -1);
    p2 = QPoint(-1, -1);
    toolbar->setVisible(true);
    repaint();
}

void Widget::colorSelected(const QColor& c)
{
    // Store selected color
    if (c.isValid()) {
        color = c;
        pen.setColor(color);
        toolbar->setColor(color);
    }
}

void Widget::pressed(ToolBarButton::ButtonType type)
{
    // Toolbar button pressed

    switch (type) {
    case ToolBarButton::ENew:
    {
        if (!messageBox) {
            messageBox = new QMessageBox(this);
            int ret = messageBox->question(this, "QMobilePaint", "Clear screen?", QMessageBox::Yes
                | QMessageBox::No);
            delete messageBox;
            messageBox = 0;
            if (ret == QMessageBox::Yes) {
                saveForUndo();
                pixmap.fill(Qt::white);
                update();
            }
        }
        break;
    }
    case ToolBarButton::EUndo:
    {
        undo();
        break;
    }
    case ToolBarButton::ESave:
    {
		// EXERCISE STORAGELOC:	How would you change this code for saving a file?
		
        // Ask filename from the user
#ifdef Q_WS_MAEMO_5
        QString filename = QFileDialog::getSaveFileName(this, "Save picture",
            QDir::home().path());
#else
        QString filename = QFileDialog::getSaveFileName(this, "Save picture",
            QDesktopServices::storageLocation(QDesktopServices::PicturesLocation));
#endif

        if (!filename.isEmpty()) {
            // Set filename extension to .png
            int i = filename.indexOf(".");
            if (i > 0) {
                filename.remove(i, filename.length() - i);
                filename.append(".png");
            }
            else {
                filename.append(".png");
            }
            // Save .png image
            pixmap.save(filename);
        }
        break;
    }
    case ToolBarButton::EOpen:
    {
		// EXERCISE STORAGELOC:	How would you change this code for opening a file?
		
        // Open file, let user select the file
#ifdef Q_WS_MAEMO_5
        QString filename = QFileDialog::getOpenFileName(this, "Open picture",
            QDir::home().path(),
            "Images (*.png *.jpg)");
#else
        QString filename = QFileDialog::getOpenFileName(this, "Open picture",
            QDesktopServices::storageLocation(QDesktopServices::PicturesLocation),
            "Images (*.png *.jpg)");
#endif

        if (!filename.isEmpty()) {
            // Load image by QImageReader
            QImageReader reader;
            reader.setFileName(filename);
            // Scale image to fit into screen
            QSize imageSize = reader.size();
            QSize screenSize = size();
            imageSize.scale(screenSize, Qt::KeepAspectRatio);
            reader.setScaledSize(imageSize);
            // Free memory before reading new image
            undoPixmap = 0;
            // Read image
            QImage image = reader.read();
            // QImage to QPixmap
            QPixmap newPixmap = QPixmap::fromImage(image);
            // Draw loaded image on top of screen
            QPainter painter(&pixmap);
            painter.drawPixmap((size().width() - imageSize.width()) / 2, (size().height()
                - imageSize.height()) / 2, newPixmap);
            painter.end();
            newPixmap = 0;
            update();
        }
        break;
    }
    case ToolBarButton::EExit:
    {
        if (!messageBox) {
            messageBox = new QMessageBox(this);
            int ret = messageBox->question(this, "QMobilePaint", "Exit from application?",
                QMessageBox::Yes | QMessageBox::No);
            delete messageBox;
            messageBox = 0;
            if (ret == QMessageBox::Yes) {
                QApplication::exit(0);
            }
        }
        break;
    }
    case ToolBarButton::EColor:
    {
#ifdef Q_OS_SYMBIAN
        if (!colorDialog) {
            colorDialog = new QColorDialog(color, this);
        }
        colorDialog->setGeometry(rect());
        colorDialog->open(this, SLOT(colorSelected(const QColor)));
#else
        QColor newColor = QColorDialog::getColor(color, this);
        if (newColor.isValid()) {
            color = newColor;
            pen.setColor(color);
            toolbar->setColor(color);
        }
#endif
        break;
    }
    case ToolBarButton::ESize:
    {
        pen.setWidth(toolbar->penSize());
        break;
    }
    case ToolBarButton::EMinimize:
    {
	// EXERCISE DBUS:
	// Here you should implement support for minimizing the application with the help of D-Bus!
        break;
    }
    default:
    {
        break;
    }
    };
}

void Widget::saveForUndo()
{
    undoPixmap = 0;
    // Copy current image for undo
    undoPixmap = pixmap.copy();
}

void Widget::undo()
{
    // Take stored previous image in use
    if (!undoPixmap.isNull()) {
        pixmap = undoPixmap.copy();
        undoPixmap = 0;
        // Update screen
        update();
    }
}

void Widget::paintToPixmap()
{
    // Paint to pixmap (paper)
    QPainter painter;
    painter.begin(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(pen);

    if (toolbar->downButton() == ToolBarButton::EPen || toolbar->downButton()
        == ToolBarButton::ELine)
        paintLine(painter);
    else if (toolbar->downButton() == ToolBarButton::EErase)
        paintPoint(painter);
    else if (toolbar->downButton() == ToolBarButton::ERectangle)
        paintRect(painter);
    else if (toolbar->downButton() == ToolBarButton::ECircle)
        paintCircle(painter);

    painter.end();
    // Draw pixmap on the screen
    update();
}

void Widget::startToolbarAnimation()
{
    if (animToolbarTimerId != -1) {
        killTimer(animToolbarTimerId);
        animToolbarTimerId = -1;
    }

    animFrame = 0;
    animationStep = 4;
    animEndFrame = (toolbar->height() * 3 - 10) / animationStep;
    animDirectionFrame = toolbar->height() * 2 / animationStep;

    // Start animation timer
    animToolbarTimerId = startTimer(0);
}

void Widget::timerEvent(QTimerEvent *event)
{
    // Handle different timer events
    if (event->timerId() == startToolbarAnimationTimerId) {
        killTimer(startToolbarAnimationTimerId);
        //startToolbarAnimationTimerId = -1;
        startToolbarAnimation();
    }
    else if (event->timerId() == animToolbarTimerId) {
        toolbarAnimation();
        if (animFrame >= animEndFrame) {
            killTimer(animToolbarTimerId);
            animToolbarTimerId = -1;
        }
    }
}

void Widget::toolbarAnimation()
{
    animFrame++;
#ifdef Q_OS_SYMBIAN
    int direction = -1;
    if (animFrame > animDirectionFrame) {
        direction = 1;
    }
#else
    int direction = 1;
    if (animFrame> animDirectionFrame) {
        direction = -1;
    }
#endif    
    int pos = toolbar->pos().y();
    // Move toolbar
    toolbar->move(toolbar->pos().x(), pos + animationStep * direction);
}

void Widget::resizeEvent(QResizeEvent *event)
{
    // Set QPixmap (paper) size and update toolbar size/position
    QWidget::resizeEvent(event);

#ifdef Q_WS_MAEMO_5
    if (event->size().height()<150) {
        return;
    }
#endif    

    toolbar->setMainWidgetSize(size());

    // Set toolbar size and pos
#ifdef Q_OS_SYMBIAN
    toolbar->updateToolbarPos(size(), 1, true);
#else
    bool hide = true;
    if (startToolbarAnimationTimerId != -1) {
        hide = false;
    }
    toolbar->updateToolbarPos(size(), 2,hide);
#endif
    pixmap = QPixmap(event->size());
    pixmap.fill(Qt::white);

    // Animate toolbar to visible animation AFTER 1000ms
    if (startToolbarAnimationTimerId == -1)
        startToolbarAnimationTimerId = startTimer(1000);
}

void Widget::paintLine(QPainter& painter)
{
    if (p1.x() != -1 && p2.x() != -1) {
        painter.drawLine(p1, p2);
    }
}

void Widget::paintPoint(QPainter& painter)
{
    if (p1.x() != -1) {
        QPoint p = p1;
        p.setX(p.x() - 5);
        p.setY(p.y() - 5);
        painter.fillRect(QRect(p, QSize(10, 10)), Qt::white);
    }
}

void Widget::paintRect(QPainter& painter)
{
    if (p2.x() != -1) {
        int w = (p2.x() - p1.x()) * 1;
        int h = (p2.y() - p1.y()) * 1;
        painter.drawRect(p1.x(), p1.y(), w, h);
    }
}

void Widget::paintCircle(QPainter& painter)
{
    if (p2.x() != -1) {
        int w = (p2.x() - p1.x()) * 1;
        int h = (p2.y() - p1.y()) * 1;
        QPoint c = QPoint(p1.x() + w / 2, p1.y() + h / 2);
        painter.drawEllipse(c, w, h);
    }
}

QRect Widget::dirtyRect()
{
    int left, top, width, height;

    if (p1.x() == -1 || p2.x() == -1) {
        return rect();
    }

    if (p1.x() < p2.x()) {
        left = p1.x();
        width = p2.x() - p1.x();
    }
    else {
        left = p2.x();
        width = p1.x() - p2.x();
    }

    if (p1.y() < p2.y()) {
        top = p1.y();
        height = p2.y() - p1.y();
    }
    else {
        top = p2.y();
        height = p1.y() - p2.y();
    }
    return QRect(left - 15, top - 15, width + 30, height + 30);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Paint only dirty area of the screen
    if (testAttribute(Qt::WA_OpaquePaintEvent)) {
        painter.setClipRegion(dirtyRect());
    }

    // Update pixmap into screen (screen background)
    // If QPainter::setClipRegion() is set this updates
    // only this wanted rectangle
    painter.drawPixmap(QPoint(0, 0), pixmap);

    // Draw ongoing drawing on top of pixmap
    if (toolbar->downButton() != ToolBarButton::EPen) {
        painter.setPen(draftPen); // ongoing drawing, not final (waiting for mouseRelease)
        if (toolbar->downButton() == ToolBarButton::ELine)
            paintLine(painter);
        else if (toolbar->downButton() == ToolBarButton::ERectangle)
            paintRect(painter);
        else if (toolbar->downButton() == ToolBarButton::ECircle)
            paintCircle(painter);
    }
}

