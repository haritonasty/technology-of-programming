#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "figure_global.h"

using namespace std;

class FIGURESHARED_EXPORT Shape {
protected:
    float x, y; //положение в пространстве
public:
    Shape();
    Shape(float coorX, float coorY);
    virtual string type() = 0;
    virtual void print()=0;
    void offsetTo(float X, float Y);
    virtual vector<int> getAll() = 0;
};


#endif // FIGURE_H
