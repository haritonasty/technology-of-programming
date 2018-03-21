#include "rectangle.h"

Rectangle::Rectangle(QObject *parent){
    height = 0;
    width = 0;
    x = 0;
    y = 0;
    angel = 0;
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Rectangle::setAll(vector<int> curr){
    width = curr.at(0);
    height = curr.at(1);
}

string Rectangle::type() {
    return "RECTANGLE";
}
QPainterPath Rectangle::shape() const{
    QPainterPath point;
    point.addRect(-width/2, -height/2, width, height);
    return point;
}
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect point(-width/2, -height/2, width, height);
    painter->setBrush(Qt::red);
    painter->setPen(pen);
    painter->drawRect(point);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Rectangle::boundingRect() const{
    return QRectF(-width/2, -height/2, width, height);
}

void Rectangle::print(){
    cout << "height = " << height << endl;
    cout << "width = " << width << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "angel = " << angel << endl;
}

vector<int> Rectangle::getAll() {
    vector<int> curr;
    curr.push_back(x);
    curr.push_back(y);
    curr.push_back(width);
    curr.push_back(height);
    curr.push_back(angel);
    return curr;
}

Rectangle::~Rectangle(){
    qDebug() << "*Rectangle::dtor()" <<endl;
}
