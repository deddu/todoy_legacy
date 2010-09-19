/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class Widget;
class MainWindow: public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~MainWindow();

public slots:
    void minimizeApplication();
    

private:
    Widget* w;
};

#endif // MAINWINDOW_H
