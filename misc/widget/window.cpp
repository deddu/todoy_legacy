/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtDBus>
#include <QtDebug>
#include <QMaemo5InformationBox>
#include <QMaemo5ValueButton>
#include <QMaemo5KineticScroller>
#include <QMaemo5TimePickSelector>
//#include <QMaemo5DatePickSelector>
#include <QMaemo5EditBar>

#include <mce/mode-names.h>
#include <mce/dbus-names.h>

#include "window.h"

class RotatedLabel : public QWidget {
public:
    RotatedLabel(const QString &str, int rotation)
        : QWidget(), m_rotation(rotation), m_text(str)
    {
        QFontMetrics fm = fontMetrics();
        int w = fm.width(m_text);
        setMinimumSize(w + 8, w + 8);
    }

protected:
    void paintEvent(QPaintEvent *)
    {
        QPainter p(this);
        p.translate(rect().center());
        p.rotate(m_rotation);
        p.drawText(rect().translated(-rect().center()), Qt::AlignCenter, m_text);
    }

private:
    int m_rotation;
    QString m_text;
};

class ProgressBarAction : public QWidgetAction {
public:
    ProgressBarAction(QObject *parent)
        : QWidgetAction(parent)
    {
        setText(tr("Progress"));
    }

    QWidget * createWidget(QWidget *parent)
    {
        return new QProgressBar(parent);
    }
};

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
#ifdef QT_ARCH_ARM
    // we should really test for X11 server == Xephyr here,
    // since Xephyr forgets to rotate the mouse coordinates.
    setAttribute(Qt::WA_Maemo5ForcePortraitOrientation);
#endif

    setAttribute(Qt::WA_Maemo5StackedWindow);

    bool isPortrait = (qApp->desktop()->screenGeometry().width() < qApp->desktop()->screenGeometry().height());

    m_fullscreen = new QAction(QIcon::fromTheme("general_fullsize"), QString(), this);
    m_fullscreen->setCheckable(true);
    QActionGroup *orientation = new QActionGroup(this);
    orientation->setExclusive(true);
    m_portrait = new QAction(QIcon::fromTheme("general_portrait", QIcon(QLatin1String(":/images/portrait"))), QString(), orientation);
    m_portrait->setCheckable(true);
    m_portrait->setChecked(isPortrait);
    m_landscape = new QAction(QIcon::fromTheme("general_landscape", QIcon(QLatin1String(":/images/landscape"))), QString(), orientation);
    m_landscape->setCheckable(true);
    m_landscape->setChecked(!isPortrait);

    connect(m_fullscreen, SIGNAL(toggled(bool)), this, SLOT(toggleFullScreen(bool)));
    connect(m_landscape, SIGNAL(toggled(bool)), this, SLOT(toggleLandscape(bool)));

    // add some radio/exclusive actions (which will be converted to filter actions in the application menu)
    // The Maemo 5 UI specification limits this to up to four actions in up to one group
    QActionGroup *filterGroup = new QActionGroup(this);
    filterGroup->setExclusive(true);
    m_enable_children = new QAction(tr("Enabled"), filterGroup);
    m_enable_children->setCheckable(true);
    m_enable_children->setChecked(true);
    m_disable_children = new QAction(tr("Disabled"), filterGroup);
    m_disable_children->setCheckable(true);
    QAction *whatever = new QAction(tr("Whatever"), filterGroup);
    whatever->setCheckable(true);

    connect(m_enable_children, SIGNAL(toggled(bool)), this, SLOT(enableChildren(bool)));

    menuBar()->addActions(filterGroup->actions());
}

Window::~Window()
{
}

void Window::toggleLandscape(bool b)
{
    setAttribute(Qt::WA_Maemo5ForcePortraitOrientation, !b);
    setAttribute(Qt::WA_Maemo5ForceLandscapeOrientation, b);

    if (b != m_landscape->isChecked()) {
        m_landscape->setChecked(b);
        m_portrait->setChecked(!b);
    }
    relayout();
}

void Window::enableChildren(bool b)
{
    foreach (QWidget *w, findChildren<QWidget *>()) {
        if (!qobject_cast<QMenuBar *>(w))
            w->setEnabled(b);
    }
}

void Window::toggleFullScreen(bool b)
{
    setWindowState(b ? windowState() | Qt::WindowFullScreen
                     : windowState() & ~Qt::WindowFullScreen);
}

void Window::showEvent(QShowEvent *se)
{
    QDBusConnection::systemBus().call(QDBusMessage::createMethodCall(MCE_SERVICE, MCE_REQUEST_PATH,
                                                                     MCE_REQUEST_IF, MCE_ACCELEROMETER_ENABLE_REQ));
    QDBusConnection::systemBus().connect("", MCE_SIGNAL_PATH, MCE_SIGNAL_IF,
                                         MCE_DEVICE_ORIENTATION_SIG, this, SLOT(orientationChanged(QString, QString, QString, int, int, int)));
    QMainWindow::showEvent(se);
}

void Window::hideEvent(QHideEvent *he)
{
    QDBusConnection::systemBus().disconnect("", MCE_SIGNAL_PATH, MCE_SIGNAL_IF,
                                            MCE_DEVICE_ORIENTATION_SIG, this, SLOT(orientationChanged(QString, QString, QString, int, int, int)));
    QDBusConnection::systemBus().call(QDBusMessage::createMethodCall(MCE_SERVICE, MCE_REQUEST_PATH,
                                                                     MCE_REQUEST_IF, MCE_ACCELEROMETER_DISABLE_REQ));
    QMainWindow::hideEvent(he);
}

void Window::orientationChanged(QString landscape, QString /*stand*/, QString /*facing*/, int /*x_mG*/, int /*y_mG*/, int /*z_mG*/)
{
    if (landscape == QLatin1String(MCE_ORIENTATION_LANDSCAPE))
        toggleLandscape(true);
    else if (landscape == QLatin1String(MCE_ORIENTATION_PORTRAIT))
        toggleLandscape(false);
}

void Window::relayout()
{
}

MainWindow::MainWindow()
    : Window(0)
{
    menuBar()->addAction(tr("Show a MessageBox"), this, SLOT(showMessageBox()));
    menuBar()->addAction(tr("Show a Banner"), this, SLOT(showBanner()));
    menuBar()->addAction(tr("Show a Note"), this, SLOT(showNote()));
    menuBar()->addAction(tr("Show a Expose"), this, SLOT(showExpose()));
    menuBar()->addAction(tr("Show a Complex Note"), this, SLOT(showComplexNote()));

    // add a checkbox action
    QAction *checkAction = new QAction(tr("Busy"), this);
    connect(checkAction, SIGNAL(triggered(bool)), this, SLOT(beBusy(bool)));
    checkAction->setCheckable(true);
    menuBar()->addAction(checkAction);

    // add a widget action
    menuBar()->addAction(new ProgressBarAction(this));

    QToolBar *tb = new QToolBar(this);
    tb->addAction(m_fullscreen);
    tb->addAction(m_portrait);
    tb->addAction(m_landscape);
    addToolBar(tb);

    QWidget *central = new QWidget(this);
    QGridLayout *lay = new QGridLayout(central);

    QPushButton *pb;
    pb = new QPushButton(tr("Show Widgets"));
    lay->addWidget(pb, 0, 0);
    connect(pb, SIGNAL(clicked()), this, SLOT(showWidgets1()));
    pb = new QPushButton(tr("Show more Widgets"));
    lay->addWidget(pb, 0, 1);
    connect(pb, SIGNAL(clicked()), this, SLOT(showWidgets2()));
    pb = new QPushButton(tr("Show even more Widgets"));
    lay->addWidget(pb, 1, 0);
    connect(pb, SIGNAL(clicked()), this, SLOT(showWidgets3()));
    pb = new QPushButton(tr("Show a List"));
    lay->addWidget(pb, 1, 1);
    connect(pb, SIGNAL(clicked()), this, SLOT(showWidgets4()));

    setCentralWidget(central);
    relayout();

    // The Maemo5 window manager mis-calculates the length of the window title
    // and won't show the 'v' indicator in Portrait mode if the title is "Stacked"
    setWindowTitle(tr("Maemo"));
}

void MainWindow::relayout()
{
    QGridLayout *grid = static_cast<QGridLayout *>(centralWidget()->layout());
    bool isPortrait = m_portrait->isChecked();
    bool wasPortrait = (grid->columnCount() == 1);

    if (isPortrait != wasPortrait) {
        QList<QLayoutItem *> list;
        while (grid->count())
            list << grid->takeAt(0);
        int c = 0, r = 0;
        foreach (QLayoutItem *li, list) {
            grid->addItem(li, r, c);
            c++;
            if (c == (isPortrait ? 1 : 2)) {
                c = 0;
                r++;
            }
        }
    }
}


WidgetWindow::WidgetWindow(int page, MainWindow *parent)
    : Window(parent)
{
    QWidget *central = new QWidget();

    page = qBound(0, page, 2);
    QStringList onetwothree;
    onetwothree << tr("One") << tr("Two") << tr("Three");

    if (page == 0) {
        setWindowTitle(tr("Widgets"));

        QVBoxLayout *lay = new QVBoxLayout(central);
        lay->addWidget(new QLabel(tr("<qt>This is a Maemo5 Stacked Dialog.")));
        lay->addWidget(new QLineEdit(tr("LineEdit")));
        lay->addWidget(new QSlider(Qt::Horizontal));
        QProgressBar *prb = new QProgressBar();
        prb->setValue(50);
        lay->addWidget(prb);
        lay->addWidget(new QCheckBox(tr("CheckBox")));
//        QComboBox *com = new QComboBox();
//        com->setEditable(false);
//        com->addItems(onethwothree);
//        lay->addWidget(com);
        QButtonGroup *radios = new QButtonGroup(central);
        QHBoxLayout *radiolay = new QHBoxLayout();
        radiolay->setSpacing(0);
        foreach(const QString &str, onetwothree) {
            QRadioButton *radio = new QRadioButton(str);
            radiolay->addWidget(radio);
            if (radios->buttons().isEmpty())
                radio->setChecked(true);
            radios->addButton(radio);
        }
        lay->addLayout(radiolay);
    } else if (page == 1) {
        setWindowTitle(tr("More Widgets"));

        QVBoxLayout *lay = new QVBoxLayout(central);
        QButtonGroup *buttons = new QButtonGroup(central);
        QMaemo5ValueButton *v1 = new QMaemo5ValueButton(tr("Text"));
        v1->setIcon(QIcon::fromTheme("chat_smiley_happy"));
        v1->setValueLayout(QMaemo5ValueButton::ValueBesideText);
        v1->setValueText(tr("ValueBesideText"));
        buttons->addButton(v1);
        lay->addWidget(v1);
        QMaemo5ValueButton *v2 = new QMaemo5ValueButton(tr("Text"));
        v2->setIcon(QIcon::fromTheme("chat_smiley_nerd"));
        v2->setValueLayout(QMaemo5ValueButton::ValueUnderText);
        v2->setValueText(tr("ValueUnderText"));
        buttons->addButton(v2);
        lay->addWidget(v2);
        QMaemo5ValueButton *v3 = new QMaemo5ValueButton(tr("Picker"));
        v3->setIcon(QIcon::fromTheme("chat_smiley_tongue"));
        v3->setValueLayout(QMaemo5ValueButton::ValueUnderText);
        v3->setPickSelector(new QMaemo5TimePickSelector());
        buttons->addButton(v3);
        lay->addWidget(v3);
        QMaemo5ValueButton *v4 = new QMaemo5ValueButton(tr("Centered"));
        v4->setIcon(QIcon::fromTheme("chat_smiley_surprised"));
        v4->setValueLayout(QMaemo5ValueButton::ValueUnderTextCentered);
//        v4->setPickSelector(new QMaemo5DatePickSelector());
        buttons->addButton(v4);
        lay->addWidget(v4);
    } else if (page == 2) {
        setWindowTitle(tr("Even More Widgets"));

        QVBoxLayout *lay = new QVBoxLayout(central);
        QComboBox *com = new QComboBox();
        com->setEditable(false);
        com->addItems(onetwothree);
        lay->addWidget(com);
        com = new QComboBox();
        com->setEditable(true);
        com->addItems(onetwothree);
        lay->addWidget(com);
    }
    setCentralWidget(central);
}

ListWindow::ListWindow(MainWindow *parent)
    : Window(parent)
{
    QWidget *central = new QWidget();

    setWindowTitle(tr("List"));

    QVBoxLayout *lay = new QVBoxLayout(central);
    lay->setSpacing(8);
    lay->setContentsMargins(0, 0, 0, 0);

    QMaemo5EditBar *eb = new QMaemo5EditBar(tr("Edit this list..."));
    lay->addWidget(eb);
    QPushButton *pb = new QPushButton(tr("Action"));
    eb->addButton(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(actionClicked()));

    QListWidget *list = new QListWidget();
    new QMaemo5KineticScroller(list);
    for (int i = 0; i < 100; ++i)
        list->addItem(tr("Item #%1").arg(i));
    lay->addWidget(list);

    setCentralWidget(central);
    toggleFullScreen(true);
}

void ListWindow::actionClicked()
{
    QMaemo5InformationBox::information(this, tr("Action was clicked"), QMaemo5InformationBox::DefaultTimeout);
}

void MainWindow::showWidgets1()
{
    WidgetWindow *w = new WidgetWindow(0, this);
    w->show();
}

void MainWindow::showWidgets2()
{
    WidgetWindow *w = new WidgetWindow(1, this);
    w->show();
}

void MainWindow::showWidgets3()
{
    WidgetWindow *w = new WidgetWindow(2, this);
    w->show();
}

void MainWindow::showWidgets4()
{
    ListWindow *w = new ListWindow(this);
    w->show();
}

void MainWindow::showMessageBox()
{
    QMessageBox::information(this, tr("A MessageBox"), tr("This is a Maemo5 Message Box."), QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::Apply);
}

void MainWindow::showBanner()
{
    QMaemo5InformationBox::information(this, tr("This is a <b>Maemo5</b> <i>banner</i>"), QMaemo5InformationBox::DefaultTimeout);
}

void MainWindow::showNote()
{
    QMaemo5InformationBox::information(this, tr("This<br>is<br>a<br><b>Maemo5</b><br><i>note</i>"), QMaemo5InformationBox::NoTimeout);
}

void MainWindow::showComplexNote()
{
    QMaemo5InformationBox *box = new QMaemo5InformationBox(this);
    box->setWidget(new RotatedLabel(tr("Qt for Maemo5"), 45));
    box->setTimeout(QMaemo5InformationBox::NoTimeout);
    box->exec();
}

void MainWindow::showExpose()
{
    QDBusConnection c = QDBusConnection::sessionBus();
    QDBusMessage m = QDBusMessage::createSignal("/","com.nokia.hildon_desktop","exit_app_view");
    c.send(m);
}

void MainWindow::beBusy(bool on)
{
    setAttribute(Qt::WA_Maemo5ShowProgressIndicator, on);
}

