#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

#include <QDebug>

class FIGURESHARED_EXPORT Rectangle : public Shape, public QObject {
    double height, width;
public:
    Rectangle(QObject *parent = 0) ;
    ~Rectangle();
    string type();
    void print();
    vector<int> getAll();
    void setAll(vector<int> curr);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
