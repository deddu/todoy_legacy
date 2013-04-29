import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import strftime, gmtime#*
#duplicate bkgrnd
#and zoom out picture in widget
#class TodoyArea(QWidget):
""" todoy.py 
    for the moment just a simple paint program with a bkground"""
USE_MAEMO = False


#class showWindowQtGui.QMainWindow):
#    def __init__(self, parent=None):
#        QtGui.QWidget.__init__(self, parent)
#        
#        self.ui = Ui_main_window()
#        self.ui.setupUi(self)
#        try:
#            self.setAttribute(Qt.WA_Maemo5StackedWindow)
#            USE_MAEMO = True
#        except:
#            USE_MAEMO = False

class Main(QMainWindow):
   def __init__(self):
         QMainWindow.__init__(self)
	 self.mousepressed=False
	 self.pixmap=QPixmap()
	 self.undoPixmap=QPixmap()
	 self.image = QImage()
         #self.lastPoint = QPoint()
	 self.setWindowTitle("Todoy")
         self.resize(640,480)
	 self.openImage("todoy_bkgrnd.png")
	 self.openPixmap("todoy_bkgrnd.png")
	 self.pen=QPen(Qt.black, 4, Qt.SolidLine)
	 self.p1 = QPoint(-1, -1);
	 self.p2 = QPoint(-1, -1);
	 #self.menu=QMenuBar()
	 #cacca=QAction(self)#QString("cacca"))
	 #self.menu.addAction(cacca)
	 #self.menu.show()
         try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
            USE_MAEMO = True
         except:
            USE_MAEMO = False

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
	today=strftime("%Y%m%d",gmtime())+".png"
	self.pixmap.save(today)

   def load(self):
	today=strftime("%Y%m%d",gmtime())+".png"
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
	today=strftime("%a, %d %b %Y",gmtime())
        p.setFont(QFont("Arial", 15))
        p.drawText(0,20, today)
	infos=("Q: Quit, C: Clear, B: Blue, R: Red, G: Green, K: Black, Z: Undo.")
	p.drawText(0,40, infos)
	pen=self.pen#QPen()
	draftPen=QPen()
	#color = QColor(Qt.black)
	#pen.setColor(color)
	#pen.setStyle(Qt.SolidLine)
	draftPen.setColor(Qt.black)
	draftPen.setStyle(Qt.DashLine)
	draftPen.setWidth(1)




	#p.drawImage(QPoint(0,0),self.image)
	p.drawPixmap(QPoint(0, 0), self.pixmap);
	if self.mousepressed:#(toolbar->downButton() != ToolBarButton::EPen)
   		p.setPen(draftPen); #// ongoing drawing, not final (waiting for mouseRelease)
        	if True:#(toolbar->downButton() == ToolBarButton::ELine)
        		self.paintLine(p);


	p.end()
	
   def mousePressEvent(self,ev):
	if (ev.buttons()& Qt.LeftButton):
		#self.lastpoint=ev.pos()
		self.mousepressed=True
		self.p1 = ev.pos()
    		self.p2 = QPoint(-1, -1)    
		self.saveForUndo()





   def mouseMoveEvent(self, event):
	if (event.buttons() & Qt.LeftButton) and self.mousepressed:
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

	#if (toolbar->downButton() == ToolBarButton::EPen || toolbar->downButton()== ToolBarButton::ELine)
	self.paintLine(painter)
#	else if (toolbar->downButton() == ToolBarButton::EErase)
#	    paintPoint(painter)
#	else if (toolbar->downButton() == ToolBarButton::ERectangle)
#	    paintRect(painter)
#	else if (toolbar->downButton() == ToolBarButton::ECircle)
#	    paintCircle(painter)

	painter.end()
	#// Draw pixmap on the screen
	self.update()
	

   def paintLine(self, painter):
	if (self.p1.x() != -1 and self.p2.x() != -1):
	   #painter.pen=self.pen
           painter.drawLine(self.p1, self.p2);
    


#void Widget::paintPoint(QPainter& painter)
#{
#    if (p1.x() != -1) {
#        QPoint p = p1;
#        p.setX(p.x() - 5);
#        p.setY(p.y() - 5);
#        painter.fillRect(QRect(p, QSize(10, 10)), Qt::white);
#    }
#}









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

   def checkKeys(self, event):
	pass
   
   def keyPressEvent (self, QKeyEvent):
	#if QKeyEvent.matches (self, QKeySequence.StandardKey)
	if QKeyEvent.key()==Qt.Key_Q:
		print "ye" #implement close!
	elif QKeyEvent.key()==Qt.Key_B:
		self.pen = QPen(Qt.blue, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_R:
		self.pen = QPen(Qt.red, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_G:
		self.pen = QPen(Qt.green, 4, Qt.SolidLine)
		#self.update()
	elif QKeyEvent.key()==Qt.Key_K:
		self.pen = QPen(Qt.black, 4, Qt.SolidLine)
	elif QKeyEvent.key()==Qt.Key_C:
		self.openPixmap("todoy_bkgrnd.png")
	elif QKeyEvent.key()==Qt.Key_W:
		self.pen = QPen(Qt.white, 10, Qt.SolidLine)
	elif QKeyEvent.key()==Qt.Key_Z:
		self.undo()
	elif QKeyEvent.key()==Qt.Key_S:
		self.save()
	elif QKeyEvent.key()==Qt.Key_L:
		self.load()

		#implement_delete_all
		pass
	
	self.update()




def main():
     app = QApplication(sys.argv)
     window=Main()
     window.show()
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()
