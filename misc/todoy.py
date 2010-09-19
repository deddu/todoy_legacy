
import sys
from PyQt4 import *
from PyQt4.QtCore import *
from PyQt4.QtGui import *
from time import *
#from todoyUi import Ui_MainWindow

class TodoyArea(QWidget):
    def __init__(self, parent = None):
        QWidget.__init__(self, parent)

        self.setAttribute(Qt.WA_StaticContents)
        self.modified = False
        self.scribbling = False
        self.myPenWidth = 1
        self.myPenColor = Qt.blue
        self.image = QImage()
        self.lastPoint = QPoint()
	self.setWindowTitle("Todoy")
	#self.openImage("todoy_bkgrnd.png")

    def openImage(self, fileName):
        loadedImage = QImage()
        if not loadedImage.load(fileName):
            return False

        newSize = loadedImage.size().expandedTo(self.size())
        self.resizeImage(loadedImage, newSize)
        self.image = loadedImage
        self.modified = False
        self.update()
        return True

    def saveImage(self, fileName, fileFormat):
        visibleImage = self.image
        self.resizeImage(visibleImage, self.size())

        if visibleImage.save(fileName, fileFormat):
            self.modified = False
            return True
        else:
            return False

    def setPenColor(self, newColor):
        self.myPenColor = newColor

    def setPenWidth(self, newWidth):
        self.myPenWidth = newWidth

    def clearImage(self):
        self.image.fill(qRgb(255, 255, 255))
        self.modified = True
        self.update()

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
	today=strftime("%a, %d %b %Y",gmtime())
        painter.setFont(QFont("Arial", 15))
        painter.drawText(0,20, today)
        #painter.drawImage(QRectF(10.0,20.0,60.0,80.0),self.image,QRectF(0.0,0.0,70.0,40.0))
        painter.end()

    def resizeEvent(self, event):
        if self.width() > self.image.width() or self.height() > self.image.height():
            newWidth = max(self.width() + 128, self.image.width())
            newHeight = max(self.height() + 128, self.image.height())
            self.resizeImage(self.image, QSize(newWidth, newHeight))
            self.update()

        QWidget.resizeEvent(self, event)

    def drawLineTo(self, endPoint):
        painter = QPainter()
        painter.begin(self.image)
        painter.setPen(QPen(self.myPenColor, self.myPenWidth,
                                  Qt.SolidLine, Qt.RoundCap,
                                  Qt.RoundJoin))
        painter.setRenderHint(painter.Antialiasing,True)
        #print "last point",self.lastPoint.x()
        #print "endpoint",endPoint
        painter.drawLine(self.lastPoint, endPoint)
        painter.end()
        self.modified = True

        rad = self.myPenWidth / 2
        self.update(QRect(self.lastPoint, endPoint).normalized()
                                        .adjusted(-rad, -rad, +rad, +rad))
        self.lastPoint = QPoint(endPoint)
        
        

    def resizeImage(self, image, newSize):
        if image.size() == newSize:
            return

        newImage = QImage(newSize, QImage.Format_RGB32)
        newImage.fill(qRgb(255, 255, 255))
        painter = QPainter()
        painter.begin(newImage)
        painter.drawImage(QPoint(0, 0), image)
        painter.end()
        self.image = newImage
    
    def isModified(self):
        return self.modified

    def penColor(self):
        return self.myPenColor

    def penWidth(self):
        return self.myPenWidth


class MainWindow(QMainWindow):
    def __init__(self, parent = None):
        QMainWindow.__init__(self, parent)
        #self.ui=Ui_MainWindow()#QWidget() 
        #self.ui.setupUi(self)
        self.saveAsActs = []

        self.todoyArea = TodoyArea()
        self.setCentralWidget(self.todoyArea)
	self.firstopen()

        self.createActions()
        self.createMenus()

        self.setWindowTitle(self.tr("Edit"))
        self.resize(640,480)

    def closeEvent(self, event):
        if self.maybeSave():
            event.accept()
        else:
            event.ignore()

    def open(self):
        if self.maybeSave():
            fileName = QFileDialog.getOpenFileName(self,
                                                         self.tr("Open File"),
                                                         QDir.currentPath())
            if not fileName.isEmpty():
                self.todoyArea.openImage(fileName)

    def firstopen(self):
	self.todoyArea.openImage("todoy_bkgrnd.png")

    def save(self):
        action = self.sender()
        fileFormat = action.data().toByteArray()
        self.saveFile(fileFormat)

    def selectcolor(self):
        newColor = QColorDialog.getColor(self.todoyArea.penColor())
        if newColor.isValid():
            self.todoyArea.setPenColor(newColor)
            self.setCursor(QCursor(Qt.ArrowCursor))

    def penWidth(self):
        newWidth, ok = QInputDialog.getInteger(self, self.tr("Todoy"),
                                               self.tr("Select pen width:"),
                                               self.todoyArea.penWidth(),
                                               1, 50, 1)
        
        if ok:
            self.todoyArea.setPenWidth(newWidth)
            self.setCursor(QCursor(Qt.PointingHandCursor))

    def drawrectangle(self):
        
        self.setCursor(QCursor(Qt.CrossCursor))

        print "draw rectangle"     
         
          
            
    """
    def about(self):
        QMessageBox.about(self, self.tr("About Todoy"), self.tr(
          "<p>The <b>Todoy</b> example shows how to use QMainWindow as the "
          "base widget for an application, and how to reimplement some of "
          "QWidget's event handlers to receive the events generated for "
          "the application's widgets:</p><p> We reimplement the mouse event "
          "handlers to facilitate drawing, the paint event handler to "
          "update the application and the resize event handler to optimize "
          "the application's appearance. In addition we reimplement the "
          "close event handler to intercept the close events before "
          "terminating the application.</p><p> The example also demonstrates "
          "how to use QPainter to draw an image in real time, as well as "
          "to repaint widgets.</p>"))
    """
    
    def createActions(self):
        self.openAct = QAction(self.tr("&Open..."), self)
        self.openAct.setShortcut(self.tr("Ctrl+O"))
        self.connect(self.openAct, SIGNAL("triggered()"), self.open)

        for format in QImageWriter.supportedImageFormats():
            text = self.tr("%1...").arg(QString(format).toUpper())

            action = QAction(text, self)
            action.setData(QVariant(format))
            self.connect(action, SIGNAL("triggered()"), self.save)
            self.saveAsActs.append(action)

        self.exitAct = QAction(self.tr("E&xit"), self)
        self.exitAct.setShortcut(self.tr("Ctrl+Q"))
        self.connect(self.exitAct, SIGNAL("triggered()"),
                     self, SLOT("close()"))

        self.selectcolorAct = QAction(self.tr("&Select Color..."), self)
        self.connect(self.selectcolorAct, SIGNAL("triggered()"),
                     self.selectcolor)

        self.penWidthAct = QAction(self.tr("Pen &Width..."), self)
        self.connect(self.penWidthAct, SIGNAL("triggered()"),
                     self.penWidth)
        
        self.textBoxAct=QAction(self.tr("Draw Rectangle"),self)
        self.connect(self.textBoxAct,SIGNAL("triggered()"),
                     self.drawrectangle)

        self.clearScreenAct = QAction(self.tr("&Clear Screen"), self)
        self.clearScreenAct.setShortcut(self.tr("Ctrl+L"))
        self.connect(self.clearScreenAct, SIGNAL("triggered()"),
                     self.todoyArea.clearImage)

        #self.aboutAct = QAction(self.tr("&About"), self)
        #self.connect(self.aboutAct, SIGNAL("triggered()"), self.about)

        #self.aboutQtAct = QAction(self.tr("About &Qt"), self)
       # self.connect(self.aboutQtAct, SIGNAL("triggered()"),
        #             qApp, SLOT("aboutQt()"))

    def createMenus(self):
        self.saveAsMenu = QMenu(self.tr("&Save As"), self)
        for action in self.saveAsActs:
            self.saveAsMenu.addAction(action)

        self.fileMenu = QMenu(self.tr("&File"), self)
        self.fileMenu.addAction(self.openAct)
        self.fileMenu.addMenu(self.saveAsMenu)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.exitAct)

        self.optionMenu = QMenu(self.tr("&Options"), self)
        self.optionMenu.addAction(self.selectcolorAct)
        self.optionMenu.addAction(self.penWidthAct)
        self.optionMenu.addAction(self.textBoxAct)
        self.optionMenu.addSeparator()
        self.optionMenu.addAction(self.clearScreenAct)

        #self.helpMenu = QMenu(self.tr("&Help"), self)
        #self.helpMenu.addAction(self.Act)
       # self.helpMenu.addAction(self.QtAct)

        self.menuBar().addMenu(self.fileMenu)
        self.menuBar().addMenu(self.optionMenu)
        #self.menuBar().addMenu(self.helpMenu)

    def maybeSave(self):
        if self.todoyArea.isModified():
            ret = QMessageBox.warning(self, self.tr("Edit"),
                        self.tr("The image has been modified.\n"
                                "Do you want to save your changes?"),
                        QMessageBox.Yes | QMessageBox.Default,
                        QMessageBox.No,
                        QMessageBox.Cancel | QMessageBox.Escape)
            if ret == QMessageBox.Yes:
                return self.saveFile("png")
            elif ret == QMessageBox.Cancel:
                return False

        return True

    def saveFile(self, fileFormat):
        initialPath = QDir.currentPath() + "/untitled." + fileFormat

        fileName = QFileDialog.getSaveFileName(self, self.tr("Save As"),
                                    initialPath,
                                    self.tr("%1 Files (*.%2);;All Files (*)")
                                    .arg(QString(fileFormat.toUpper()))
                                    .arg(QString(fileFormat)))
        if fileName.isEmpty():
            return False
        else:
            return self.todoyArea.saveImage(fileName, fileFormat)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
