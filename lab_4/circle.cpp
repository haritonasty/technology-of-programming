#include "circle.h"


Circle::Circle(QObject *parent) :
    QObject(parent)
{
    radius=0;
    setFlag(QGraphicsItem::ItemIsMovable, true);
       setFlag(QGraphicsItem::ItemIsSelectable, true);
       setFlag(QGraphicsItem::ItemIsFocusable,true);
}
void Circle::setAll(vector<int> curr)
{
    radius=curr.at(0);
}
QPainterPath Circle::shape() const
{   QPainterPath point;
    point.addEllipse(-radius/2,-radius/2,radius,radius);
     return point;
}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRect point(-radius/2,-radius/2,radius,radius);
    painter->setBrush(Qt::green);
    painter->setPen(pen);
    painter->drawEllipse(point);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF Circle::boundingRect() const
{
    return QRectF(-radius/2,-radius/2,radius,radius);
}
string Circle::type() {
    return "CIRCLE";
}
void Circle::print()
{
    cout<<"radius = "<<radius<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"angel = "<<angel<<endl;
}
vector<int> Circle::getAll() {
    vector<int> a;
    a.push_back(x);
    a.push_back(y);
    a.push_back(radius);
    a.push_back(angel);
    return a;
}
