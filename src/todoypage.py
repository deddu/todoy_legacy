
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


class TodoyPage(QWidget):
   def __init__(self,parent,conf):
	 QWidget.__init__(self,parent)
	 self.mousepressed=False
	 #self#.conf=conf
	 self.parent=parent
	 self.inputmode= self.parent.conf.default_mode#"auto"#"sketch"#or auto
	 self.pixmap=QPixmap()
	 self.undoPixmap=QPixmap()
	 self.image = QImage()
	 self.defpath=self.parent.conf.user_path#"/home/user/.todoy/"
	 self.text=""
         #self.lastPoint = QPoint()
	 self.setWindowTitle("Todoy")
         self.resize(800,350)
	 self.openImage(self.parent.conf.bkgrnd)
	 self.openPixmap(self.parent.conf.bkgrnd)
	 self.pen=QPen(self.parent.conf.pen_color, 4, Qt.SolidLine)
	 self.p1 = QPoint(-1, -1)
	 self.p2 = QPoint(-1, -1)
         self.date=strftime("%Y%m%d",gmtime())
	 self.colorlist=self.parent.conf.colorlist

   def openPixmap(self, fileName):
	loadedPix=QPixmap()
	if not loadedPix.load(fileName):
		return False
	newSize = loadedPix.size().expandedTo(self.size())
        #self.resizeImage(loadedImage, newSize)
        self.pixmap = loadedPix
        self.modified = False
        self.update()
        return True

   def save(self):
	today=self.defpath+self.date+".png"
	self.pixmap.save(today)

   def load(self):
	today=self.defpath+self.date+".png"#strftime("%Y%m%d",gmtime())+".png"
	self.openPixmap(today)	
	self.openImage(today)



   def openImage(self, fileName):
        loadedImage = QImage()
        if not loadedImage.load(fileName):
            return False

        newSize = loadedImage.size().expandedTo(self.size())
        #self.resizeImage(loadedImage, newSize)
        self.image = loadedImage
        self.modified = False
        self.update()
        return True

   def paintEvent(self, ev):
        p = QPainter(self)
	#today=strftime("%a, %d %b %Y",gmtime())
        
	self.pen.setColor(self.parent.conf.pen_color)#QPen()
	self.pen.setWidth(self.parent.conf.defaultpen_size)
	pen=self.pen
	self.draftPen=QPen()
	#color = QColor(Qt.black)
	#pen.setColor(color)
	#pen.setStyle(Qt.SolidLine)
	self.draftPen.setColor(Qt.black)
	self.draftPen.setStyle(Qt.DashLine)
	self.draftPen.setWidth(1)
	p.drawPixmap(QPoint(0, 0), self.pixmap);
	if self.mousepressed and self.inputmode=="sketch":#(toolbar->downButton() != ToolBarButton::EPen)
   		p.setPen(self.draftPen) #// ongoing drawing, not final (waiting for mouseRelease)
        	#if self.inputmode=="sketch":
        	self.paintLine(p)
	if self.mousepressed and self.inputmode=="auto":
		#p.setPen(self.draftPen)
	 	self.paintAuto(p)

	p.setFont(self.parent.conf.font)#QFont("Arial", 15))
        p.drawText(20,20, self.date)
	infos=("Q: Quit, C/U: Clear/Undo, S/L:save/load, W-CYMK-RGB: colors")
	if self.inputmode=="sketch":p.drawText(20,50, infos)
	p.end()
	
   def mousePressEvent(self,ev):
	from random import choice
	if (ev.buttons()& Qt.LeftButton):
		#self.lastpoint=ev.pos()
		self.mousepressed=True
		self.p1 = ev.pos()
    		self.p2 = QPoint(-1, -1)
		self.showcircles=True    
		self.saveForUndo()
		if self.parent.conf.pie_randcolor: self.parent.conf.pie_color=choice(self.colorlist)#[Qt.blue,Qt.yellow,Qt.red,Qt.green,Qt.cyan])





   def mouseMoveEvent(self, event):
	if (event.buttons() & Qt.LeftButton) and self.mousepressed and self.inputmode=="sketch":
        #   self.drawLineTo(event.pos())
	# if (toolbar.downButton() == ToolBarButton.EPen or toolbar.downButton()== ToolBarButton.EErase) 
	        #// Pen is drawed direct to pixmap in mouseMoveEvent
	        if (self.p2.x() == -1) :
	            self.p2 = event.pos()
	        
	        else :
	            self.p1 = self.p2
	            self.p2 = event.pos()
	        
	        #// Paint to pixmap and then pixmap on screen
	        self.paintToPixmap()
	    
	else :
	        #// Other tools are drawed on pixmap in mouseReleaseEvent
	        #// Draw ongoing drawing
	        	self.p2 = event.pos()
	        #// Update screen
			#self.paintToPixmap()
			self.update()
	    







   def mouseReleaseEvent(self,event):
	self.showcircles=False
	if (event.buttons() & Qt.LeftButton) and self.mousepressed:
        #   self.drawLineTo(event.pos())
	   self.mousepressed=False
	   
	#if (toolbar->downButton() == ToolBarButton::EPen):setAttribute(Qt::WA_OpaquePaintEvent, false)
	    #// Drawing finished. Update pixmap (paper)
	    #// Paint to pixmap and then pixmap on screen
	   self.paintToPixmap()
	   self.p1 = QPoint(-1, -1)
	   self.p2 = QPoint(-1, -1)
	   #toolbar->setVisible(true)
	   repaint()


   def saveForUndo(self):
	    self.undoPixmap = None;
	    #// Copy current image for undo
	    self.undoPixmap = self.pixmap.copy();


   def undo(self):
    #// Take stored previous image in use
    if (not self.undoPixmap==None): 
        self.pixmap = self.undoPixmap.copy()
        self.undoPixmap = None
        #// Update screen
        self.update()
    

   def paintToPixmap(self):

	#// Paint to pixmap (paper)
	painter=QPainter()
	painter.begin(self.pixmap)
	painter.setRenderHint(QPainter.Antialiasing)

	painter.setPen(self.pen)

	if self.inputmode=="sketch":#(toolbar->downButton() == ToolBarButton::EPen || toolbar->downButton()== ToolBarButton::ELine)
		self.paintLine(painter)
	else: #self.inputmode=="auto":
	        self.paintAuto(painter)
		
	painter.end()
	#// Draw pixmap on the screen
	self.update()
	

   def paintLine(self, painter):
	if (self.p1.x() != -1 and self.p2.x() != -1):
	   painter.pen=self.pen
	   #.setColor(self.parent.conf.pen_color)
	   #painter.setSize(self.parent.conf.defaultpen_size)
           painter.drawLine(self.p1, self.p2);

   def paintAuto(self, painter):
	from math import atan, degrees
#	from random import choice
    	if (self.p2.x() != -1): 
		orig=QPoint(400,175)
		self.orig=orig
		pm=QPoint((self.p1.x()+self.p2.x())/2,(self.p1.y()+self.p2.y())/2)
		


		painter.setFont(self.parent.conf.font)#QFont("Arial", 8))
		#print self.parent.conf.font##############################################################debugline
		painter.drawText(pm, self.text)
		radi=self.getRadi()
		if radi<self.parent.conf.g_rad_inner:
			self.angles_time(self.parent.conf.g_scale_inner)
			if self.showcircles:
				painter.setBrush(Qt.yellow)
				painter.setOpacity(self.parent.conf.ellipse_opacity)
				#painter.setBrush(Qt.CrossPattern)
				painter.drawEllipse(orig, self.parent.conf.g_rad_inner,self.parent.conf.g_rad_inner)
				#painter.fillPath(a,Qt.cyan)
		elif radi>=self.parent.conf.g_rad_inner and radi <self.parent.conf.g_rad_middle:
			if self.showcircles:
				painter.setBrush(Qt.cyan)
				painter.setOpacity(self.parent.conf.ellipse_opacity)#0.15
				#painter.setBrush(Qt.Dense7Pattern)
				painter.drawEllipse(orig, self.parent.conf.g_rad_middle,self.parent.conf.g_rad_middle)			
			self.angles_time(self.parent.conf.g_scale_middle)
		else:
				self.angles_time(self.parent.conf.g_scale_outer)
		rect=QRect(0,0,800,350)#orig,self.p2)

		painter.save()
		painter.setBrush(self.parent.conf.pie_color)
		painter.setOpacity(self.parent.conf.ellipse_opacity)#0.15
		rect2=QRect(orig.x()-radi,orig.y()-radi,2*radi,2*radi)#(orig.x()-self.p2.x(),orig.y()-self.p2.y(),2*radi,2*radi)
		if self.spantu <0:self.spantu=360+self.spantu
		#elif self.spantu>360:self.spantu=self.spantu -360
		#painter.drawRect(rect2)
		painter.drawPie(rect2, (-self.start_angle)*16, (self.spantu-360)*16)
		painter.restore()

		#painter.drawEllipse(orig, 300,300)
		start_time=str(self.t0)
		end_time=str(self.t1)
		painter.setOpacity(1.0)
		painter.drawText(self.p1,start_time)
		painter.drawText(self.p2,end_time)

		#eyecandy.drawarea(self.orig, )
		
   def drawLineTo(self,endpoint):
	painter=QPainter()
	painter.begin(self.image)
	#self.pen = QPen(Qt.black, 4, Qt.SolidLine)
	#self.pen.setColor(self.parent.conf.pen_color)
        painter.setPen(self.pen)
	painter.drawLine(self.lastpoint, endpoint)
	painter.end()
	self.update()
	rad = 4#self.myPenWidth / 2
        self.update(QRect(self.lastpoint, endpoint).normalized()
                                        .adjusted(-rad, -rad, +rad, +rad))
        self.lastpoint = QPoint(endpoint)

   def resizeEvent(self, event):
        if self.width() > self.image.width() or self.height() > self.image.height():
            newWidth = max(self.width() + 128, self.image.width())
            newHeight = max(self.height() + 128, self.image.height())
            self.resizeImage(self.image, QSize(newWidth, newHeight))
            self.update()

        QWidget.resizeEvent(self, event)

   def setmode(self, mode):#, event):
	#print "uff"
	if mode=="sketch": self.inputmode="sketch"
	else: self.inputmode="auto"
	#	print "cacca"
	#else:
	#	self.inputmode="auto"
   
   def settext(self, text):
	self.text=text

   def color(self):
	from random import choice
	color=choice(self.colorlist)#[Qt.blue,Qt.black,Qt.red,Qt.green])
	self.parent.conf.pen_color=color
		
   def setdate(self, date):
	self.date=date.toString("yyyyMMdd")
	#check if a file already exist, then, if not
	self.parent.clear()
	print self.date
	#self.update()

   def validate(self):
	self.paintToPixmap()
	self.update()

   def angles_det(self,p,o):
	from todoy_otherfuns import anglescheck2
	#from todoy_otherfuns import distance	
	px= p.x() -o.x()
	py= p.y() -o.y()
	alpha=anglescheck2(px,py)
	return alpha

   def getRadi(self):
	from todoy_otherfuns import distance
	radi=distance(self.orig.x(),self.orig.y(),self.p2.x(),self.p2.y())
	return radi

   def angles(self):
	oOp1=self.angles_det(self.p1, self.orig)
	oOp2=self.angles_det(self.p2, self.orig)
	#if self.p1.y()>self.orig.x():
	self.start_angle=oOp1
	#else:
	#	self.start_angle=oOp1
	self.spantu=(oOp1-oOp2)
	self.span_angle= (oOp1+oOp2) # should check this one for various cases

   def angles_time(self, step):
	from todoy_otherfuns import time_conv
	self.angles()
	self.t0=((self.start_angle+90)/30)%12 #yep!
	self.t1=((self.span_angle-self.start_angle+90)/30)%12#yep!
	self.t0=time_conv(self.t0, step)
	self.t1=time_conv(self.t1, step)

