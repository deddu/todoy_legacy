from PyQt4.QtGui import *
from PyQt4.QtCore import *
import sys
class myLineItem(QGraphicsLineItem):
    def __init__(self,line):
        QGraphicsLineItem.__init__(self,line)
    def paint(self, painter, options, widget):
        print "Painting"
        QGraphicsLineItem.paint(self, painter,options,widget)
        #self.setPen(QPen(Qt.red))
app=QApplication(sys.argv)
scene=QGraphicsScene()
l=myLineItem(QLineF(0,0,20,20))
scene.addItem(l)
view= QGraphicsView(scene)
view.show();
app.exec_()
