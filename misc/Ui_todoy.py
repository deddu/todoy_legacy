# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'todoy.ui'
#
# Created: Fri Aug  6 10:43:59 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 500)
        MainWindow.setStyleSheet("None")
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setMaximumSize(QtCore.QSize(850, 450))
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(10, -20, 781, 471))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setSizeConstraint(QtGui.QLayout.SetMinAndMaxSize)
        self.verticalLayout.setObjectName("verticalLayout")
        self.graphicsView = QtGui.QGraphicsView(self.verticalLayoutWidget)
        self.graphicsView.setProperty("cursor", QtCore.Qt.ArrowCursor)
        self.graphicsView.setStyleSheet("background-image: url(:/bkgrnd/todoy_bkgrnd.png);")
        self.graphicsView.setObjectName("graphicsView")
        self.verticalLayout.addWidget(self.graphicsView)
        self.dateEdit = QtGui.QDateEdit(self.verticalLayoutWidget)
        self.dateEdit.setCalendarPopup(True)
        self.dateEdit.setCurrentSectionIndex(0)
        self.dateEdit.setObjectName("dateEdit")
        self.verticalLayout.addWidget(self.dateEdit)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 23))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
        self.dateEdit.setDisplayFormat(QtGui.QApplication.translate("MainWindow", "dd/MM/yyyy", None, QtGui.QApplication.UnicodeUTF8))

import todoy_rc
