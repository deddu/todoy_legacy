#!/usr/bin/python2.5
# -*- coding: utf-8 -*-
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published
## by the Free Software Foundation; version 2 only.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
import py2deb
import os
if __name__ == "__main__":
    try:
        os.chdir(os.path.dirname(sys.argv[0]))
    except:
        pass
    print
    p=py2deb.Py2deb("todoy")   #This is the package name and MUST be in lowercase! (using  "mClock" fails miserably, for example)
    p.description="A fast revolutionary way to handle your duty and your appointments. With desktop widget and calendar export"
    p.author="Andrea Cadeddu"
    p.mail="mrernia@gmail.com"
    p.depends = "python2.5, python-osso, python2.5-pyqt4-core, python2.5-pyqt4-gui"
    # Edit this based on your import statements (for example, you probably will not need pygame)
    p.section="user/office"
    # When editing the .section, make sure to use [[Packaging#Sections|an allowed section]] - otherwise the autobuilder will give a warning.
    p.icon = "/home/user/MyDocs/todoy/src/todoy_ico_48.png"
    p.arch="all"                #should be all for python, any for all arch
    p.urgency="low"             #not used in maemo onl for deb os
    p.distribution="fremantle"
    p.repository="extras-devel"
    p.xsbc_bugtracker="http://bugs.maemo.org"
    p.postinstall="""#!/bin/sh
    chmod +x /opt/todoy/todoy.py""" #Set here your post install script
    #  p.postremove="""#!/bin/sh
    #  chmod +x /usr/bin/mclock.py""" #Set here your post remove script
    #  p.preinstall="""#!/bin/sh
    #  chmod +x /usr/bin/mclock.py""" #Set here your pre install script
    #  p.preremove="""#!/bin/sh
    #  chmod +x /usr/bin/mclock.py""" #Set here your pre remove script
    version = "0.0.2"           #Version of your software, for example "1.2.0" or "0.8.2"
    build = "1"                 #Build number, for example "1" for the first build of this version of your software. Increment for later re-builds of the same version of your software.
                                #Text with changelog information to be displayed in the package "Details" tab of the Maemo Application Manager
    changeloginformation = "First Edition." 
    dir_name = "src"            #Name of the subfolder containing your package source files (for example, usr\share\icons\hicolor\scalable\myappicon.svg, usr\lib\myapp\somelib.py). We suggest to leave it named src in all projects and will refer to that in the wiki article on maemo.org
    #Thanks to DareTheHair from talk.maemo.org for this snippet that recursively builds the file list 
    for root, dirs, files in os.walk(dir_name):
        real_dir = "//" + root#[:len(dir_name)]
        print root, real_dir
        fake_file = []
        for f in files:
            fake_file.append(root + os.sep + f + "|" + f)
        if len(fake_file) > 0:
            p[real_dir] = fake_file
    print p
    r = p.generate(version,build,changelog=changeloginformation,tar=True,dsc=True,changes=True,build=False,src=True)
