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
from settingsUI2 import Ui_Form
from todoy_conf import todoy_config
import cPickle,os


class Settings(QWidget):
   def __init__(self, parent=None):
         QWidget.__init__(self)
         self.ui=Ui_Form()#QWidget() 
         self.ui.setupUi(self)
	 self.parent=parent
	 #self.tempconf=todoy_config()
	 conffile="todoy.conf"#"/home/user/.todoy/todoy.conf"
	 if not os.path.exists(conffile):
	 	self.tempconf=todoy_config()
	 else: self.tempconf=self.parent.conf
	#	conf=open(conffile, 'r+b')
	#	self.tempconf=cPickle.load(conf)

	 try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
	    from PyQt4.QtMaemo5 import QMaemo5InformationBox
         except:
            pass



 #nav bar buttons
	 QObject.connect(self.ui.commandLinkButton_7, SIGNAL("pressed()"), self.showpage_auto)
	 QObject.connect(self.ui.commandLinkButton_15, SIGNAL("pressed()"), self.showpage_gran)
	 #QObject.connect(self.ui.commandLinkButton_8, SIGNAL("pressed()"), self.showpage_date)
	 QObject.connect(self.ui.commandLinkButton_9, SIGNAL("pressed()"), self.showpage_sketch)
	 self.ui.buttonBox.clicked.connect(self.confirm)
 #page1 auto
	 self.ui.checkBox.pressed.connect(self.setdefmode)# setdefault mode
	 self.ui.checkBox_2.pressed.connect(self.setcalsyncmode)
	 self.ui.comboBox_3.currentIndexChanged.connect(self.setpiecolor)#piecolor
	 self.ui.comboBox.currentIndexChanged.connect(self.setdefevent)#defevent
	 self.ui.fontComboBox.currentFontChanged.connect(self.setdeffont)
	 #self.ui.lineEdit.textChanged.connect(self.setcalfile)
 #page2 gran
	 self.ui.spinBox_9.setRange(1,60)
	 self.ui.spinBox_9.setValue(self.tempconf.g_scale_inner)
	 self.ui.spinBox_10.setRange(1,60)
	 self.ui.spinBox_10.setValue(self.tempconf.g_scale_middle)
	 self.ui.spinBox_11.setRange(1,60)
	 self.ui.spinBox_11.setValue(self.tempconf.g_scale_outer)
	 self.ui.spinBox_12.setRange(0,400)
	 self.ui.spinBox_12.setValue(self.tempconf.g_rad_inner)
	 self.ui.spinBox_13.setRange(0,400)
	 self.ui.spinBox_13.setValue(self.tempconf.g_rad_middle)
	 self.ui.spinBox_9.valueChanged.connect(self.setgran_in)
	 self.ui.spinBox_10.valueChanged.connect(self.setgran_mid)
	 self.ui.spinBox_11.valueChanged.connect(self.setgran_out)
	 self.ui.spinBox_12.valueChanged.connect(self.setrad_inn)
	 self.ui.spinBox_13.valueChanged.connect(self.setrad_mid)
	 self.ui.startTimeEdit.setTime(self.tempconf.starttime)
	 self.ui.startTimeEdit.timeChanged.connect(self.setStartTime)
 #page3 date

 #page4 sketch
	 #self.ui.backgroundTemplateLineEdit.textChanged.connect(self.setbkgrnd)
	 self.ui.spinBox_14.setRange(1,20)
	 self.ui.spinBox_14.setValue(self.tempconf.defaultpen_size)
	 self.ui.spinBox_14.valueChanged.connect(self.setpensize)
	 self.ui.doubleSpinBox_15.setRange(0.0,1.0)
	 self.ui.doubleSpinBox_15.setSingleStep(0.01)
	 self.ui.doubleSpinBox_15.setValue(self.tempconf.ellipse_opacity)
	 self.ui.doubleSpinBox_15.valueChanged.connect(self.setopacity)
	 self.ui.comboBox_2.currentIndexChanged.connect(self.setpencolor)#piecolor
	 self.ui.comboBox_4.currentIndexChanged.connect(self.setbkgrnd)#piecolor
	 #self.show()




#main
   def confirm(self):
	#import cPickle
	#configfile=self.tempconf.user_path + "todoy.conf"
	#configuz=open(configfile,"w+b")
	#cPickle.dump(self.tempconf,configuz)
	print "settings saved"
	self.parent.conf=self.tempconf
	self.hide()
	#self.loadsettings()
	#Settings.close(self)

   def showpage_auto(self):
        self.ui.stackedWidget.setCurrentIndex(0)
   def showpage_gran(self):
        self.ui.stackedWidget.setCurrentIndex(1)
   #def showpage_date(self):
   #     self.ui.stackedWidget.setCurrentIndex(2)
   def showpage_sketch(self):
        self.ui.stackedWidget.setCurrentIndex(2)
# page 1 ##############################################################
   def setdefmode(self):
	if self.ui.checkBox.checkState()==0:
		self.tempconf.default_mode="auto"
		try:QMaemo5InformationBox.information(None, "automode set")
		except:print "default automode"

	else: 
		self.tempconf.default_mode="sketch"
		try:QMaemo5InformationBox.information(None, "sketchmode set")
		except: print "default sketchmode"
   def setcalsyncmode(self):
	if self.ui.checkBox_2.checkState()==0:
		self.tempconf.calsync=True
		print "calsync on"
	else: 
		self.tempconf.calsync=False
		print "calsync off"
   
   def setdefevent(self,index):
	if index==0: self.tempconf.default_ev="EVENT"
	elif index==1: self.tempconf.default_ev="TODO"
	else: self.tempconf.default_ev="ALARM"
	print "set default event as: " + self.tempconf.default_ev

   def setpiecolor(self,index):
	if index==0: 
		self.tempconf.pie_color=Qt.green
		self.tempconf.pie_randcolor=False
	elif index==1: 
		self.tempconf.pie_color=Qt.red
		self.tempconf.pie_randcolor=False
	elif index==2: 
		self.tempconf.pie_color=Qt.blue
		self.tempconf.pie_randcolor=False
	elif index==3: 
		self.tempconf.pie_color=Qt.yellow
		self.tempconf.pie_randcolor=False
	elif index==4: 
		self.tempconf.pen_color=Qt.gray
		self.tempconf.pie_randcolor=False
	else: self.tempconf.pie_randcolor=True
	#print "set default event as: " + self.tempconf.pie_color


   def setcalfile(self,text):
	self.tempconf.cal_file=str(text)
	print text
   def setdeffont(self,font):
	self.tempconf.font=font###doesn't work.. 
	print "font changed"
# page 2 ##############################################################
   def setgran_in(self, value):
	self.tempconf.g_scale_inner=value
   def setgran_mid(self,value):
	self.tempconf.g_scale_middle=value
   def setgran_out(self,value):
	self.tempconf.g_scale_outer=value
   def setrad_inn(self,value):
	self.tempconf.g_rad_inner=value
   def setrad_mid(self,value):
	self.tempconf.g_rad_middle=value
   def setStartTime(self,value):
	self.tempconf.starttime=value
	print value
# page 3 ##############################################################
# page 4 ##############################################################
   def setbkgrnd(self, index):
#	self.tempconf.bkgrnd="todoy_bkgrnd" + ".png"
	if index==0: self.tempconf.bkgrnd="todoy_bkgrnd" +".png"
	elif index==1: self.tempconf.bkgrnd="todoy_bkgrnd" +str(index)+ ".png"
	elif index==2: self.tempconf.bkgrnd="todoy_bkgrnd" +str(index)+ ".png"
	elif index==3: self.tempconf.bkgrnd="todoy_bkgrnd" +str(index)+ ".png"
	elif index==4: self.tempconf.bkgrnd="todoy_bkgrnd" +str(index)+ ".png"
#	elif index==5: self.tempconf.bkgrnd=value
	else: self.tempconf.bkgrnd="todoy_bkgrnd" + ".png"

   def setpensize(self,value):
	self.tempconf.defaultpen_size=value
   def setopacity(self,value):
	self.tempconf.ellipse_opacity=value

   def setpencolor(self,index):
	if index==0: self.tempconf.pen_color=Qt.black
	elif index==1: self.tempconf.pen_color=Qt.white
	elif index==2: self.tempconf.pen_color=Qt.green
	elif index==3: self.tempconf.pen_color=Qt.red
	elif index==4: self.tempconf.pen_color=Qt.blue
	elif index==5: self.tempconf.pen_color=Qt.yellow
	else: self.tempconf.pen_color=Qt.gray







def main():
     app = QApplication(sys.argv)
     window=Settings()
     window.show()
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()

