#include <QCoreApplication>
#include "container.h"
void start()
{
    int x, y, h, w, r, s;
    char type;
    Container pull;
    while (true)
    {
        cout << "1: addFigure, 0: printResults" << endl;
        int trigger = 0;
        cin >> trigger;
        if (trigger == 0) break;
        if (trigger == 1){
            Shape *figure = NULL;
            cout << "C: Circle, S: Square, R: Rectangle" << endl;
            cin >> type;
            switch (type){
                case 'C':{
                    cout << "x:"; cin >> x;
                    cout << "y:"; cin >> y;
                    cout << "radius:"; cin >> r;
                    figure = new Circle(r, x, y);
                    pull.addFigure(figure);
                    break;
                }
                case 'R':{
                    cout << "x:"; cin >> x;
                    cout << "y:"; cin >> y;
                    cout << "height:"; cin >> h;
                    cout << "width:"; cin >> w;
                    figure = new Rectangle(h, w, x, y);
                    pull.addFigure(figure);
                    break;
                }
                case 'S':{
                    cout << "x:"; cin >> x;
                    cout << "y:"; cin >> y;
                    cout << "side:"; cin >> s;
                    figure = new Square(s, x, y);
                    pull.addFigure(figure);
                    break;
                }
                default:
                    break;
            }
        }

    }
    pull.save();
    pull.print();
}

int main()
{
    start();
    cin.get();
    cin.get();
}
