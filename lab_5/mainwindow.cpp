#include "mainwindow.h"

MainWindow :: MainWindow(QWidget *parent) : QWidget(parent){

    setFixedSize(600,600);

    graphicsView = new QGraphicsView();
    graphicsView->resize(600, 600);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,600,600);
    graphicsView->setScene(scene);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(graphicsView);
    setLayout(layout);


    timer=new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::threadUpdate);
    bright = 250;
    threadWorkNow = false;
    thread = new Thread(bright);
    connect(thread, &Thread::getItem, this, &MainWindow::setItem);
    connect(thread, &Thread::finished, this, &MainWindow::threadFinish);
    connect(this, &MainWindow::changeBright, thread, &Thread::changeBright);
    timer->start(1200);
}

void MainWindow :: setItem(QGraphicsItem *item){
    scene->addItem(item);
}

void MainWindow :: threadUpdate(){
    if(!threadWorkNow){
      threadWorkNow = true;
      thread->start();
    }
}

void MainWindow :: threadFinish(){
    threadWorkNow = false;
}

void MainWindow :: mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::RightButton){ //more
        if (bright < 250){
            bright += 10;
            QList <QGraphicsItem*> figures = scene->items();
            for(int i=0; i<figures.size(); i++){
               QGraphicsRectItem *curr = (QGraphicsRectItem*)(figures[i]);
               int red = curr->brush().color().red();
               int green = curr->brush().color().green();
               int blue = curr->brush().color().blue();
               curr->setBrush(QBrush(QColor(red, green, blue, bright)));
            }
            emit changeBright(bright);
        }
    }
    if(event->button() == Qt::LeftButton){ //lower
        if (bright > 50){
            bright -= 10;
            QList <QGraphicsItem*> figures = scene->items();
            for(int i=0; i<figures.size(); i++){
               QGraphicsRectItem *curr = (QGraphicsRectItem*)(figures[i]);
               int red = curr->brush().color().red();
               int green = curr->brush().color().green();
               int blue = curr->brush().color().blue();
               curr->setBrush(QBrush(QColor(red, green, blue, bright)));
            }
            emit changeBright(bright);
        }
    }
}

MainWindow :: ~MainWindow(){
    delete thread;
    timer->stop();
    delete timer;
    delete scene;
}
