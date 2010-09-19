#! /usr/bin/env python

from math import pi
import cairo
import gtk
import hildondesktop
import time
class hw_home_applet_c(hildondesktop.HomePluginItem):
    '''
    __gsignals__ = {
        'realize' : 'override',
        'expose-event' : 'override',
        }
    '''
    def __init__(s):
        hildondesktop.HomePluginItem.__init__(s)
        today=time.strftime("%Y%m%d",time.gmtime())+".png"
        fname='/home/user/MyDocs/DropN900/todoy/src/'+today
        pb = gtk.gdk.pixbuf_new_from_file(fname)
        i = gtk.Image()
        s.set_size_request(300,300)
        i.set_from_pixbuf(pb)
        i.show_all()
        s.add(i)

    def do_expose_event(s, e):
        a = e.area
        cr = s.window.cairo_create()
        cr.arc(a.width/2,a.height/2,a.width/2,0,2*pi)
        cr.set_source_rgba(1.0,0.0,0.0,0.625)
        cr.fill()
        hildondesktop.HomePluginItem.do_expose_event(s,e)

    def do_realize(s):
        scn = s.get_screen()
        cm = scn.get_rgba_colormap()
        s.set_colormap(scn.get_rgba_colormap())
        s.set_app_paintable(True)
        hildondesktop.HomePluginItem.do_realize(s)

hd_plugin_type = hw_home_applet_c

if __name__ == '__main__':
    import gobject
    gobject.type_register(hd_plugin_type)
    obj = gobject.new(hd_plugin_type, plugin_id='plugin_id')
    obj.show_all()
    gtk.main()
