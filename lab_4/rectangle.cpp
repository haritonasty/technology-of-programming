#include "rectangle.h"


Rectangle::Rectangle(QObject *parent) :
    QObject(parent) {
    height=0;
    width=0;
    setFlag(QGraphicsItem::ItemIsMovable, true);
       setFlag(QGraphicsItem::ItemIsSelectable, true);
       setFlag(QGraphicsItem::ItemIsFocusable,true);
}
void Rectangle::setAll(vector<int> curr)
{
    height=curr.at(0);
    width=curr.at(1);
}
string Rectangle::type() {
    return "RECTANGLE";
}
QPainterPath Rectangle::shape() const
{   QPainterPath point;
    point.addRect(-width/2,-height/2,width,height);
     return point;
}
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRect point(-width/2,-height/2,width,height);
    painter->setBrush(Qt::red);
    painter->setPen(pen);
    painter->drawRect(point);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF Rectangle::boundingRect() const
{
    return QRectF(-width/2,-height/2,width,height);
}
void Rectangle::print()
{
    cout<<"height = "<<height<<endl;
    cout<<"width = "<<width<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
    cout<<"angel = "<<angel<<endl;
}

vector<int> Rectangle::getAll() {
    vector<int> a;
    a.push_back(x);
    a.push_back(y);
    a.push_back(width);
    a.push_back(height);
    a.push_back(angel);
    return a;
}
