/*! \file deviceorientationnotifierprivate_fremantle_p.h
 *  \brief DeviceOrientationNotifierPrivate class declaration.
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

#ifndef DeviceOrientationNotifierPrivate_H
#define DeviceOrientationNotifierPrivate_H

#include <QObject>

// Device orientation support
#include <QtDBus>
#include <mce/mode-names.h>
#include <mce/dbus-names.h>

#include "deviceorientationnotifier.h"

//! %DeviceOrientationNotifierPrivate informs about device pitch and roll.
/*!
  In order to calculate pitch and roll, it requests device orientation
  through mce dbus interface.
 */
class DeviceOrientationNotifierPrivate : public QObject
{
  Q_OBJECT

  public:
    //! Constructor. Starts timer for orientation method calls.
    /*!
      \param interval timeout interval in milliseconds
     */
    DeviceOrientationNotifierPrivate(DeviceOrientationNotifier* pubNotifier, int interval);

    //! Destructor.
    ~DeviceOrientationNotifierPrivate();

  private: 
    DeviceOrientationNotifier *pubNotifier;

  private slots:
    //! Callback for orientation method calls, that calculates pitch and roll.
    /*!
      \sa DeviceOrientationNotifier::deviceOrientation()
    */
    void mceOrientationSlot(const QString &rotation, const QString &stand, const QString &face, int x, int y, int z);

  protected:
    //! Requests device orientation through mce dbus interface.
    /*!
      \sa mceOrientationSlot()
    */
    void timerEvent(QTimerEvent *event);
};

#endif
