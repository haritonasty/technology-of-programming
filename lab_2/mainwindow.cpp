#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent){

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

    }

void MainWindow::mousePressEvent(QMouseEvent *event){

   int x = event->pos().x();
   int y = event->pos().y();

   if(x <= 586 && x >= 13 && y <= 535 && y >= 13)
      {
          if(event->button() == Qt::LeftButton){
              scene->addEllipse(x-10, y-10, 20, 20, QPen(QColor(0,0,255,255)), QBrush(QColor(0,0,255,255)));
          }
          if(event->button() == Qt::RightButton){
              scene->addRect(x-15, y-15, 30, 30, QPen(QColor(255,0,0,255)), QBrush(QColor(255,0,0,255)));
          }
      }

}
MainWindow::~MainWindow(){
    delete scene;
    delete graphicsView;
}
