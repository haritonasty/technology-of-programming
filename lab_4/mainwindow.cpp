#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent){
        wrapper = new Container();
        activeCircle = false;
        activeRectangle = false;
        activeSquare = false;

        setFixedSize(600,800);

        graphicsView = new QGraphicsView();
        graphicsView->resize(600, 600);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,600,600);
        graphicsView->setScene(scene);


        blockFigures = new QVBoxLayout;
        figures = new QHBoxLayout;
        figure1 = new QRadioButton("Circle");
        figure2 = new QRadioButton("Square");
        figure3 = new QRadioButton("Rectangle");
        groupFigures = new QGroupBox("Shape:");
        figures->addWidget(figure1);
        figures->addWidget(figure2);
        figures->addWidget(figure3);
        groupFigures->setLayout(figures);
        blockFigures->addWidget(groupFigures);

        size1 = new QLineEdit("100");
        size2 = new QLineEdit("250");
        sizes = new QHBoxLayout;
        groupSizes = new QGroupBox("Change size:");
        sizes->addWidget(size1);
        sizes->addWidget(size2);
        groupSizes->setLayout(sizes);
        blockFigures->addWidget(groupSizes);
        objFigures = new QGroupBox("Figures:");
        objFigures->setLayout(blockFigures);

        blockActions = new QHBoxLayout;
        buttonOpen = new QPushButton("Open");
        buttonSave = new QPushButton("Save");
        blockActions->addWidget(buttonOpen);
        blockActions->addWidget(buttonSave);
        groupButtons = new QGroupBox("Actions:");
        groupButtons->setLayout(blockActions);

        layout = new QVBoxLayout();
        layout->addWidget(graphicsView);
        layout->addWidget(objFigures);
        layout->addWidget(groupButtons);
        setLayout(layout);
        connect(figure1, &QRadioButton::clicked, this, &MainWindow::pressedCircle);
        connect(figure2, &QRadioButton::clicked, this, &MainWindow::pressedSquare);
        connect(figure3, &QRadioButton::clicked, this, &MainWindow::pressedRectangle);
        connect(buttonSave,&QPushButton::clicked,this,&MainWindow::save);
        connect(buttonOpen,&QPushButton::clicked,this,&MainWindow::load);

    }


void MainWindow::pressedCircle(){
    activeCircle = true;
    activeRectangle = false;
    activeSquare = false;
    size2->setEnabled(false);
}
void MainWindow::pressedSquare(){
    activeCircle = false;
    activeRectangle = false;
    activeSquare = true;
    size2->setEnabled(false);
}
void MainWindow::pressedRectangle(){
    activeCircle = false;
    activeRectangle = true;
    activeSquare = false;
    size2->setEnabled(true);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x=event->pos().x(),y=event->pos().y();
    if(x <= 586 && x >= 13 && y <= 535 && y >= 13)
    {
        xCounter = x;
        yCounter = y+25;
        addFigure();

    }

   }

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QList<QGraphicsItem*> curr = scene->selectedItems();
    if(event->key() == Qt::Key_Less )
    {
        for (int i=0; i<curr.size(); i++)
        {
            curr[i]->setRotation(curr[i]->rotation()+1);
        }
    }
    if(event->key() == Qt::Key_Greater )
    {
        for (int i=0; i<curr.size(); i++)
        {
             curr[i]->setRotation(curr[i]->rotation()-1);

        }
    }
}
void MainWindow::addFigure()
{
    bool check =false;
    Shape * curr;
    vector<int> Properties;
    if (activeCircle)
    {

        curr=new Circle();
        Properties.push_back(size1->text().toInt());
        check=true;
    }
    if (activeSquare)
    {

        curr=new Square();
        Properties.push_back(size1->text().toInt());
        check=true;
    }
    if (activeRectangle)
    {
        curr=new Rectangle();
        Properties.push_back(size1->text().toInt());
        Properties.push_back(size2->text().toInt());
        check=true;
    }
    if(check)
    {
        curr->setPos(xCounter,yCounter);
        curr->offsetTo(xCounter,yCounter);
        curr->setAll(Properties);
        scene->addItem(curr);
        wrapper->addFigure(curr);
    }

}

void MainWindow::save()
{
    vector<Shape*> list=wrapper->getFigure();
    wrapper->print();
    for (int i=0;i<list.size();i++)
    {

        list.at(i)->changeAngel();
        QPointF curr=list.at(i)->pos();
        list.at(i)->offsetTo(curr.x(),curr.y());
    }
    wrapper->save();
}
void MainWindow::load()
{
    vector<Shape*> list=wrapper->getFigure();
    int i = list.size();
    wrapper->load();
    list = wrapper->getFigure();
    for (; i<list.size(); i++)
    {
        vector<int> curr=list.at(i)->getAll();
        list.at(i)->setPos(curr.at(0),curr.at(1));
        scene->addItem(list.at(i));
    }

}


MainWindow::~MainWindow(){
    delete wrapper;
    delete scene;
    delete graphicsView;
}
