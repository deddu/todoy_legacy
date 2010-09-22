#! /usr/bin/env python

"""
ver 2010 08 30 14
autor Bartlomiej Ceglik
e-mail yoyoek[no spam]wp.pl
"""




################## CONFIGURATION PART ##################
lista_of_icals = [
         #['www.rcspot.pl/meventy_ical.php', 2], # last int is houers offset
         #['www.google.com/meventy_ical.php', 2]
         ]
################## CONFIGURATION PART ##################


def conf_read():
    try:
        f = open('/home/user/.pywebcalai.config','r')
        while f:
            line = f.readline()
            if line:
                tmp = []
                tmp = line.split(' ')
                offset = int( tmp[0] )
                str = tmp[1][:-1]
                print str


                lista_of_icals.append([ str,offset ])
            else:
                break

        print "------config read ----"
        print lista_of_icals
    except:
        pass



def conf_save():
    print "----- config save ---------"
    print lista_of_icals
    f = open('/home/user/.pywebcalai.config','w',0)
    for i in lista_of_icals:
        f.writelines( ("%i %s\n"%( i[1], i[0] )) )

    f.close()


def Info_no_icalendar_found():
    dialog = gtk.Dialog("pyWebCal :: error")
    label = gtk.Label("No icalender found :/ \nYou need to install:\nhttp://codespeak.net/icalendar/")
    dialog.vbox.pack_start(label,1,1,0)
    dialog.show_all()
    error = 1
    dialog.run()


def Info_no_connection():
    dialog = gtk.Dialog("pyWebCal :: error")
    label = gtk.Label("Can't connect to internet / host :/")
    dialog.vbox.pack_start(label,1,1,0)
    dialog.show_all()
    error = 1
    dialog.run()

def Info(str):
    dialog = gtk.Dialog("pyWebCal :: DONE")
    label = gtk.Label(str)
    dialog.vbox.pack_start(label,1,1,0)
    dialog.show_all()
    dialog.run()


import gtk
import pygtk
import gtk.glade
import glib
import hildon
import os


import socket
try:
    from icalendar import Calendar, Event
except:
    Info_no_icalendar_found()

import sqlite3
import time


sql_file = '/home/user/.calendar/calendardb'
sql_debug = 0
error = 0

done_ok = ''


def Read_ical_from_web( host, file ):
    tr = ''

    try:
        s = socket.socket()
        s.connect((host, 80))
    except:
        Info_no_connection()
        return ''
    s.send("""GET """+file+""" HTTP/1.1
Host: """+host+"""


""")

    recive_tmp = ""
    iter = 0
    while iter<500:
        d = s.recv(1024)
        #print '[socket recv]'+d
        if not d:
            break
        else:
            recive_tmp = recive_tmp+d
        if len(recive_tmp.split('END:VCALENDAR'))>1:
            break
        if len(recive_tmp.split("\n0\n\n"))>1 and iter > 0:
            break

        iter = iter + 1

    split_res = recive_tmp.split('BEGIN:VCALENDAR')
    if len(split_res) > 1:
        tr = "BEGIN:VCALENDAR"+split_res[1]
    else:
        return ''

    split_res = tr.split('END:VCALENDAR')
    if len(split_res) > 1:
        tr = split_res[0]+"END:VCALENDAR"
    else:
        return ''

    tr = tr.replace("\r\n1000\r\n", '')
    tr = tr.replace("\r\nb66\r\n", '')
    tr = tr.replace("\r\n ", ' ')
    tr = tr.replace("\n ", ' ')
    tr = tr.replace("\r ",' ')

    return tr


def list_join( list, glut ):
    tr = list[0]
    iter = 0
    for i in list:
        if iter == 0:
            iter = 1
        else:
            tr = tr+glut+i
    return tr

def Sql_query_select_one_value( s_con, s_what, s_from, s_where  ):
    c = s_con.cursor()
    q = 'select '+s_what+' from '+s_from+' where '+s_where+' limit 1'
    if sql_debug:
        print '[q]'+q
    c.execute(q)
    for r in c:
        return '%s'%r

def Sql_insert_correct(s_con, s_id, s_into, s_values, s_vars ):
    c = s_con.cursor()

    vars_tmp = '?'
    for i in range(1,len(s_values)):
        vars_tmp = vars_tmp+',?'
    q = 'insert into '+s_into+' ('+list_join(s_values,',')+') VALUES ('+vars_tmp+')'

    if sql_debug:
        print "[q] [%s]\n[q] [ insert values ]  [%s]" %(q, vars_tmp)

    try:
        count = s_vars[0][0]
        #print "[q] insert get s_var as list!"
        #print "\n-------------\n"+str(s_vars)+"\n-list------------"
        for s in s_vars:
            c.execute(q,s)
    except:
        #print "[q] insert get s_var as singiel record"
        #print "\n-------------\n"+str(s_vars)+"\n-singiel------------"
        c.execute(q,s_vars)

    s_con.commit()

    if s_id<>'':
        return Sql_query_select_one_value( s_con, s_id, s_into, '1 ORDER BY '+s_id+' DESC' )
    else:
        return ''

def Sql_delete(s_con, s_from, s_where ):
    c = s_con.cursor()
    q = 'delete from '+s_from+' where '+s_where
    if sql_debug:
        print '[q]'+q
    c.execute(q)
    s_con.commit()

def ParseStrTime_to_unix( str_time ):
    tr = 0
    try:
        tr = time.mktime(time.strptime(str(str_time),'%Y%m%dT%H%M%SZ' ))
    except:
        try:
            tr = time.mktime(time.strptime(str(str_time),'%Y%m%d' ))
        except:
            tr = time.mktime(time.strptime(str(str_time),'%Y%m%dT%H%M%S' ))
    return tr

def Call_featch_val( item, val_name ):
    try:
        return item[val_name]
    except:
        return ''





def Run_import():
    os.system("dbus-send --type=method_call --dest=org.freedesktop.Notifications /org/freedesktop/Notifications org.freedesktop.Notifications.SystemNoteInfoprint string:\"py web call auto import start it's work...\"")
    global done_ok

    for ical in lista_of_icals:

        subt_host = ical[0].split('/')
        if len(subt_host) > 0:
            ical[0] = subt_host[0]
            ical.append(ical[1])
            ical[1] = ''
            for i in range(1, len(subt_host)):
                 ical[1] = ical[1]+'/'+subt_host[i]
        else:
            ical.append(ical[1])
            ical[1] = '/'

        print "[Start ical iter]    [start]    ["+ical[0]+"] ["+ical[1]+"]"

        ical_str = Read_ical_from_web( ical[0], ical[1]  )
        #ical_str = open('rcspot_calendar.ics','rb').read()
        if ical_str<> '':
            print "[Start ical iter]    [len]   ["+str(len(ical_str))+"]"



            try:
                print "[Start ical iter]    [ical parsing]"
                cal = Calendar.from_string( str(ical_str) )
            except:
                print "error in ical parsing str ---------------------------------"
                print ical_str
                print "---------------- EXITING --------------------------------------------\n"
                break
            cal_name_item = cal.walk("VCALENDAR")
            cal_name = cal_name_item[0]['X-WR-CALNAME']+" (webcal)"
            print "[Start ical iter]    [ical name] ["+cal_name+"]"

            print "[Start ical iter]    [sql try connect]"
            s_con = sqlite3.connect( sql_file )
            cal_id = Sql_query_select_one_value(s_con, 'CalendarId', 'Calendars', 'Name LIKE \''+cal_name+'\'')
            print "[Start ical iter]    [db call exist with id]"+str(cal_id)
            if cal_id == None:
                print "[Start ical iter]    [db insert call]"
                colour = Sql_query_select_one_value(s_con, '(Colour+1)', 'Calendars', '1 ORDER BY Colour DESC')
                cal_id = Sql_insert_correct(s_con,
                                            'CalendarId',
                                            'Calendars',
                                            ['Name',        'Colour','IsVisible','IsReadonly',   'CalendarType','CalendarTune',  'CalendarVersion',  'CalendarProfile'],
                                            [str(cal_name), colour,  '1',         '1',           '0',            '',             '1',                '0']
                                            )
                if cal_id == None:
                    break
                print "[Start ical iter]    [db new call with id]"+str(cal_id)

            print "[Start ical iter]    [db clean present records]"
            Sql_delete(s_con, 'Components', 'CalendarId='+str(cal_id))


            print "[Start ical iter]    [db insert some events :)]"
            count_total = len( cal.walk('vevent') )
            ev_ta = []
            for e in cal.walk('vevent'):
                tStart = ParseStrTime_to_unix(e['dtstart'])+(ical[2]*3600)
                tEnd = ParseStrTime_to_unix(e['dtend'])+(ical[2]*3600)

                location = Call_featch_val(e,'location')
                desc = Call_featch_val(e, 'description')
                ev_ta.append(
                             [cal_id,        '1',                '-1',   tStart,         tEnd,        e['summary'],      location,           desc,               '-1',       '0',        '-1',   '0',    '0',            '0',            ':UTC', '0']
                             )

            print "[Start ical iter]    [db insert %i/%i] [%s]" % (len(ev_ta),count_total, cal_name)
            Sql_insert_correct(s_con,
                        '',
                        'Components',
                        ['CalendarId',  'ComponentType',    'Flags','DateStart',    'DateEnd',  'Summary',          'Location',         'Description',      'Status',   'Uid',     'Until','AllDay','CreatedTime', 'ModifiedTime', 'Tzid','TzOffset'],
                        ev_ta
                        )

            print "[Start ical iter]    [sql try disconnect]"
            s_con.close()
            done_ok = done_ok+"\n- ["+ical[0]+"] events:["+str(count_total)+"]    "+cal_name



        else:
            print "[Start ical iter]    [icar return '' error no string :/]"

        print "[Start ical iter]    [end]    ["+ical[0]+"]"


    if error == 0:
        Info( done_ok )
    print "[done oK] "+done_ok



class Start_dialog(hildon.Program):
    dialog = gtk.Dialog()
    selected_item = -1


    def ev_import(self, widget=None ):
        self.iter = -1
        self.dialog.destroy()
        Run_import()

    def ev_select_ok(self, widget, del_bt):
        global lista_of_icals
        if del_bt==1 and self.selected_item>-1:
            print 'edit'
            lista_of_icals[self.selected_item][0] = self.entry_addres.get_text()
            lista_of_icals[self.selected_item][1] = int(self.entry_offset.get_text())
        else:
            print 'add'
            lista_of_icals.append(
                                  [ self.entry_addres.get_text(),
                                   int(self.entry_offset.get_text()) ])
        conf_save()
        self.ev_select(None)

    def ev_select_del(self, widget):
        global lista_of_icals
        if self.selected_item>-1:
            tmp = []
            for i in range(0,len(lista_of_icals)):
                if self.selected_item<> i:
                    tmp.append(lista_of_icals[i])
            lista_of_icals = tmp
        conf_save()
        self.ev_select(None)

    def dialog_add(self, widget=None, del_bt=0, adres='', offset=0):
        self.iter = -1
        self.dialog.destroy()
        self.dialog = gtk.Dialog( 'pyWebCal :: select / config' )
        self.g = gtk.glade.XML("pywebcalai_gConfig.glade")
        self.hbox1 = self.g.get_widget("hbox1")

        self.bt_del = self.g.get_widget("button_del")


        self.entry_addres = self.g.get_widget("entry_adres")
        self.entry_addres.set_text(adres)


        self.entry_offset = self.g.get_widget("entry_offset")
        self.entry_offset.set_text(("%i"%offset))

        self.bt_del = self.g.get_widget("button_del")
        self.bt_del.connect("clicked", self.ev_select_del)

        self.bt_cancel = self.g.get_widget("button_cancel")
        self.bt_cancel.connect("clicked", self.ev_select)

        self.bt_ok = self.g.get_widget("button_ok")
        self.bt_ok.connect("clicked", self.ev_select_ok,del_bt)


        self.hbox1.reparent(self.dialog.vbox)
        self.dialog.show_all()


        if del_bt == 0:
            self.bt_del.hide()

        self.dialog.run()


    def selection_changed(self, selector, user_data):
        global lista_of_icals
        current_selection = selector.get_current_text()
        try:
            nr = 0
            for i in lista_of_icals:

                if i[0]==current_selection:
                    self.selected_item = nr
                    print "Current selection : ID %s" % (nr)
                    break
                nr = nr +1
        except:
            print "cos selector nie teges :/"


    def ev_bt_edit(self,widget):
        global lista_of_icals
        if self.selected_item > -1 :
            self.dialog_add(None, 1, lista_of_icals[self.selected_item][0], lista_of_icals[self.selected_item][1])

    def ev_select(self, widget=None):
        global lista_of_icals

        self.iter = -1
        self.dialog.destroy()
        self.dialog = gtk.Dialog( 'pyWebCal :: select / config' )
        self.g = gtk.glade.XML("pywebcalai_gSelect.glade")
        self.hbox1 = self.g.get_widget("hbox1")

        selected_item = -1
        self.vbox2 = self.g.get_widget("vbox2")
        pick = hildon.PickerButton(gtk.HILDON_SIZE_AUTO, hildon.BUTTON_ARRANGEMENT_VERTICAL)
        pick.set_title("select webcal:")
        selector = hildon.TouchSelectorEntry( text=True )
        selector.connect("changed", self.selection_changed)
        for i in lista_of_icals:
            selector.append_text( i[0] )
        pick.set_selector(selector)
        self.vbox2.add(pick)



        self.bt_add = self.g.get_widget("button_add")
        self.bt_add.connect("clicked", self.dialog_add)

        self.bt_edit = self.g.get_widget("button_edit")
        self.bt_edit.connect("clicked", self.ev_bt_edit)

        self.bt_cancel = self.g.get_widget("button_config")
        self.bt_cancel.connect("clicked", self.dialog_main)

        self.hbox1.reparent(self.dialog.vbox)
        self.dialog.show_all()
        self.dialog.run()


    def timeOut_for_no_action(self):
        print "iter %i" % self.iter
        if self.iter > 0:
            self.label_status.set_text( ("auto import in %i sec..." % self.iter) )
            self.iter = self.iter -1
            glib.timeout_add( 1000, self.timeOut_for_no_action )
        elif self.iter == 0:
            self.iter = -1
            self.ev_import()

    def dialog_main(self, widget=None):
        global lista_of_icals

        self.iter = 15
        self.dialog.destroy()
        self.dialog = gtk.Dialog( 'pyWebCal' )

        self.g = gtk.glade.XML("pywebcalai_g1.glade")
        self.hbox1 = self.g.get_widget("hbox1")
        self.image_logo = self.g.get_widget("image_logo")
        self.image_logo.set_from_file('ico_ical_64_64.png')

        self.label_status = self.g.get_widget("label_status")

        self.bt_config = self.g.get_widget("button_config")
        self.bt_config.connect("clicked", self.ev_select)

        self.bt_import = self.g.get_widget("button_import")
        self.bt_import.connect("clicked", self.ev_import)

        self.hbox1.reparent(self.dialog.vbox)
        self.dialog.show_all()

        if len( lista_of_icals )>0:
            self.timeOut_for_no_action()
        else:
            self.label_status.set_text("No webcal's set. Add some, click Preferences.")
            self.bt_import.hide()

        self.dialog.run()


    def __init__(self):
        self.program = hildon.Program.get_instance()
        self.dialog_main()



if __name__ == "__main__":
    conf_read()
    Start_dialog()
    print "si ja :)"

