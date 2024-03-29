#!/usr/bin/python

import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import strftime, gmtime
from todoyUI import Ui_MainWindow
from todoypage import TodoyPage
import todoy_calsync


class Main(QMainWindow):
   def __init__(self):
         QMainWindow.__init__(self)
         self.ui=Ui_MainWindow()#QWidget() 
         self.ui.setupUi(self)
	 self.todoypage=TodoyPage(self)
 	 self.cal=todoy_calsync.cal_handling()
	 eee=strftime("%Y%m%d",gmtime())
	 today=QDate.fromString(eee,"yyyyMMdd")
	 self.ui.dateEdit.setDate(today)
	 self.ui.dateEdit.setDisplayFormat("yyyy.MM.dd")
	 self.ui.dateEdit_2.setDate(today)
	 self.ui.dateEdit_2.setDisplayFormat("yyyy.MM.dd")
	 self.setmode1()

	 QObject.connect(self.ui.toolButton_3, SIGNAL("pressed()"), self.setmode0)
	 QObject.connect(self.ui.toolButton, SIGNAL("pressed()"), self.setmode1)
	 #QObject.connect(self.ui.toolButton, SIGNAL("pressed()"), self.todoypage.setmode)editingFinished ()
	 QObject.connect(self.ui.lineEdit, SIGNAL("textChanged(QString)"), self.todoypage.settext)
	 QObject.connect(self.ui.dateEdit, SIGNAL("dateChanged(QDate)"),self.todoypage.setdate)
	 QObject.connect(self.ui.dateEdit_2, SIGNAL("dateChanged(QDate)"),self.todoypage.setdate)
 	 QObject.connect(self.ui.lineEdit, SIGNAL("editingFinished()"), self.confirm)
	#ui key connections:
	 QObject.connect(self.ui.toolButton_undo, SIGNAL("pressed()"), self.todoypage.undo)#undo
	 QObject.connect(self.ui.toolButton_trash, SIGNAL("pressed()"), self.clear)#trash
	 QObject.connect(self.ui.toolButton_color, SIGNAL("pressed()"), self.todoypage.color)#color
	 QObject.connect(self.ui.toolButton_save, SIGNAL("pressed()"), 	self.todoypage.save)#save
#	 QObject.connect(self.ui.toolButton_3, SIGNAL("pressed()"), self.setmode0)
	 try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
            USE_MAEMO = True
         except:
            USE_MAEMO = False


   def setmode0(self):
        self.ui.stackedWidget.setCurrentIndex(0)
	self.todoypage.setmode("sketch")
   def setmode1(self):
        self.ui.stackedWidget.setCurrentIndex(1)
	self.todoypage.setmode("auto")



   def keyPressEvent (self, QKeyEvent):
	#if QKeyEvent.matches (self, QKeySequence.StandardKey)
	if QKeyEvent.key()==Qt.Key_Q:
		print "ye" #implement close!
		QApplication.exit(0)
	elif QKeyEvent.key()==Qt.Key_B:
		self.todoypage.pen = QPen(Qt.blue, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_R:
		self.todoypage.pen = QPen(Qt.red, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_G:
		self.todoypage.pen = QPen(Qt.green, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_K:
		self.todoypage.pen = QPen(Qt.black, 4, Qt.SolidLine)
	elif QKeyEvent.key()==Qt.Key_C:
		self.clear()
	elif QKeyEvent.key()==Qt.Key_W:
		self.todoypage.pen = QPen(Qt.white, 10, Qt.SolidLine)
	elif QKeyEvent.key()==Qt.Key_Z:
		self.todoypage.undo()
	elif QKeyEvent.key()==Qt.Key_S:
		self.todoypage.save()
	elif QKeyEvent.key()==Qt.Key_L:
		self.todoypage.load()
	elif QKeyEvent.key()==Qt.Key_V:
		self.todoypage.validate()
#	elif QKeyEvent.key()==Qt.Key_Enter:
#		self.todoypage.validate()
#		self.cal_add()
#	elif QKeyEvent.key()==Qt.Key_Return:
#		self.todoypage.validate()
#		self.cal_add()
	elif QKeyEvent.key()==Qt.Key_A:
		self.cal_add()


   def cal_add(self):
		self.cal.date=self.todoypage.date
		self.cal.start=self.todoypage.t0
		self.cal.end=self.todoypage.t1
		self.cal.summary=str(self.todoypage.text)
		self.cal.add_event()


   def confirm(self):
	self.todoypage.validate()
	self.cal_add()
   def clear(self):
	self.todoypage.openPixmap("todoy_bkgrnd.png")


def main():
     app = QApplication(sys.argv)
     window=Main()
     window.show()
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()
