#include "square.h"

Square::Square(QObject *parent){
    side = 0;
    angel = 0;
    x = 0;
    y = 0;
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsFocusable,true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

void Square::setAll(vector<int> curr){
    side = curr.at(0);
}

QPainterPath Square::shape() const{
    QPainterPath point;
    point.addRect(-side/2, -side/2, side, side);
    return point;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRect point(-side/2, -side/2, side, side);
    painter->setBrush(Qt::blue);
    painter->setPen(pen);
    painter->drawRect(point);
    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform, true);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Square::boundingRect() const{
    return QRectF(-side/2, -side/2, side, side);
}

string Square::type() {
    return "SQUARE";
}

void Square::print(){
    cout << "side = " << side << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "angel = " << angel << endl;
}
vector<int> Square::getAll() {
    vector<int> curr;
    curr.push_back(x);
    curr.push_back(y);
    curr.push_back(side);
    curr.push_back(angel);
    return curr;
}

Square::~Square(){
    qDebug() << "*Square::dtor()" <<endl;
}

