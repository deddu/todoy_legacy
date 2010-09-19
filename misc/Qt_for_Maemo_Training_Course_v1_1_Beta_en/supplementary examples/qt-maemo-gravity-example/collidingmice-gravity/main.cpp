/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Qt Software Information (qt-info@nokia.com)
**
** This file is part of the example classes of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial Usage
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Nokia.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at qt-sales@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mouse.h"
#include <QtGui>

#include <QGraphicsView>
#include <math.h>

#include <libdevornot-qt-maemo/deviceorientationnotifier.h>
#include "scenetuner.h"
#include "myapplication.h"

static const int MouseCount = 7;
static const int TimerInterval = 1000 / 33;


int main(int argc, char **argv)
{
    MyApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    QGraphicsScene scene;
    scene.setSceneRect(-300, -300, 600, 600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i < MouseCount; ++i) {
        Mouse *mouse = new Mouse;
        mouse->setPos(::sin((i * 6.28) / MouseCount) * 200,
                      ::cos((i * 6.28) / MouseCount) * 200);
        scene.addItem(mouse);
    }

    app.view.setScene(&scene);
    app.view.setRenderHint(QPainter::Antialiasing);
    app.view.setBackgroundBrush(QPixmap(":/images/cheese.jpg"));
    app.view.setCacheMode(QGraphicsView::CacheBackground);
    app.view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    app.view.setDragMode(QGraphicsView::ScrollHandDrag);
    app.view.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Colliding Mice Gravity Example"));
    app.view.resize(400, 300);
    app.view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.start(TimerInterval);

    // Device orientation support
    DeviceOrientationNotifier notifier(100);
    SceneTuner tuner(&scene, TimerInterval);
    QObject::connect(&notifier, SIGNAL(deviceOrientation(qreal, qreal)), &tuner, SLOT(setProps(qreal, qreal)));
    
    // A few special hardware keys
    app.keyHandler()->grabIncreaseDecreaseKeys(&app.view, true);
    
    QObject::connect(app.keyHandler(), SIGNAL(decreaseKeyPressed()), &app, SLOT(decreaseKeyPressed()));
    QObject::connect(app.keyHandler(), SIGNAL(increaseKeyPressed()), &app, SLOT(increaseKeyPressed()));
    QObject::connect(app.keyHandler(), SIGNAL(powerKeyPressed()), &app, SLOT(quit()));
    QObject::connect(app.keyHandler(), SIGNAL(keyboardSliderMoved(bool)), &app, SLOT(quit()));
    return app.exec();
}
