#! /usr/bin/env python

from math import pi
import cairo
import gtk
import hildondesktop

class hw_home_applet_c(hildondesktop.HomePluginItem):
    '''
    __gsignals__ = {
        'realize' : 'override',
        'expose-event' : 'override',
        }
    '''
    def __init__(s):
        hildondesktop.HomePluginItem.__init__(s)
        pb = gtk.gdk.pixbuf_new_from_file('/home/user/src/demos/images/gnome-gimp.png')
        i = gtk.Image()
        s.set_size_request(90,90)
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
