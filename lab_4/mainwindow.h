#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QWidget>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsView>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>
#include "container.h"
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    void pressedCircle();
    void pressedSquare();
    void pressedRectangle();
    void addFigure();
    void save();
    void load();
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();
private:
    Container *wrapper;
    bool activeCircle, activeRectangle, activeSquare;
    int xCounter, yCounter;
    QGraphicsScene *scene;
    QGraphicsView * graphicsView;
    QRadioButton *figure1, *figure2, *figure3;
    QPushButton *buttonSave, *buttonOpen;
    QLineEdit *size1, *size2;
    QHBoxLayout *figures, *sizes,*blockActions;
    QVBoxLayout *blockFigures,*layout;
    QGroupBox *groupButtons,*objFigures,*groupSizes,*groupFigures;
};

#endif // MAINWINDOW_H
