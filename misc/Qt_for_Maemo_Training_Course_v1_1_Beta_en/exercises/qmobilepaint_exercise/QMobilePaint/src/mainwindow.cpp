/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#include "mainwindow.h"
#include "widget.h"

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent,flags)
{
    w = new Widget(this);
    setCentralWidget(w);
}

MainWindow::~MainWindow()
{
}

void MainWindow::minimizeApplication()
{
    this->setWindowState(Qt::WindowMinimized);
}

