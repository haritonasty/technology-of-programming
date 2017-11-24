#include <QCoreApplication>
#include "container.h"
void start(){
    Container pull;
    pull.load();
    pull.print();
    pull.moveTo(1,0,0);
    pull.print();
    pull.deleteFigure(0);
    pull.print();
}

int main(){
    start();
    cin.get();
    cin.get();
}
