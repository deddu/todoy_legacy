# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'another_4.ui'
#
# Created: Sun Oct  3 10:03:15 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 437)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setMinimumSize(QtCore.QSize(0, 400))
        self.centralwidget.setObjectName("centralwidget")
        self.graphicsView = QtGui.QGraphicsView(self.centralwidget)
        self.graphicsView.setEnabled(False)
        self.graphicsView.setGeometry(QtCore.QRect(0, 0, 800, 350))
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.graphicsView.sizePolicy().hasHeightForWidth())
        self.graphicsView.setSizePolicy(sizePolicy)
        self.graphicsView.setMinimumSize(QtCore.QSize(800, 350))
        self.graphicsView.setMaximumSize(QtCore.QSize(800, 350))
        self.graphicsView.setObjectName("graphicsView")
        self.stackedWidget = QtGui.QStackedWidget(self.centralwidget)
        self.stackedWidget.setGeometry(QtCore.QRect(9, 350, 782, 50))
        self.stackedWidget.setMinimumSize(QtCore.QSize(0, 50))
        self.stackedWidget.setObjectName("stackedWidget")
        self.page_3 = QtGui.QWidget()
        self.page_3.setObjectName("page_3")
        self.widget = QtGui.QWidget(self.page_3)
        self.widget.setGeometry(QtCore.QRect(0, 0, 782, 61))
        self.widget.setObjectName("widget")
        self.horizontalLayout = QtGui.QHBoxLayout(self.widget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.horizontalLayout_7 = QtGui.QHBoxLayout()
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.toolButton = QtGui.QToolButton(self.widget)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/no/sketch_freedraw.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton.setIcon(icon)
        self.toolButton.setObjectName("toolButton")
        self.horizontalLayout_7.addWidget(self.toolButton)
        self.line_2 = QtGui.QFrame(self.widget)
        self.line_2.setFrameShape(QtGui.QFrame.VLine)
        self.line_2.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.horizontalLayout_7.addWidget(self.line_2)
        self.toolButton_color = QtGui.QToolButton(self.widget)
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap(":/no/control_personalization.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton_color.setIcon(icon1)
        self.toolButton_color.setObjectName("toolButton_color")
        self.horizontalLayout_7.addWidget(self.toolButton_color)
        self.toolButton_undo = QtGui.QToolButton(self.widget)
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap(":/no/general_undo.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton_undo.setIcon(icon2)
        self.toolButton_undo.setObjectName("toolButton_undo")
        self.horizontalLayout_7.addWidget(self.toolButton_undo)
        self.line = QtGui.QFrame(self.widget)
        self.line.setFrameShape(QtGui.QFrame.VLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName("line")
        self.horizontalLayout_7.addWidget(self.line)
        self.toolButton_trash = QtGui.QToolButton(self.widget)
        icon3 = QtGui.QIcon()
        icon3.addPixmap(QtGui.QPixmap(":/no/camera_delete.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton_trash.setIcon(icon3)
        self.toolButton_trash.setObjectName("toolButton_trash")
        self.horizontalLayout_7.addWidget(self.toolButton_trash)
        self.toolButton_save = QtGui.QToolButton(self.widget)
        icon4 = QtGui.QIcon()
        icon4.addPixmap(QtGui.QPixmap(":/no/notes_save.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton_save.setIcon(icon4)
        self.toolButton_save.setObjectName("toolButton_save")
        self.horizontalLayout_7.addWidget(self.toolButton_save)
        self.horizontalLayout.addLayout(self.horizontalLayout_7)
        spacerItem = QtGui.QSpacerItem(40, 40, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.dateEdit = QtGui.QDateEdit(self.widget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(40)
        sizePolicy.setHeightForWidth(self.dateEdit.sizePolicy().hasHeightForWidth())
        self.dateEdit.setSizePolicy(sizePolicy)
        self.dateEdit.setMinimumSize(QtCore.QSize(0, 40))
        self.dateEdit.setObjectName("dateEdit")
        self.horizontalLayout.addWidget(self.dateEdit)
        self.stackedWidget.addWidget(self.page_3)
        self.page_4 = QtGui.QWidget()
        self.page_4.setObjectName("page_4")
        self.widget_2 = QtGui.QWidget(self.page_4)
        self.widget_2.setGeometry(QtCore.QRect(0, 0, 782, 61))
        self.widget_2.setObjectName("widget_2")
        self.horizontalLayout_5 = QtGui.QHBoxLayout(self.widget_2)
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.toolButton_3 = QtGui.QToolButton(self.widget_2)
        icon5 = QtGui.QIcon()
        icon5.addPixmap(QtGui.QPixmap(":/no/widgets_time_editor.png"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.toolButton_3.setIcon(icon5)
        self.toolButton_3.setObjectName("toolButton_3")
        self.horizontalLayout_5.addWidget(self.toolButton_3)
        self.line_3 = QtGui.QFrame(self.widget_2)
        self.line_3.setFrameShape(QtGui.QFrame.VLine)
        self.line_3.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.horizontalLayout_5.addWidget(self.line_3)
        self.lineEdit = QtGui.QLineEdit(self.widget_2)
        self.lineEdit.setMinimumSize(QtCore.QSize(0, 30))
        self.lineEdit.setObjectName("lineEdit")
        self.horizontalLayout_5.addWidget(self.lineEdit)
        self.dateEdit_2 = QtGui.QDateEdit(self.widget_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(40)
        sizePolicy.setHeightForWidth(self.dateEdit_2.sizePolicy().hasHeightForWidth())
        self.dateEdit_2.setSizePolicy(sizePolicy)
        self.dateEdit_2.setMinimumSize(QtCore.QSize(0, 40))
        self.dateEdit_2.setObjectName("dateEdit_2")
        self.horizontalLayout_5.addWidget(self.dateEdit_2)
        self.stackedWidget.addWidget(self.page_4)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 37))
        self.menubar.setObjectName("menubar")
        self.menuSettings = QtGui.QMenu(self.menubar)
        self.menuSettings.setObjectName("menuSettings")
        MainWindow.setMenuBar(self.menubar)
        self.actionSettings = QtGui.QAction(MainWindow)
        self.actionSettings.setObjectName("actionSettings")
        self.actionAbout = QtGui.QAction(MainWindow)
        self.actionAbout.setObjectName("actionAbout")
        self.actionSave = QtGui.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionLoad = QtGui.QAction(MainWindow)
        self.actionLoad.setObjectName("actionLoad")
        self.actionQuit = QtGui.QAction(MainWindow)
        self.actionQuit.setObjectName("actionQuit")
        self.actionSync = QtGui.QAction(MainWindow)
        self.actionSync.setObjectName("actionSync")
        self.menuSettings.addAction(self.actionSettings)
        self.menuSettings.addAction(self.actionSave)
        self.menuSettings.addAction(self.actionLoad)
        self.menuSettings.addAction(self.actionAbout)
        self.menuSettings.addAction(self.actionSync)
        self.menuSettings.addAction(self.actionQuit)
        self.menubar.addAction(self.menuSettings.menuAction())

        self.retranslateUi(MainWindow)
        self.stackedWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate("MainWindow", "MainWindow", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton_color.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton_undo.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton_trash.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton_save.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.toolButton_3.setText(QtGui.QApplication.translate("MainWindow", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.menuSettings.setTitle(QtGui.QApplication.translate("MainWindow", "&Zettings", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSettings.setText(QtGui.QApplication.translate("MainWindow", "&preferences", None, QtGui.QApplication.UnicodeUTF8))
        self.actionAbout.setText(QtGui.QApplication.translate("MainWindow", "&about", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSave.setText(QtGui.QApplication.translate("MainWindow", "&save", None, QtGui.QApplication.UnicodeUTF8))
        self.actionLoad.setText(QtGui.QApplication.translate("MainWindow", "&load", None, QtGui.QApplication.UnicodeUTF8))
        self.actionQuit.setText(QtGui.QApplication.translate("MainWindow", "quit", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSync.setText(QtGui.QApplication.translate("MainWindow", "sync", None, QtGui.QApplication.UnicodeUTF8))

import todoy_rc

if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

