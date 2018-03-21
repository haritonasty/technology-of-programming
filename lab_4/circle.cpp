#include "circle.h"

Circle::Circle(QObject *parent){
   radius = 0;
   x = 0;
   y = 0;
   angel = 0;
   setFlag(QGraphicsItem::ItemIsMovable, true);
   setFlag(QGraphicsItem::ItemIsFocusable,true);
   setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Circle::setAll(vector<int> curr){
    radius = curr.at(0);
}

QPainterPath Circle::shape() const{
    QPainterPath point;
    point.addEllipse(-radius/2, -radius/2, radius, radius);
    return point;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect point(-radius/2, -radius/2, radius, radius);
    painter->setBrush(Qt::green);
    painter->setPen(pen);
    painter->drawEllipse(point);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Circle::boundingRect() const{
    return QRectF(-radius/2, -radius/2, radius, radius);
}

string Circle::type() {
    return "CIRCLE";
}

void Circle::print(){
    cout << "radius = " << radius << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "angel = " << angel << endl;
}
vector<int> Circle::getAll() {
    vector<int> curr;
    curr.push_back(x);
    curr.push_back(y);
    curr.push_back(radius);
    curr.push_back(angel);
    return curr;
}


Circle::~Circle(){
    qDebug() << "*Circle::dtor()" <<endl;
}

