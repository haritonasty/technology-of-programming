#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <QGraphicsPathItem>
#include <QObject>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "figure_global.h"


using namespace std;

class FIGURESHARED_EXPORT Shape:public QGraphicsItem {
protected:
    QPen pen;
    float x, y, angel; //положение в пространстве
public:
    virtual ~Shape();
    virtual string type() = 0;
    virtual void print() = 0;
    void offsetTo(float X, float Y);
    void changeAngel();
    virtual vector<int> getAll() = 0;
    virtual void setAll(vector<int>) = 0;
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};


#endif // FIGURE_H
