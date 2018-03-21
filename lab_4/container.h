#ifndef CONTAINER_H
#define CONTAINER_H
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include <QDebug>

class FIGURESHARED_EXPORT Container {
    vector<Shape* > list;
public:
    Container();
    ~Container();
    string T;
    void debug();
    void addFigure(Shape * curr);
    void deleteFigure(int curr);
    void moveTo(int X, int Y, int curr);
    void setAngel(int angel, int i);
    vector<Shape*> getFigure();
    void save();
    void load();
    void print();
};
#endif // CONTAINER_H
