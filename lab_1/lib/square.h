#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class FIGURESHARED_EXPORT Square : public Shape {
    float side;
public:
    Square(float Side);
    Square(float Side, float X, float Y);
    string type();
    void print();
    vector<int> getAll();
};
#endif // SQUARE_H
