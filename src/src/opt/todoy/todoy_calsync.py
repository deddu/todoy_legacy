#todoy_calsync.py
class cal_handling():
   def __init__(self):
	import os
	self.filename="/home/user/.todoy/todoy.ics"
	if not os.path.exists(self.filename):
		self.cal_create()
		print False
	else: print True
	self.summary="yay!"
	self.date=20100921
	self.start=1130
	self.end=1230

   def add_event(self):
	f = open( self.filename, 'r+b' )
	lines = f.readlines()
	f.close()

	f = open( self.filename,'w+b' )
	#f.write( '\n'.join( lines[1:] ) )
	f.writelines(lines[:-1])
	f.close()
	
	f=open(self.filename,'a+b')
	f.write('BEGIN:VEVENT')
	f.write('\nCATEGORIES:MEETING')
	f.write('\nSTATUS:TENTATIVE')
	f.write('\nDTSTART:')
	f.write(self.gen_time_string(self.date,self.start))	#(20100921T033000Z')
	f.write('\nDTEND:')
	f.write(self.gen_time_string(self.date,self.end))#(20100921T043000Z')
	f.write('\nSUMMARY:')
	f.write(self.summary)#(Your Proposal Review')
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

 


