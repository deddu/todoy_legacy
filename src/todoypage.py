import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import strftime, gmtime


class TodoyPage(QWidget):
   def __init__(self,parent):
	 QWidget.__init__(self,parent)
	 self.mousepressed=False
	 self.inputmode= "auto"#"sketch"#or auto
	 self.pixmap=QPixmap()
	 self.undoPixmap=QPixmap()
	 self.image = QImage()
	 self.text=""
         #self.lastPoint = QPoint()
	 self.setWindowTitle("Todoy")
         self.resize(800,350)
	 self.openImage("todoy_bkgrnd.png")
	 self.openPixmap("todoy_bkgrnd.png")
	 self.pen=QPen(Qt.black, 4, Qt.SolidLine)
	 self.p1 = QPoint(-1, -1)
	 self.p2 = QPoint(-1, -1)
         self.date=strftime("%Y%m%d",gmtime())

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
	today=self.date+".png"
	self.pixmap.save(today)

   def load(self):
	today=self.date+".png"#strftime("%Y%m%d",gmtime())+".png"
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
        p.setFont(QFont("Arial", 15))
        p.drawText(20,50, self.date)
	infos=("Q: Quit, C: Clear, B: Blue, R: Red, G: Green, K: Black, Z: Undo.")
	p.drawText(20,90, infos)
	pen=self.pen#QPen()
	draftPen=QPen()
	#color = QColor(Qt.black)
	#pen.setColor(color)
	#pen.setStyle(Qt.SolidLine)
	draftPen.setColor(Qt.black)
	draftPen.setStyle(Qt.DashLine)
	draftPen.setWidth(1)
	p.drawPixmap(QPoint(0, 0), self.pixmap);
	if self.mousepressed and self.inputmode=="sketch":#(toolbar->downButton() != ToolBarButton::EPen)
   		p.setPen(draftPen) #// ongoing drawing, not final (waiting for mouseRelease)
        	#if self.inputmode=="sketch":
        	self.paintLine(p)
	if self.mousepressed and self.inputmode=="auto":
	 	self.paintAuto(p)


	p.end()
	
   def mousePressEvent(self,ev):
	if (ev.buttons()& Qt.LeftButton):
		#self.lastpoint=ev.pos()
		self.mousepressed=True
		self.p1 = ev.pos()
    		self.p2 = QPoint(-1, -1)    
		self.saveForUndo()





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
	   #painter.pen=self.pen
           painter.drawLine(self.p1, self.p2);

   def paintAuto(self, painter):
	from math import atan, degrees
    	if (self.p2.x() != -1): 
		orig=QPoint(400,240)
		pm=QPoint((self.p1.x()+self.p2.x())/2,(self.p1.y()+self.p2.y())/2)
		painter.drawLine(orig, self.p1)
		painter.drawLine(orig,self.p2)
		#painter.drawLine(self.p1,self.p2)
		painter.drawText(pm, self.text)
		painter.setFont(QFont("Arial", 8))
		start_time="hhmmyy"
		end_time="totototo"
		painter.drawText(self.p1,start_time)
		painter.drawText(self.p2,end_time)
		
   def drawLineTo(self,endpoint):
	painter=QPainter()
	painter.begin(self.image)
	#self.pen = QPen(Qt.black, 4, Qt.SolidLine)
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

   def setmode(self):#, event):
	#print "uff"
	if self.inputmode=="sketch": self.inputmode="auto"
	else: self.inputmode="sketch"
	#	print "cacca"
	#else:
	#	self.inputmode="auto"
   
   def settext(self, text):
	self.text=text

		#implement_delete_all
		
   def setdate(self, date):
	self.date=date.toString("yyyyMMdd")
	print self.date
	#self.update()

   def validate(self):
	self.paintToPixmap()
	self.update()

