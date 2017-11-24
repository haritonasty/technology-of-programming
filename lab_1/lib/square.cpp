#include "square.h"


Square::Square(float Side) : side(Side) {}
Square::Square(float Side, float X, float Y) : Shape(X, Y), side(Side) {}
string Square::type() {
    return "SQUARE";
}
void Square::print()
{
    cout<<"side = "<<side<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
}
vector<int> Square::getAll() {
    vector<int> a;
    a.push_back(side);
    a.push_back(x);
    a.push_back(y);
    return a;
}
