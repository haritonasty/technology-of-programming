#include "rectangle.h"


Rectangle::Rectangle(float Height, float Width) : height(Height), width(Width){}
Rectangle::Rectangle(float Height, float Width, float X, float Y) : Shape(X, Y), height(Height) , width(Width) {}
string Rectangle::type() {
    return "RECTANGLE";
}
void Rectangle::print()
{
    cout<<"height = "<<height<<endl;
    cout<<"width = "<<width<<endl;
    cout<<"x = "<<x<<endl;
    cout<<"y = "<<y<<endl;
}
vector<int> Rectangle::getAll() {
    vector<int> a;
    a.push_back(width);
    a.push_back(height);
    a.push_back(x);
    a.push_back(y);
    return a;
}
