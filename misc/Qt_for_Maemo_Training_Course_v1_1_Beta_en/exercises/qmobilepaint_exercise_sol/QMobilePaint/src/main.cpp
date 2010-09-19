/*
 * Copyright (c) 2009 Nokia Corporation.
 */

#include <QtGui/QApplication>
#include "mainwindow.h"

// Lock S60 orientation
#ifdef Q_OS_SYMBIAN
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    // Lock S60 orientation
#ifdef Q_OS_SYMBIAN
    CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
    TRAPD(error, 
    if (appUi) {
        appUi->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
    }
    );
#endif
   
    w.showFullScreen();

    return a.exec();
}
