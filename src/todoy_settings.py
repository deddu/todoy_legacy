#!/usr/bin/python

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
#from time import strftime, gmtime
from settingsUI import Ui_Form
#from todoypage import TodoyPage
#import todoy_calsync
from todoy_conf import todoy_config
#from todoy_settings import settings


class Settings(QWidget):
   def __init__(self):
         QWidget.__init__(self)
         self.ui=Ui_Form()#QWidget() 
         self.ui.setupUi(self)



def main():
     app = QApplication(sys.argv)
     window=Settings()
     window.show()
     sys.exit(app.exec_())


if __name__ == "__main__":
     main()

