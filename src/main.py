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
import datetime
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
	 self.currentdate=datetime.date.today()
	 self.delta=datetime.timedelta(1)

 	 self.cal=todoy_calsync.cal_handling(self.conf)
	 self.todoypage=TodoyPage(self,self.conf)#settings=QSettings("sofago.net","todoy")
	 eee=strftime("%Y%m%d",gmtime())
	 today=QDate.fromString(eee,"yyyyMMdd")
	 self.ui.dateEdit.setDate(self.currentdate)#today)
	 self.ui.dateEdit.setDisplayFormat("dd.MM.yy")
	 #self.ui.dateEdit_2.setDate(today)
	 #self.ui.dateEdit_2.setDisplayFormat("yyyy.MM.dd")

	 if 	self.conf.default_mode =="auto":
		self.setmode1()
	 else: self.setmode0()

	 QObject.connect(self.ui.toolButton_3, SIGNAL("pressed()"), self.setmode0)
	 QObject.connect(self.ui.toolButton, SIGNAL("pressed()"), self.setmode1)
	 #QObject.connect(self.ui.toolButton, SIGNAL("pressed()"), self.todoypage.setmode)editingFinished ()
	 QObject.connect(self.ui.lineEdit, SIGNAL("textChanged(QString)"), self.todoypage.settext)
	 QObject.connect(self.ui.dateEdit, SIGNAL("dateChanged(QDate)"),self.todoypage.setdate)
	 #QObject.connect(self.ui.dateEdit_2, SIGNAL("dateChanged(QDate)"),self.todoypage.setdate)
 	 QObject.connect(self.ui.lineEdit, SIGNAL("editingFinished()"), self.confirm)
	#ui key connections:
	 QObject.connect(self.ui.toolButton_undo, SIGNAL("pressed()"), self.todoypage.undo)#undo
	 QObject.connect(self.ui.toolButton_trash, SIGNAL("pressed()"), self.clear)#trash
	 QObject.connect(self.ui.toolButton_color, SIGNAL("pressed()"), self.todoypage.color)#color
	 QObject.connect(self.ui.toolButton_save, SIGNAL("pressed()"), 	self.todoypage.save)
	 QObject.connect(self.ui.toolButton_save, SIGNAL("pressed()"), 	self.cal.parse_events)#save
#	 QObject.connect(self.ui.toolButton_3, SIGNAL("pressed()"), self.setmode0)
	 #self.ui.menuSettings=QAction(self.tr('Configure'), self)
	 self.ui.toolButton_2.clicked.connect(self.minusday)
	 self.ui.toolButton_4.clicked.connect(self.plusday)




	 try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
            USE_MAEMO = True
         except:
            USE_MAEMO = False
   
   #def hideEvent(self,event):
	#print "clos"
	#self.loadsettings()

   def plusday(self):
	self.currentdate= self.currentdate+self.delta
	self.ui.dateEdit.setDate(self.currentdate)
   def minusday(self):
	self.currentdate=self.currentdate-self.delta
	self.ui.dateEdit.setDate(self.currentdate)


   def loadsettings(self):
	 #import os, cPickle		self.conf.pen_color = Qt.blue
	 #conffile="todoy.conf"#"/home/user/.todoy/todoy.conf"
	 #if not os.path.exists(conffile):
	#try:
	settings=QSettings("sofago.net","todoy")
	self.conf=todoy_config()
	success=True
	self.conf.user_path=str(settings.value("user_path","").toString())#""#"/home/user/.todoy/"
	self.conf.install_path=str(settings.value("install_path","/opt/todoy/").toString())
	self.conf.cal_sync= settings.value("cal_sync",True).toBool()
	self.conf.default_mode = str(settings.value("default_mode","auto").toString())
	self.conf.cal_file=str(settings.value("cal_file","todoy.ics").toString())
	self.conf.default_ev=str(settings.value("default_ev","EVENT").toString())
	piecolor,success=settings.value("pie_color", Qt.green).toInt()
	self.conf.pie_color=Qt.GlobalColor(piecolor)#QtCore.Qt.green
	self.conf.pie_randcolor=settings.value("pie_randcolor", True).toBool()#True#False

	self.conf.g_rad_inner,success=settings.value("g_rad_inner",100).toInt()#100
	self.conf.g_rad_middle,success=settings.value("g_rad_middle",200).toInt()#200
	self.conf.g_scale_inner,success=settings.value("g_scale_inner",15).toInt()#15
	self.conf.g_scale_middle,success=settings.value("g_scale_middle",5).toInt()#5
	self.conf.g_scale_outer,success=settings.value("g_scale_outer",1).toInt()#1
	self.conf.starttime=settings.value("starttime",QTime(8,0)).toTime()
	self.conf.defaultpen_size,success=settings.value("defaultpen_size",4).toInt()#4
	pencolor,success=settings.value("pen_color", Qt.black).toInt()
	self.conf.pen_color=Qt.GlobalColor(pencolor)
	self.conf.ellipse_opacity,success=settings.value("ellipse_opacity",0.15).toFloat()#0.15
	self.conf.font=QFont(settings.value("font",QFont("Arial", 15)))
	self.conf.bkgrnd=str(settings.value("bkgrnd","todoy_bkgrnd.png").toString())#"todoy_bkgrnd.png"
#	self.conf.colorlist=



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
		self.conf.pen_color = Qt.blue
		#self.update()
	elif QKeyEvent.key()==Qt.Key_R:
		self.conf.pen_color = Qt.red
		#self.update()
	elif QKeyEvent.key()==Qt.Key_G:
		self.conf.pen_color = Qt.green
		#self.update()
	elif QKeyEvent.key()==Qt.Key_K:
		self.conf.pen_color = Qt.black
	elif QKeyEvent.key()==Qt.Key_D:
		self.clear()
	elif QKeyEvent.key()==Qt.Key_W:
		self.conf.pen_color = Qt.white
	elif QKeyEvent.key()==Qt.Key_Y:
		self.conf.pen_color = Qt.yellow
	elif QKeyEvent.key()==Qt.Key_C:
		self.conf.pen_color = Qt.cyan
	elif QKeyEvent.key()==Qt.Key_M:
		self.conf.pen_color = Qt.magenta
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
	self.ui.lineEdit.setText("")
   def clear(self):
	self.todoypage.openPixmap(self.conf.bkgrnd)


   def savesettings(self):
	settings=QSettings("sofago.net","todoy")
	#settings.setValue("conf",self.conf)
	success=True
	settings.setValue("user_path",	self.conf.user_path)
	settings.setValue("install_path",self.conf.install_path)
	settings.setValue("cal_sync",self.conf.cal_sync)
	settings.setValue("default_mode",self.conf.default_mode)
	settings.setValue("cal_file",self.conf.cal_file)
	settings.setValue("default_ev",self.conf.default_ev)
	settings.setValue("pie_color", self.conf.pie_color)
	settings.setValue("pie_randcolor",self.conf.pie_randcolor)#True#False
	settings.setValue("g_rad_inner",self.conf.g_rad_inner)#100
	settings.setValue("g_rad_middle",self.conf.g_rad_middle)#200
	settings.setValue("g_scale_inner",self.conf.g_scale_inner)
	settings.setValue("g_scale_middle",self.conf.g_scale_middle)#5
	settings.setValue("g_scale_outer",self.conf.g_scale_outer)#1
	settings.setValue("starttime",self.conf.starttime)
	settings.setValue("defaultpen_size",self.conf.defaultpen_size)#4
	settings.setValue("pen_color", self.conf.pen_color)#QtCore.Qt.black
	settings.setValue("ellipse_opacity",self.conf.ellipse_opacity)#0.15
	settings.setValue("font",self.conf.font)
	settings.setValue("bkgrnd",self.conf.bkgrnd)#"todoy_bkgrnd.png"
#	self.conf.colorlist=



   def closeEvent(self,ev):
	self.savesettings()
	#settings=QSettings("sofago.net","todoy")
	#settings.setValue("conf",self.conf)
	print"ok"
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
