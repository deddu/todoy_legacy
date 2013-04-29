
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

from hildon_home_plugin_item import HildonHomePluginItem
import gtk
import time

class MyWidget(HildonHomePluginItem):
    def __init__(self):
        HildonHomePluginItem.__init__(self, header=time.strftime("%a, %d %b %y",time.gmtime()), corner_radius=7)
        self.set_size_request(400, 250)
        #body = gtk.Label("This is the body\nline2\nline3")
        #self.add(body)
        self.show_all()
        today=time.strftime("%Y%m%d",time.gmtime())+".png"
        fname='/home/user/.todoy/'+today
        pb = gtk.gdk.pixbuf_new_from_file(fname) #was pixbug
	i = gtk.Image()
	height=(800*2)/3
	width=(480 *2)/3
	scaled_buf = pb.scale_simple(height,width,gtk.gdk.INTERP_BILINEAR)
	#pb.set_size_request(250,250)
        #s.set_size_request(200,200)
        i.set_from_pixbuf(scaled_buf)
        i.show_all()
        self.add(i)

hd_plugin_type = MyWidget

if __name__ == '__main__':
    import gobject
    gobject.type_register(hd_plugin_type)
    obj = gobject.new(hd_plugin_type, plugin_id="plugin_id")
    obj.show()
    gtk.main()
