#include "shape.h"


Shape::Shape() : x(0),y(0){} //фигура будет начинаться от (0,0)
Shape::Shape(float coorX, float coorY) : x(coorX),y(coorY){} //фигура будет начинаться от (X,Y)
void Shape::offsetTo(float coorX, float coorY) {
    x += coorX;
    y += coorY;
}
