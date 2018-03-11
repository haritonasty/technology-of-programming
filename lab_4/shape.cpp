#include "shape.h"



void Shape::offsetTo(float coorX, float coorY) {
    x = coorX;
    y = coorY;
}
void Shape::changeAngel()
{
    angel=rotation();
}
void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
     this->setPos(mapToScene(event->pos()));
     QPointF point = this->pos();
     this->x= point.x();
     this->x = point.y();
}

void Shape::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(event->button() == Qt::RightButton)
    {
        if(isSelected())
        {
            pen.setColor(Qt::black);
            pen.setWidth(1);
            this->setSelected(false);
        }
        else
        {
            pen.setColor(Qt::red);
            pen.setWidth(1);
            this->setFlag(ItemIsSelectable, true);
            this->setSelected(true);
        }
    }
}
