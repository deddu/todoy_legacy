# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'settings_3.ui'
#
# Created: Thu Sep 30 09:36:48 2010
#      by: PyQt4 UI code generator 4.7.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(800, 400)
        self.stackedWidget = QtGui.QStackedWidget(Form)
        self.stackedWidget.setGeometry(QtCore.QRect(0, 0, 800, 350))
        self.stackedWidget.setObjectName("stackedWidget")
        self.page = QtGui.QWidget()
        self.page.setObjectName("page")
        self.formLayoutWidget = QtGui.QWidget(self.page)
        self.formLayoutWidget.setGeometry(QtCore.QRect(0, 0, 791, 684))
        self.formLayoutWidget.setObjectName("formLayoutWidget")
        self.formLayout = QtGui.QFormLayout(self.formLayoutWidget)
        self.formLayout.setFieldGrowthPolicy(QtGui.QFormLayout.AllNonFixedFieldsGrow)
        self.formLayout.setObjectName("formLayout")
        self.label_3 = QtGui.QLabel(self.formLayoutWidget)
        self.label_3.setObjectName("label_3")
        self.formLayout.setWidget(1, QtGui.QFormLayout.LabelRole, self.label_3)
        self.checkBox = QtGui.QCheckBox(self.formLayoutWidget)
        self.checkBox.setObjectName("checkBox")
        self.formLayout.setWidget(2, QtGui.QFormLayout.LabelRole, self.checkBox)
        self.checkBox_2 = QtGui.QCheckBox(self.formLayoutWidget)
        self.checkBox_2.setObjectName("checkBox_2")
        self.formLayout.setWidget(3, QtGui.QFormLayout.LabelRole, self.checkBox_2)
        self.label_7 = QtGui.QLabel(self.formLayoutWidget)
        self.label_7.setObjectName("label_7")
        self.formLayout.setWidget(3, QtGui.QFormLayout.FieldRole, self.label_7)
        self.label_2 = QtGui.QLabel(self.formLayoutWidget)
        self.label_2.setObjectName("label_2")
        self.formLayout.setWidget(4, QtGui.QFormLayout.LabelRole, self.label_2)
        self.comboBox = QtGui.QComboBox(self.formLayoutWidget)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.comboBox.addItem("")
        self.formLayout.setWidget(4, QtGui.QFormLayout.FieldRole, self.comboBox)
        self.defautlFontLabel = QtGui.QLabel(self.formLayoutWidget)
        self.defautlFontLabel.setObjectName("defautlFontLabel")
        self.formLayout.setWidget(5, QtGui.QFormLayout.LabelRole, self.defautlFontLabel)
        self.fontComboBox = QtGui.QFontComboBox(self.formLayoutWidget)
        self.fontComboBox.setObjectName("fontComboBox")
        self.formLayout.setWidget(5, QtGui.QFormLayout.FieldRole, self.fontComboBox)
        self.stackedWidget.addWidget(self.page)
        self.page_2 = QtGui.QWidget()
        self.page_2.setObjectName("page_2")
        self.textBrowser = QtGui.QTextBrowser(self.page_2)
        self.textBrowser.setGeometry(QtCore.QRect(12, 230, 769, 101))
        self.textBrowser.setObjectName("textBrowser")
        self.widget = QtGui.QWidget(self.page_2)
        self.widget.setGeometry(QtCore.QRect(14, 14, 761, 211))
        self.widget.setObjectName("widget")
        self.gridLayout = QtGui.QGridLayout(self.widget)
        self.gridLayout.setObjectName("gridLayout")
        self.label_4 = QtGui.QLabel(self.widget)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 0, 0, 1, 1)
        self.label_5 = QtGui.QLabel(self.widget)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 0, 1, 1, 1)
        self.formLayout_6 = QtGui.QFormLayout()
        self.formLayout_6.setObjectName("formLayout_6")
        self.label_12 = QtGui.QLabel(self.widget)
        self.label_12.setObjectName("label_12")
        self.formLayout_6.setWidget(0, QtGui.QFormLayout.LabelRole, self.label_12)
        self.spinBox_9 = QtGui.QSpinBox(self.widget)
        self.spinBox_9.setObjectName("spinBox_9")
        self.formLayout_6.setWidget(0, QtGui.QFormLayout.FieldRole, self.spinBox_9)
        self.label_13 = QtGui.QLabel(self.widget)
        self.label_13.setObjectName("label_13")
        self.formLayout_6.setWidget(1, QtGui.QFormLayout.LabelRole, self.label_13)
        self.spinBox_10 = QtGui.QSpinBox(self.widget)
        self.spinBox_10.setObjectName("spinBox_10")
        self.formLayout_6.setWidget(1, QtGui.QFormLayout.FieldRole, self.spinBox_10)
        self.label_14 = QtGui.QLabel(self.widget)
        self.label_14.setObjectName("label_14")
        self.formLayout_6.setWidget(2, QtGui.QFormLayout.LabelRole, self.label_14)
        self.spinBox_11 = QtGui.QSpinBox(self.widget)
        self.spinBox_11.setObjectName("spinBox_11")
        self.formLayout_6.setWidget(2, QtGui.QFormLayout.FieldRole, self.spinBox_11)
        self.gridLayout.addLayout(self.formLayout_6, 1, 0, 1, 1)
        self.formLayout_7 = QtGui.QFormLayout()
        self.formLayout_7.setObjectName("formLayout_7")
        self.label_15 = QtGui.QLabel(self.widget)
        self.label_15.setObjectName("label_15")
        self.formLayout_7.setWidget(0, QtGui.QFormLayout.LabelRole, self.label_15)
        self.spinBox_12 = QtGui.QSpinBox(self.widget)
        self.spinBox_12.setObjectName("spinBox_12")
        self.formLayout_7.setWidget(0, QtGui.QFormLayout.FieldRole, self.spinBox_12)
        self.label_16 = QtGui.QLabel(self.widget)
        self.label_16.setObjectName("label_16")
        self.formLayout_7.setWidget(1, QtGui.QFormLayout.LabelRole, self.label_16)
        self.spinBox_13 = QtGui.QSpinBox(self.widget)
        self.spinBox_13.setObjectName("spinBox_13")
        self.formLayout_7.setWidget(1, QtGui.QFormLayout.FieldRole, self.spinBox_13)
        self.gridLayout.addLayout(self.formLayout_7, 1, 1, 1, 1)
        self.stackedWidget.addWidget(self.page_2)
        self.page_4 = QtGui.QWidget()
        self.page_4.setObjectName("page_4")
        self.layoutWidget = QtGui.QWidget(self.page_4)
        self.layoutWidget.setGeometry(QtCore.QRect(30, 10, 676, 325))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.formLayout_5 = QtGui.QFormLayout()
        self.formLayout_5.setFieldGrowthPolicy(QtGui.QFormLayout.AllNonFixedFieldsGrow)
        self.formLayout_5.setObjectName("formLayout_5")
        self.sketchModePreferencesLabel = QtGui.QLabel(self.layoutWidget)
        self.sketchModePreferencesLabel.setObjectName("sketchModePreferencesLabel")
        self.formLayout_5.setWidget(0, QtGui.QFormLayout.LabelRole, self.sketchModePreferencesLabel)
        self.label_6 = QtGui.QLabel(self.layoutWidget)
        self.label_6.setObjectName("label_6")
        self.formLayout_5.setWidget(1, QtGui.QFormLayout.LabelRole, self.label_6)
        self.formLayout_9 = QtGui.QFormLayout()
        self.formLayout_9.setFieldGrowthPolicy(QtGui.QFormLayout.AllNonFixedFieldsGrow)
        self.formLayout_9.setObjectName("formLayout_9")
        self.label_17 = QtGui.QLabel(self.layoutWidget)
        self.label_17.setObjectName("label_17")
        self.formLayout_9.setWidget(0, QtGui.QFormLayout.LabelRole, self.label_17)
        self.spinBox_14 = QtGui.QSpinBox(self.layoutWidget)
        self.spinBox_14.setObjectName("spinBox_14")
        self.formLayout_9.setWidget(0, QtGui.QFormLayout.FieldRole, self.spinBox_14)
        self.label_18 = QtGui.QLabel(self.layoutWidget)
        self.label_18.setObjectName("label_18")
        self.formLayout_9.setWidget(1, QtGui.QFormLayout.LabelRole, self.label_18)
        self.doubleSpinBox_15 = QtGui.QDoubleSpinBox(self.layoutWidget)
        self.doubleSpinBox_15.setObjectName("doubleSpinBox_15")
        self.formLayout_9.setWidget(1, QtGui.QFormLayout.FieldRole, self.doubleSpinBox_15)
        self.formLayout_5.setLayout(2, QtGui.QFormLayout.FieldRole, self.formLayout_9)
        self.backgroundTemplateLabel = QtGui.QLabel(self.layoutWidget)
        self.backgroundTemplateLabel.setObjectName("backgroundTemplateLabel")
        self.formLayout_5.setWidget(3, QtGui.QFormLayout.LabelRole, self.backgroundTemplateLabel)
        self.backgroundTemplateLineEdit = QtGui.QLineEdit(self.layoutWidget)
        self.backgroundTemplateLineEdit.setObjectName("backgroundTemplateLineEdit")
        self.formLayout_5.setWidget(3, QtGui.QFormLayout.FieldRole, self.backgroundTemplateLineEdit)
        self.horizontalLayout.addLayout(self.formLayout_5)
        self.stackedWidget.addWidget(self.page_4)
        self.layoutWidget_3 = QtGui.QWidget(Form)
        self.layoutWidget_3.setGeometry(QtCore.QRect(0, 340, 791, 51))
        self.layoutWidget_3.setObjectName("layoutWidget_3")
        self.horizontalLayout_2 = QtGui.QHBoxLayout(self.layoutWidget_3)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.commandLinkButton_7 = QtGui.QCommandLinkButton(self.layoutWidget_3)
        self.commandLinkButton_7.setObjectName("commandLinkButton_7")
        self.horizontalLayout_2.addWidget(self.commandLinkButton_7)
        self.commandLinkButton_15 = QtGui.QCommandLinkButton(self.layoutWidget_3)
        self.commandLinkButton_15.setObjectName("commandLinkButton_15")
        self.horizontalLayout_2.addWidget(self.commandLinkButton_15)
        self.commandLinkButton_9 = QtGui.QCommandLinkButton(self.layoutWidget_3)
        self.commandLinkButton_9.setObjectName("commandLinkButton_9")
        self.horizontalLayout_2.addWidget(self.commandLinkButton_9)
        self.buttonBox = QtGui.QDialogButtonBox(self.layoutWidget_3)
        self.buttonBox.setStandardButtons(QtGui.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.horizontalLayout_2.addWidget(self.buttonBox)

        self.retranslateUi(Form)
        self.stackedWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        Form.setWindowTitle(QtGui.QApplication.translate("Form", "Form", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("Form", "Auto Mode Preferences:", None, QtGui.QApplication.UnicodeUTF8))
        self.checkBox.setText(QtGui.QApplication.translate("Form", "start with auto mode", None, QtGui.QApplication.UnicodeUTF8))
        self.checkBox_2.setText(QtGui.QApplication.translate("Form", "sync with calendar", None, QtGui.QApplication.UnicodeUTF8))
        self.label_7.setText(QtGui.QApplication.translate("Form", "(requires auto mode)", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("Form", "default event", None, QtGui.QApplication.UnicodeUTF8))
        self.comboBox.setItemText(0, QtGui.QApplication.translate("Form", "event", None, QtGui.QApplication.UnicodeUTF8))
        self.comboBox.setItemText(1, QtGui.QApplication.translate("Form", "todo", None, QtGui.QApplication.UnicodeUTF8))
        self.comboBox.setItemText(2, QtGui.QApplication.translate("Form", "alarm", None, QtGui.QApplication.UnicodeUTF8))
        self.defautlFontLabel.setText(QtGui.QApplication.translate("Form", "default font", None, QtGui.QApplication.UnicodeUTF8))
        self.textBrowser.setHtml(QtGui.QApplication.translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Droid Sans\'; font-size:18pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Granulometry: time tolerance while dragging: set up here your favourite time steps. defaults are: 15, 5, 1 minutes</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Granulometry radii: radii of the boundaries between zones, measured from the center.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">defaults are: 100, 200</span></p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_4.setText(QtGui.QApplication.translate("Form", "granulometry:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_5.setText(QtGui.QApplication.translate("Form", "granulometry radii:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_12.setText(QtGui.QApplication.translate("Form", "inner", None, QtGui.QApplication.UnicodeUTF8))
        self.label_13.setText(QtGui.QApplication.translate("Form", "middle", None, QtGui.QApplication.UnicodeUTF8))
        self.label_14.setText(QtGui.QApplication.translate("Form", "outer", None, QtGui.QApplication.UnicodeUTF8))
        self.label_15.setText(QtGui.QApplication.translate("Form", "inner", None, QtGui.QApplication.UnicodeUTF8))
        self.label_16.setText(QtGui.QApplication.translate("Form", "middle", None, QtGui.QApplication.UnicodeUTF8))
        self.sketchModePreferencesLabel.setText(QtGui.QApplication.translate("Form", "sketch mode preferences:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_6.setText(QtGui.QApplication.translate("Form", "pen preferences", None, QtGui.QApplication.UnicodeUTF8))
        self.label_17.setText(QtGui.QApplication.translate("Form", "size", None, QtGui.QApplication.UnicodeUTF8))
        self.label_18.setText(QtGui.QApplication.translate("Form", "opacity", None, QtGui.QApplication.UnicodeUTF8))
        self.backgroundTemplateLabel.setText(QtGui.QApplication.translate("Form", "background template", None, QtGui.QApplication.UnicodeUTF8))
        self.commandLinkButton_7.setText(QtGui.QApplication.translate("Form", "auto mode", None, QtGui.QApplication.UnicodeUTF8))
        self.commandLinkButton_15.setText(QtGui.QApplication.translate("Form", "granulometry", None, QtGui.QApplication.UnicodeUTF8))
        self.commandLinkButton_9.setText(QtGui.QApplication.translate("Form", "sketch mode", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    Form = QtGui.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())

