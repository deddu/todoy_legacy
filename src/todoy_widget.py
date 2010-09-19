from hildon_home_plugin_item import HildonHomePluginItem
import gtk
import time

class MyWidget(HildonHomePluginItem):
    def __init__(self):
        HildonHomePluginItem.__init__(self, header="Todoy_Widget", corner_radius=7)
        self.set_size_request(200, 200)
        body = gtk.Label("This is the body\nline2\nline3")
        self.add(body)
        self.show_all()
        today=time.strftime("%Y%m%d",time.gmtime())+".png"
        fname='./'+today
        pb = gtk.gdk.pixbuf_new_from_file(fname)
        #s.set_size_request(200,200)
        i.set_from_pixbuf(pb)
        i.show_all()
        self.add(i)

hd_plugin_type = MyWidget

if __name__ == '__main__':
    import gobject
    gobject.type_register(hd_plugin_type)
    obj = gobject.new(hd_plugin_type, plugin_id="plugin_id")
    obj.show()
    gtk.main()
