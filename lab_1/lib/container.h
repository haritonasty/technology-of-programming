#ifndef CONTAINER_H
#define CONTAINER_H
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"


class FIGURESHARED_EXPORT Container {
    vector<Shape* > list;
public:
    Container();
    string T;
    void addFigure(Shape * a);
    void deleteFigure(int a);
    void moveTo(int X, int Y, int a);
    void save();
    void load();
    void print();
};
#endif // CONTAINER_H
