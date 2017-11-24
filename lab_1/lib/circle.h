#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


class FIGURESHARED_EXPORT Circle : public Shape {
    float radius;
public:
    Circle(float Radius);
    Circle(float Radius, float X, float Y);
    string type();
    void print();
    vector<int> getAll();
};

#endif // CIRCLE_H
