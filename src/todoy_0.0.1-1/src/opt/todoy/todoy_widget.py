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
