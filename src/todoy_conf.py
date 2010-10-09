#todoy_conf.py

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

################### main conf ########################
class todoy_config():
    def __init__(self):
	from PyQt4 import QtCore, QtGui
	import os

	self.user_path=""#"/home/user/.todoy/"
	self.install_path="/opt/todoy/"

################### auto mode ########################
	self.cal_sync= True
	self.default_mode = "auto"
	self.cal_file="todoy.ics"
	self.default_ev="EVENT"
	self.pie_color=QtCore.Qt.green
	self.pie_randcolor=True#False

################### granulometry #####################
	self.g_rad_inner=100
	self.g_rad_middle=200
	self.g_scale_inner=15
	self.g_scale_middle=5
	self.g_scale_outer=1
	self.starttime=QtCore.QTime(8,0)
################### sketch mode ######################
	self.defaultpen_size=4
	self.pen_color=QtCore.Qt.black
	self.ellipse_opacity=0.15
	self.font=QtGui.QFont("Arial", 15)
	self.bkgrnd="todoy_bkgrnd.png"
	self.colorlist=[QtCore.Qt.black,QtCore.Qt.red,QtCore.Qt.green,QtCore.Qt.blue,QtCore.Qt.yellow,QtCore.Qt.cyan,QtCore.Qt.magenta,QtCore.Qt.darkGreen,QtCore.Qt.darkRed,QtCore.Qt.darkBlue,QtCore.Qt.darkGray]
