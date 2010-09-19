import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import *

#class TodoyArea(QWidget):
""" todoy.py 
    for the moment just a simple paint program with a bkground"""


class Main(QMainWindow):
   def __init__(self):
         QMainWindow.__init__(self)
	 self.mousepressed=False
	 self.image=QImage()
	 self.image = QImage()
         self.lastPoint = QPoint()
	 self.setWindowTitle("Todoy")
         self.resize(640,480)
	 self.openImage("todoy_bkgrnd.png")
	 self.pen=QPen(Qt.black, 4, Qt.SolidLine)
	 #self.menu=QMenuBar()
	 #cacca=QAction(self)#QString("cacca"))
	 #self.menu.addAction(cacca)
	 #self.menu.show()

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
	infos=("Q: Quit, C: White, B: Blue, R: Red, G: Green, K: Black.")
	p.drawText(0,40, infos)
	p.drawImage(QPoint(0,0),self.image)
	p.end()
	
   def mousePressEvent(self,ev):
	if (ev.buttons()& Qt.LeftButton):
		self.lastpoint=ev.pos()
		self.mousepressed=True

   def mouseMoveEvent(self, event):
	if (event.buttons() & Qt.LeftButton) and self.mousepressed:
           self.drawLineTo(event.pos())

   def mouseReleaseEvent(self,event):
	if (event.buttons() & Qt.LeftButton) and self.mousepressed:
           self.drawLineTo(event.pos())
	   self.mousepressed=False

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
		self.openImage("todoy_bkgrnd.png")
	elif QKeyEvent.key()==Qt.Key_W:
		self.pen = QPen(Qt.white, 10, Qt.SolidLine)
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
