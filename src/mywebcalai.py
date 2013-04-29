#! /usr/bin/env python

ver = "0.10.25.10.35"
"""
autor Bartlomiej Ceglik
e-mail yoyoek[no spam]wp.pl
"""

def conf_read():
    try:
        f = open('mywebcalai.config','r')
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
    f = open('mywebcalai.config','w',0)
    for i in lista_of_icals:
        f.writelines( ("%i %s\n"%( i[1], i[0] )) )

    f.close()



#import gtk
#import gobject
#import pygtk
#import gtk.glade
#import glib
#import hildon
import os
import httplib
import getopt
import sys

try:
    from icalendar import Calendar, Event
except:
    Info_no_icalendar_found()

import sqlite3
import time

lista_of_icals = ['todoy.ics', 2]
sql_file = 'calendardb'
sql_debug = 0
error = 0
done_ok = ''


def Read_ical_from_file ( fp ):
    tr = ''
    print "read file %s" % fp
    try:
        f = open(fp,'r')
        while f:
            line = f.readline()
            if line:
                tr+= line
            else:
                break
        print "read file %s DONE" % fp
        return tr
    except:
        print "read file %s ERROR " % fp
        return ''


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
        print "[q] [%s]\n[q][ insert values ]  [%s]" %(q, vars_tmp)

    try:
        count = s_vars[0][0]
        #print "\n-------------\n"+str(s_vars)+"\n-list------------"
        for s in s_vars:
            c.execute(q,s)
    except:
        if len( s_vars ) == len( s_values ):
            print "[q] insert get s_var as singiel record"
            #print "\n-------------\n"+str(s_vars)+"\n-singiel------------"
            c.execute(q,s_vars)
        else:
            print "[q] insert get singiel record - error "

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
            tr = time.mktime(time.strptime(str(str_time),'%Y%m%dT%H%M%S' ))
        except:
            try:
                tr = time.mktime(time.strptime(str(str_time),'%Y%m%d' ))
            except:
                print "[Error]\tParseStrTime_to_unix error [%s]" % str_time
                return 1
    return tr


def Call_featch_val( item, val_name ):
    try:
        return item[val_name]
    except:
        return ''





def Run_import():
    
    #os.system("dbus-send --type=method_call --dest=org.freedesktop.Notifications /org/freedesktop/Notifications org.freedesktop.Notifications.SystemNoteInfoprint string:\"py web call auto import start it's work...\"")
    #global done_ok

    cal_nr = 0;
    for ical in lista_of_icals:
        cal_nr = cal_nr+1
	work_type = 'internet'
        print "--------------- DETECT WORK TYPE ------------------------"
        work_path = ical[0]
        if work_path[:1] == '/':
            print 'local work [%s]' % work_path
            work_type = 'local'
            ical[0] = work_path
        elif work_path[:7] == 'http://':
            ical[0] = work_path[7:]
            print '1 internet work [%s] => [%s]' % (work_path, ical[0] )
        elif work_path[:4] == 'www.':
            ical[0] = work_path[4:]
            print '2 internet work [%s] => [%s]' % (work_path, ical[0] )
        else:
            print '3 internet work [%s] ' % (ical[0] )
        print "--------------- DETECT WORK TYPE ------------------------"


        if work_type == 'internet':
            
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
    
            s = "[%i/%i]working on %s"% (cal_nr, len(lista_of_icals),ical[0])
            os.system("dbus-send --type=method_call --dest=org.freedesktop.Notifications "+
                      "/org/freedesktop/Notifications org.freedesktop.Notifications.SystemNoteInfoprint "+
                      "string:\"%s\""% s)
            
            ical_str = Read_ical_from_web( ical[0], ical[1]  )
        else:
            host = ical[1]
            offset = ical[0]
            ical_str = Read_ical_from_file( ical[0] )
            ical.append(ical[1]) 
            print "local file len [%i]" % len( ical_str )
            
            

        host = ical[1]
        offset = ical[0]
        ical_str = Read_ical_from_file( ical[0] )
        ical.append(ical[1]) 
        print "local file len [%i]" % len( ical_str )
            
            
            
        #ical_str = open('todoy.ics','rb').read()
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
            try:
                cal_name = cal_name_item[0]['X-WR-CALNAME']+" (webcal)"
            except:
                print "[Cal name not deff :/ set from X-WR-CALDESC]"
                cal_name = cal_name_item[0]['X-WR-CALDESC']+" (webcal)"

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
                                            [str(cal_name), colour,  '1',         '1',           '0',            '',             '1.0',                '0']
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
                entryDate = Call_featch_val(e, 'created')
                if entryDate:
                    entryDate = ParseStrTime_to_unix(entryDate)
                    if entryDate < 0:
                        entryDate = 0
                modDate = Call_featch_val(e, 'last-modified')
                if modDate:
                    modDate = ParseStrTime_to_unix(modDate)
                    if modDate < 0:
                        modeDate = 0

                #print "entry(%s) mod(%s)" % ( entryDate, modDate )

                ev_ta.append(
                             [cal_id,        '1',                '-1',   tStart,         tEnd,        e['summary'],      location,           desc,               '-1',       '0',        '-1',   '0',    str(entryDate),     str(modDate),        ':UTC', '0']
                             )

            print "[Start ical iter]    [db insert %i/%i] [%s]" % (len(ev_ta),count_total, cal_name)
            Sql_insert_correct(s_con,
                        '',
                        'Components',
                        ['CalendarId',      'ComponentType',    'Flags','DateStart',    'DateEnd',  'Summary',          'Location',         'Description',      'Status',   'Uid',     'Until', 'AllDay','CreatedTime', 'ModifiedTime', 'Tzid','TzOffset'],
                        ev_ta
                        )

            print "[Start ical iter]    [sql try disconnect]"
            s_con.close()
            done_ok = done_ok+"\n- ["+ical[0]+"] "+cal_name+"\n\tevents:["+str(count_total)+"]"



        else:
            print "[Start ical iter]    [icar return '' error no string :/]"

        print "[Start ical iter]    [end]    ["+ical[0]+"]"


    if error == 0:
        
       print "[done oK] "#+done_ok


    #os.system("dbus-send --type=method_call --dest=org.freedesktop.Notifications "+
                      #"/org/freedesktop/Notifications org.freedesktop.Notifications.SystemNoteInfoprint "+
                      #"string:\"%s\""% done_ok)
    sys.exit(2)




if __name__ == "__main__":
    msg = """ pywebcalai """+ver+"""
    [no args]  you can star in with no args for gui mode
    [cmd]      run in back ground no gui, run, do import and close
""" 
    conf_read()
    Read_ical_from_file("todoy.ics")
    Run_import()
    print "si ja :)"

