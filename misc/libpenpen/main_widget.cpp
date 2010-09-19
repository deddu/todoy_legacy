#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QAction>
#include <QToolBar>
#include <QtCore>
#include <QColorDialog>
#include "pppaperwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    PPPaperWidget *paperWidget;

    MainWindow() : QMainWindow() {
        /// Create UI elements
        QWidget *frame = new QWidget(this);
        setCentralWidget(frame);

        QVBoxLayout *layout = new QVBoxLayout(frame);

        paperWidget = new PPPaperWidget(frame);
        layout->addWidget(paperWidget);

        QToolBar *toolBar = new QToolBar(frame);
        layout->addWidget(toolBar);

        QAction *penAction = new QAction("Pen",toolBar);
        penAction->setCheckable(true);

        QAction *eraserAction = new QAction("Eraser",toolBar);
        eraserAction->setCheckable(true);

        QAction *clearAction = new QAction("Clear",toolBar);
        QAction *colorAction = new QAction("Color",toolBar);

        QActionGroup *group = new QActionGroup(toolBar);
        group->addAction(penAction);
        group->addAction(eraserAction);

        toolBar->addAction(penAction);
        toolBar->addAction(eraserAction);
        toolBar->addAction(clearAction);
        toolBar->addAction(colorAction);

        QObject::connect(clearAction,SIGNAL(triggered()),
                paperWidget->paper(),SLOT(clear()));

        QObject::connect(penAction,SIGNAL(triggered()),
                         this,SLOT(onPenAction()));

        QObject::connect(eraserAction,SIGNAL(triggered()),
                         this,SLOT(onEraserAction()));

        QObject::connect(colorAction,SIGNAL(triggered()),
                         this,SLOT(onColorAction()));

        penAction->trigger();
    }

    void setBackground() { // Create a pixmap and set its as background
        QPixmap pixmap(800,50);
        pixmap.fill(Qt::white);

        QPainter painter(&pixmap);
        QPen pen(Qt::red);
        painter.setPen(pen);
        painter.drawLine(30,0,30,49);

        pen.setColor(Qt::blue);
        painter.setPen(pen);
        painter.drawLine(0,49,800,49);

        painter.end();

        PPBackground bg;
        bg.setPixmap(pixmap);
        bg.setRepeatY(true);

        paperWidget->paper()->setBackground(bg);

    }

public slots:
    void onPenAction() { // Select pen
        paperWidget->pencilBox()->setTool(PPPencilBox::Pen);
    }

    void onEraserAction() { // Select eraser
        paperWidget->pencilBox()->setTool(PPPencilBox::Eraser);
    }

    void onColorAction() { // Change color
        QColorDialog dialog(this);
        QColor color = paperWidget->pencilBox()->pen()->color();
        dialog.setCurrentColor(color);
        if (dialog.exec() == QDialog::Accepted){
            color = dialog.selectedColor();
            paperWidget->pencilBox()->pen()->setColor(color);
        }
    }

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    window.resize(640,480);
    window.show();

    QFile file("paper.xml");
    QByteArray data;
    if (file.open(QIODevice::ReadOnly)) { // Try to load from previous saved drawing
         data = file.readAll();
         window.paperWidget->setContent(data);
         file.close();
    }

    // Set a pixmap background. As PPXmlPaper do not handle background save & load.
    window.setBackground();

    int res = a.exec();

    // Save the drawing
    data = window.paperWidget->toByteArray();

    file.open(QIODevice::WriteOnly);
    file.write(data);
    file.close();

    return res;
}

#include "main.moc"
