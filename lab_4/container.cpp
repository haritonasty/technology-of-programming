#include "container.h"


Container::Container(){}
void Container::addFigure(Shape * a) {
    list.push_back(a);
}
void Container::deleteFigure(int a) {
    list.erase(list.begin() + a );
}
void Container::moveTo(int X, int Y, int a) {
    if (list.size() > a) {
        list.at(a)->offsetTo(X, Y);
    }
}
void Container::print(){
for (int i = 0; i < list.size(); i++) {
    cout << list.at(i)->type() <<endl;
    list.at(i)->print();

}
}
vector<Shape*> Container::getFigure()
{
    return list;
}
void Container::setAngel(int angel, int i){
   list.at(i)->changeAngel();
}
void Container::save() {
    ofstream outfile;
    outfile.open("file.txt", ios::out);
    for (int i = 0; i < list.size(); i++) {
        outfile << list.at(i)->type()[0] << " ";
        vector<int>a = list.at(i)->getAll();
        for (int j = 0; j < a.size(); j++)
        {
            outfile << a.at(j) << " ";
        }
        outfile << endl;

    }
    outfile.close();
}
void Container::load() {
    ifstream infile;
    infile.open("file.txt");
    char Type;
    float x, y, X, Y,angel;
    while (true) {
        if (infile.eof()) break;
        Shape *figure = NULL;
        infile >> Type;
        if (!infile.good())
            break;
        if (Type == 'S')
        {
            infile >> X >> Y >> x>>angel;
            figure = new Square;
            vector<int> curr;
            curr.push_back(x);
            figure->setRotation(angel);
            figure->changeAngel();
            figure->setAll(curr);
            figure->offsetTo(X,Y);
        }
        if (Type == 'R')
        { infile >> X >> Y >> x >> y>>angel;
            figure = new Rectangle;
            vector<int> curr;
            curr.push_back(x);
            curr.push_back(y);
            figure->setRotation(angel);
            figure->changeAngel();
            figure->setAll(curr);
            figure->offsetTo(X,Y);
        };
        if (Type == 'C')
        {
            infile >> X >> Y >> x>>angel;
            figure = new Circle;
            vector<int> curr;
            curr.push_back(x);
            figure->setAll(curr);
            figure->setRotation(angel);
            figure->changeAngel();
            figure->offsetTo(X,Y);};
        addFigure(figure);
    }
}
