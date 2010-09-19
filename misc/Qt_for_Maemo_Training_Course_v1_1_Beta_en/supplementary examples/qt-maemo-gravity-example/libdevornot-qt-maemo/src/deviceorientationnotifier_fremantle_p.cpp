/*! \file deviceorientationnotifier_fremantle_p.cpp
 *  \brief DeviceOrientationNotifierPrivatePrivate class implementation.
 */

/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "deviceorientationnotifier_fremantle_p.h"
#include <QDebug>

DeviceOrientationNotifierPrivate::DeviceOrientationNotifierPrivate(DeviceOrientationNotifier *notifier, int interval)
{
  pubNotifier = notifier;
  startTimer(interval);
}

DeviceOrientationNotifierPrivate::~DeviceOrientationNotifierPrivate()
{
}

void DeviceOrientationNotifierPrivate::timerEvent(QTimerEvent *)
{
  QDBusMessage msg = QDBusMessage::createMethodCall(MCE_SERVICE, MCE_REQUEST_PATH, MCE_REQUEST_IF, MCE_DEVICE_ORIENTATION_GET);
  qDebug() << msg;
  bool sent = QDBusConnection::systemBus().callWithCallback(msg, this, SLOT(mceOrientationSlot(QString, QString, QString, int, int, int)));
  qDebug() << sent;
}

void DeviceOrientationNotifierPrivate::mceOrientationSlot(const QString &rotation, const QString &stand, const QString &face, int x, int y, int z)
{
  qDebug() << "Device orientation changed\nRotation: " << rotation << "\nFace: " << face << "\nStand: " << stand << "\n(" << x << ", " << y << ", " << z << ")";

  qreal pitch = atan2((qreal) x, (qreal) -y);
  qreal roll = atan2((qreal) y, (qreal) -z);
  qDebug() << "roll: " << roll * 180/M_PI << ", pitch" << pitch * 180/M_PI;

  emit pubNotifier->deviceOrientation(pitch, roll);
}
