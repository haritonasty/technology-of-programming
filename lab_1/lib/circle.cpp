#include "circle.h"


Circle::Circle(float Radius) : radius(Radius) {}
Circle::Circle(float Radius, float X, float Y) : Shape(X,Y), radius(Radius) {}
string Circle::type() {
    return "CIRCLE";
}
void Circle::print()
{
    cout<<"radius = "<<radius<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
}
vector<int> Circle::getAll() {
    vector<int> a;
    a.push_back(radius);
    a.push_back(x);
    a.push_back(y);
    return a;
}
