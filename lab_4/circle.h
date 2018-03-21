#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


class FIGURESHARED_EXPORT Circle : public Shape, public QObject{
    float radius;
public:
    Circle(QObject *parent = 0);
    ~Circle();
    string type();
    void print();
    vector<int> getAll();
    void setAll(vector<int> curr);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CIRCLE_H
