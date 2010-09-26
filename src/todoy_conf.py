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
	import os

	self.user_path=""#"/home/user/.todoy"
	self.install_path="/opt/todoy"

################### auto mode ########################
	self.cal_sync= True
	self.default_mode = "auto"
	self.cal_file="todoy.ics"
	self.default_ev="event"

################### granulometry #####################
	self.g_rad_inner=100
	self.g_rad_middle=200
	self.g_scale_inner=15
	self.g_scale_middle=5
	self.g_scale_outer=1

################### sketch mode ######################
	self.defaultpen="default"
	self.ellipse_opacity=0.15
	self.font="arial"
	self.bkgrnd="todoy_bkgrnd.png"

