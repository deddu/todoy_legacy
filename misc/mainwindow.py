# -*- coding: utf-8 -*-

"""
Module implementing MainWindow.
"""

from PyQt4.QtGui import QMainWindow
from PyQt4.QtCore import pyqtSignature

from Ui_todoy import Ui_MainWindow

class MainWindow(QMainWindow, Ui_MainWindow):
    """
    Class documentation goes here.
    """
    def __init__(self, parent = None):
        """
        Constructor
        """
        QMainWindow.__init__(self, parent)
        self.setupUi(self)
        #self.dateEdit.selectAll()
        #self.connect(self.dateEdit,  SIGNAL("returnPressed"),  self.updateUi)
        self.setWindowTitle("todoy")
    
    @pyqtSignature("QDate")
    def on_dateEdit_dateChanged(self, date):
        """
        Slot documentation goes here.
        """
        # TODO: not implemented yet
        raise NotImplementedError
        
   
