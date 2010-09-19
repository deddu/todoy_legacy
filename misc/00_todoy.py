# -*- coding: utf-8 -*-

"""The user interface for our app"""

import os,sys

# Import Qt modules
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import *

# Import the compiled UI module
from todoyUi import Ui_MainWindow

# Create a class for our main window
class Main(QMainWindow):
     def __init__(self):
         QMainWindow.__init__(self)

         # This is always the same
         self.ui=Ui_MainWindow()#QWidget() 
         self.ui.setupUi(self)
	 self.setWindowTitle("Todoy")
	 #self.setMouseTracking(True)
	 self.p1= QPoint(0,0)
	 self.p2= QPoint(0,0)
	 self.seq=[]
	 self.mouseispressed = False
         self.image = QImage()
	 #self.connect(self.paintEvent, SIGNAL("mouseMoveEvent"), self.paintEvent)
     
#     def paintEvent(self, ev):
#        self.p = QPainter(self)
#	today=strftime("%a, %d %b %Y",gmtime())
#        self.p.setFont(QFont("Arial", 15))
#        self.p.drawText(0,20, today)
#	#self.p.setPen(QColor(0,0,255))
#	pen = QPen(Qt.black, 2, Qt.SolidLine)
#	self.p.setPen(pen)
#	#self.p.setPen(10)
#	#self.p.setBrush(QColor(10,10,255))
#	#a=QPoint(100,100)
#	#b=self.point#QPoint(0,0)
#	#b.setX=0
#	#b.setY=0
#	#p.drawPoints(self.pointlist)
#        self.p.drawLine(self.p1,self.p2)
#	line=[self.p1,self.p2]
#	self.seq.append(line)
#	p.drawLines(self.seq)
#	#if self.mouseispressed:
#	#print "press" #p.drawPoint(self.point)
#	p.end()
#	
	

#     def mouseMoveEvent(self, ev):
#	if self.mouseispressed:	

#		#self.pointnew.setX(ev.x())
#		#self.pointnew.setY(ev.y())
##		x1=self.x1
##		y1=self.y1
##		x2=ev.x()
##		y2=ev.y()
##		self.p1= QPoint(x1,y1)
##		self.p2= QPoint(x2,y2)
#		#self.p.setPen(QColor(255,255,255))
#		#self.p.drawLine(p1,p2)#self.pointold,self.pointnew)
#		#self.pointlist.append(self.point)
#		self.update()#print self.point
#		#self.pointnew=self.pointold
#		x1=x2
#		y1=y2
##	pass

#     def mousePressEvent(self, ev):
#	#self.pointold=QPoint()
#	#self.pointold.setX(ev.x())
#	#self.pointold.setY(ev.y())
#	#print self.startpoint
#	#self.x1=ev.x()
#	#self.y1=ev.y()
#	if ev.button()=Qt.LeftButton:
#		self.p1 = event.pos()
#		self.mouseispressed=True

#     def mouseReleaseEvent(self, ev):
#	self.mouseispressed=False
#	#self.endpoint=QPoint()
#	#self.endpoint.setX(ev.x())
#	#self.endpoint.setY(ev.y())
#	self.update()


     def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.lastPoint = event.pos()
            self.scribbling = True

     def mouseMoveEvent(self, event):
        if (event.buttons() & Qt.LeftButton) and self.scribbling:
         #if (event.buttons() & Qt.LeftButton):
         self.drawLineTo(event.pos())
            
     def mouseReleaseEvent(self, event):
        if event.button() == Qt.LeftButton and self.scribbling:
            self.drawLineTo(event.pos())
            self.scribbling = False

     def paintEvent(self, event):
        painter = QPainter()
        painter.begin(self)
        painter.drawImage(QPoint(0, 0), self.image)
        #painter.drawImage(QtCore.QRectF(10.0,20.0,60.0,80.0),self.image,QtCore.QRectF(0.0,0.0,70.0,40.0))
        painter.end()


     def drawLineTo(self, endPoint):
        painter = QPainter()
        painter.begin(self)
	pen = QPen(Qt.black, 4, Qt.SolidLine)
        painter.setPen(pen)
        painter.setRenderHint(painter.Antialiasing,True)
        print "last point",self.lastPoint.x()
        print "endpoint",endPoint
        painter.drawLine(self.lastPoint, endPoint)
        painter.end()
        #self.modified = True

        rad = 4#self.myPenWidth / 2
        self.update(QRect(self.lastPoint, endPoint).normalized()
                                        .adjusted(-rad, -rad, +rad, +rad))
        self.lastPoint = QPoint(endPoint)	

        
	

def main():
     # Again, this is boilerplate, it's going to be the same on
     # almost every app you write
     app = QApplication(sys.argv)
     window=Main()
     window.show()
     # It's exec_ because exec is a reserved word in Python
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()
