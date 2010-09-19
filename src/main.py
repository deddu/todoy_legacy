import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import strftime, gmtime
from todoyUI import Ui_MainWindow
from todoypage import TodoyPage



class Main(QMainWindow):
   def __init__(self):
         QMainWindow.__init__(self)
         self.ui=Ui_MainWindow()#QWidget() 
         self.ui.setupUi(self)
	 self.todoypage=TodoyPage(self)
	 try:
            self.setAttribute(Qt.WA_Maemo5StackedWindow)
            USE_MAEMO = True
         except:
            USE_MAEMO = False

   def keyPressEvent (self, QKeyEvent):
	#if QKeyEvent.matches (self, QKeySequence.StandardKey)
	if QKeyEvent.key()==Qt.Key_Q:
		print "ye" #implement close!
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
		self.todoypage.openPixmap("todoy_bkgrnd.png")
	elif QKeyEvent.key()==Qt.Key_W:
		self.todoypage.pen = QPen(Qt.white, 10, Qt.SolidLine)
	elif QKeyEvent.key()==Qt.Key_Z:
		self.todoypage.undo()
	elif QKeyEvent.key()==Qt.Key_S:
		self.todoypage.save()
	elif QKeyEvent.key()==Qt.Key_L:
		self.todoypage.load()




def main():
     app = QApplication(sys.argv)
     window=Main()
     window.show()
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()
