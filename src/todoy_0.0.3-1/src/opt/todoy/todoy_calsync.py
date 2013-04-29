#todoy_calsync.py

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



class cal_handling():
   def __init__(self,conf):
	import os
	self.conf=conf
	self.filename=self.conf.user_path+self.conf.cal_file#"todoy.ics"#"/home/user/.todoy/todoy.ics"
	self.default_event=self.conf.default_ev
	self.cal_sync_on=self.conf.cal_sync

	if not os.path.exists(self.filename):
		self.cal_create()
		print False
	else: print True
	self.summary="yay!"
	self.date=20100921
	self.start=1130
	self.end=1230
	self.eventlist=[]

   def add_event(self):
	if self.cal_sync_on:
		self.eventlist.append([self.date,self.start,self.end,self.summary])


   def parse_events(self):
	f = open( self.filename, 'r+b' )
	lines = f.readlines()
	f.close()

	f = open( self.filename,'w+b' )
	#f.write( '\n'.join( lines[1:] ) )
	f.writelines(lines[:-1])
	f.close()
	
	f=open(self.filename,'a+b')
	for item in self.eventlist:
		date=item[0]
		start=item[1]
		end=item[2]
		summary=item[3]
		f.write('BEGIN:VEVENT')
		f.write('\nCATEGORIES:MEETING')
		f.write('\nSTATUS:TENTATIVE')
		f.write('\nDTSTART:')
		f.write(self.gen_time_string(date,start))	#(20100921T033000Z')
		f.write('\nDTEND:')
		f.write(self.gen_time_string(date,end))#(20100921T043000Z')
		f.write('\nSUMMARY:')
		f.write(summary)#(Your Proposal Review')
		f.write('\nDESCRIPTION:Created with todoy!')
		f.write('\nCLASS:PRIVATE')
		f.write('\nEND:VEVENT')
	f.write('\nEND:VCALENDAR')
	f.close()

   def gen_time_string(self,date,time):
	timestring=str(date) + "T" + str(time) + "00Z"
	return timestring
	pass


   def cal_create(self):
	f=open(self.filename,'w+b')
	f.write('BEGIN:VCALENDAR')
	f.write('\nVERSION:1.0')
	f.write('\nEND:VCALENDAR')
	f.close()
	return True

 


