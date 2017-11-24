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
    float x, y, X, Y;
    while (true) {
        if (infile.eof()) break;
        Shape *figure = NULL;
        infile >> Type;
        if (!infile.good())
            break;
        if (Type == 'S') { infile >> x >> X >> Y;	   figure = new Square(x, X, Y); };
        if (Type == 'R') { infile >> x >> y >> X >> Y;  figure = new Rectangle(x, y, X, Y); };
        if (Type == 'C') { infile >> x >> X >> Y;       figure = new Circle(x, X, Y); };
        addFigure(figure);
    }
}
