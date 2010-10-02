#!/usr/bin/python

###The MIT License

#Copyright (c) 2010  andrea cadeddu, mrernia@gmail.com

#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:

#The above copyright notice and this permission notice shall be included in
#all copies or substantial portions of the Software.

#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#THE SOFTWARE.
###

import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import strftime, gmtime
from todoyUI import Ui_MainWindow
from todoypage import TodoyPage
import todoy_calsync
from todoy_conf import todoy_config
from todoy_settings import Settings


class Main(QMainWindow):
   def __init__(self):
         QMainWindow.__init__(self)
	 import os, cPickle
         self.ui=Ui_MainWindow()#QWidget() 
         self.ui.setupUi(self)
	 self.loadsettings()
	 self.settings=Settings(self)
	 self.settings.hide()
	 self.synced=False

 	 self.cal=todoy_calsync.cal_handling(self.conf)
	 self.todoypage=TodoyPage(self,self.conf)
	 eee=strftime("%Y%m%d",gmtime())
	 today=QDate.fromString(eee,"yyyyMMdd")
	 self.ui.dateEdit.setDate(today)
	 self.ui.dateEdit.setDisplayFormat("yyyy.MM.dd")
	 self.ui.dateEdit_2.setDate(today)
	 self.ui.dateEdit_2.setDisplayFormat("yyyy.MM.dd")

	 if 	self.conf.default_mode =="auto":
		self.setmode1()
	 else: self.setmode0()

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
	 QObject.connect(self.ui.toolButton_save, SIGNAL("pressed()"), 	self.todoypage.save)
	 QObject.connect(self.ui.toolButton_save, SIGNAL("pressed()"), 	self.cal.parse_events)#save
#	 QObject.connect(self.ui.toolButton_3, SIGNAL("pressed()"), self.setmode0)
	 #self.ui.menuSettings=QAction(self.tr('Configure'), self)




	 try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
            USE_MAEMO = True
         except:
            USE_MAEMO = False
   
   #def hideEvent(self,event):
	#print "clos"
	#self.loadsettings()


   def loadsettings(self):
	 #import os, cPickle
	 #conffile="todoy.conf"#"/home/user/.todoy/todoy.conf"
	 #if not os.path.exists(conffile):
	 self.conf=todoy_config()
	 #else: 
		#conf=open(conffile, 'r+b')
		#self.conf=cPickle.load(conf)
   def on_actionSync_triggered(self):
	import os
	import dbus
	self.cal.parse_events()
	try:
		bus=dbus.SessionBus()
		proxy=bus.get_object('com.nokia.calendar','/com/nokia/calendar')
		iface=dbus.Interface(proxy,'com.nokia.calendar')
		iface.mime_open('file:///home/user/.todoy/todoy.ics')
		self.synced=True
		#self.cal.cal_clear()
	    #os.system('dbus-send --type=method_call --dest=com.nokia.calendar /com/nokia/calendar com.nokia.calendar.mime_open string:"file:///home/user/.todoy/.todoy"')
	except: 
		print "you should be using me on maemo5"
		self.synced=False

   def on_actionSettings_triggered(self):
	#self.settings=Settings(self)
	self.settings.show()
	#self.loadsettings()   def on	 
	#self.settings.close.connect(self.loadsettings)

	
   def on_actionSave_triggered(self):
	self.todoypage.save()
	self.cal.parse_events()
   def on_actionLoad_triggered(self):
	self.todoypage.load()
   def on_actionAbout_triggered(self):
	pass
   def on_actionQuit_triggered(self):
	self.close()

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
		self.close()#QApplication.exit(0)
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
	self.todoypage.openPixmap(self.conf.bkgrnd)



   def closeEvent(self,ev):
	if self.synced: 
		self.cal.cal_clear()
		print "cal cleared on exit"
	ev.accept()


def main():
     app = QApplication(sys.argv)
     window=Main()
     window.show()
     
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()
