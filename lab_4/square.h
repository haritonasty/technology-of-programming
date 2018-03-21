#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class FIGURESHARED_EXPORT Square : public Shape,public QObject {
    float side;
public:
    explicit Square(QObject *parent = 0 );
    ~Square();
    string type();
    void print();
    vector<int> getAll();
    void setAll(vector<int> curr);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // SQUARE_H
