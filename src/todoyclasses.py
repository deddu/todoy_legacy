#Todoyclasses.py
from PyQt4.QtGui import *

class TodoyTextItem(QGraphicsItem):
   #def __init__(self):
   #  self.setFlag(self.ItemIsMovable)
   #  self.setFlag(self.ItemIsSelectable)
 

 #QVariant DiagramTextItem::
#   def itemChange(self, GraphicsItemChange change,const QVariant &value):
   def itemChange(self, change, value):
      if (change == self.ItemSelectedHasChanged):
         emit(selectedChange())
      return value
 
#   def focusOutEvent(self, QFocusEvent event)
   def focusOutEvent(self, event):
 
     self.setTextInteractionFlags(Qt.NoTextInteraction)
     emit(lostFocus())
     self.QGraphicsTextItem.focusOutEvent(event)
 

 #void DiagramTextItem::
#   def mouseDoubleClickEvent(self, QGraphicsSceneMouseEvent *event):
   def mouseDoubleClickEvent(self, event):
      if (textInteractionFlags() == Qt.NoTextInteraction):
         self.setTextInteractionFlags(Qt.TextEditorInteraction)
      self.QGraphicsTextItem.mouseDoubleClickEvent(event)
 
