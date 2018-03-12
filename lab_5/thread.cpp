#include "thread.h"

Thread :: Thread(int new_bright){
    bright = new_bright;
}

void Thread :: changeBright(int new_bright){
    bright = new_bright;
}

void Thread :: run(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int width = qrand() % 30 + 30;
    int height = qrand() % 30 + 30;
    int x = qrand() % 500+15;
    int y = qrand() % 500+15;
    QGraphicsEllipseItem * figure = new QGraphicsEllipseItem(x, y, width, height);
    figure->setBrush(QBrush(QColor(qrand()%250+1, qrand()%250+1, qrand()%250+1, bright)));
    emit getItem((QGraphicsItem*) figure);
}




