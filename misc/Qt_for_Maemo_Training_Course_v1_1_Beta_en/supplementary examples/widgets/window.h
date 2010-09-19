/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>


class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    virtual ~Window();

protected slots:
    void orientationChanged(QString, QString, QString, int, int, int);
    void toggleLandscape(bool);
    void toggleFullScreen(bool);
    void enableChildren(bool);

protected:
    void showEvent(QShowEvent *e);
    void hideEvent(QHideEvent *e);

    virtual void relayout();

    QAction *m_fullscreen;
    QAction *m_landscape;
    QAction *m_portrait;
    QAction *m_enable_children;
    QAction *m_disable_children;
};

class MainWindow : public Window
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void showWidgets1();
    void showWidgets2();
    void showWidgets3();
    void showWidgets4();

    void showMessageBox();
    void showBanner();
    void showNote();
    void showComplexNote();
    void showExpose();
    void beBusy(bool);

protected:
    void relayout();
};

class WidgetWindow : public Window
{
    Q_OBJECT

public:
    WidgetWindow(int page, MainWindow *parent);
};

class ListWindow : public Window
{
    Q_OBJECT

public:
    ListWindow(MainWindow *parent);

private slots:
    void actionClicked();
};

#endif
