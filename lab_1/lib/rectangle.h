#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"



class FIGURESHARED_EXPORT Rectangle : public Shape {
    double height, width;
public:
    Rectangle(float Height, float Width);
    Rectangle(float Height, float Width, float X, float Y);
    string type();
    void print();
    vector<int> getAll();
};

#endif // RECTANGLE_H
