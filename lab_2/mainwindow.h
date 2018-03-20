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
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    QGraphicsView * graphicsView;
};

#endif // MAINWINDOW_H
