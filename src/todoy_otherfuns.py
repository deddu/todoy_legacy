#todoy_otherfuns.py

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

def angle_from_sides_deg(a,b,c):
	from math import acos, degrees
	#alpha=acos((b**2+c**2-a**2)/(2*b*c))
	alpha=acos(0.5 *(b/c + c/b - a**2/(b*c)))
	alpha=degrees(alpha)
	return alpha

def distance(ax,ay,bx,by):
	from math import sqrt
	distance=sqrt((ax-bx)**2+(ay-by)**2)
	return distance

def anglescheck2(px,py):
	#should be smart to input the point relative to desired origin.
	import math
	#split in 4 trigon regions
	radius=math.sqrt(px**2+py**2)
	if px >=0 and py>=0:	angle=math.asin(py/radius)
	elif py<0 and px>0:	angle=2*math.pi-math.acos(px/radius)
	elif py<0 and px<0:	angle=math.pi+math.asin(-py/radius)
	else: angle=math.pi-math.asin(py/radius) #px<0 py>0 :)
	angle=math.degrees(angle)
	return angle

def angles_from_pos(self,p,o):
	from todoy_otherfuns import angle_from_sides_deg
	from todoy_otherfuns import distance	
	
	a=distance(p.x(),p.y(),0,0)
	c=distance(o.x(),o.y(),0,0)
	b=distance(p.x(),p.y(),o.x(),o.y())
	ahh = 59.0362434679
	alpha=angle_from_sides_deg(a,b,c)-ahh 
	return alpha

def time_conv(time, step=1):
	from math import floor
	excess=time-floor(time)
	spareh=0
	minutes=(round((60/step)*excess)*step)%60
	#looks ugly but it works: rounding the first part generate an int between 0 and 60/step. then multiplying by step after rounding grants that 		the time will be again in minutes. and the final modulo accounts that there are no difference between 60 and 00. 
	#print minutes
	#if excess>=0.60: spareh=1
	hours=floor((time+spareh)%24) 
	#print hours, minutes
	mins="0"+str(int(minutes))
	mins=mins[-2:]
	when="0"+str(int(hours))+mins
	when=when[-4:]
	return when#hours, minutes

def time_conv2(time, step=1, starttime=8):
	from math import floor
	excess=time-floor(time)
	spareh=0
	minutes=(round((60/step)*excess)*step)%60
	#looks ugly but it works: rounding the first part generate an int between 0 and 60/step. then multiplying by step after rounding grants that 		the time will be again in minutes. and the final modulo accounts that there are no difference between 60 and 00. 
	#print minutes
	#if excess>=0.60: spareh=1
	hours=floor((time+spareh)%12)#%24) 
	if hours<starttime:
		hours=hours+12
	#print hours, minutes
	mins="0"+str(int(minutes))
	mins=mins[-2:]
	when="0"+str(int(hours))+mins
	when=when[-4:]
	return when#hours, minutes




def angles(self):
	oOp1=self.angles_from_pos(self.p1, self.orig)
	oOp2=self.angles_from_pos(self.p2, self.orig)
	#if self.p1.y()>self.orig.x():
	self.start_angle=oOp1
	#else:
	#	self.start_angle=oOp1
	self.span_angle=oOp1+oOp2 # should check this one for various cases

def angles_time(self):
	self.angles()
	self.t0=(self.start_angle -90) #yep!
