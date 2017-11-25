#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsView>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    QGraphicsScene *scene;
    QGraphicsView * graphicsView;
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();
};

#endif // MAINWINDOW_H
