#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsItem>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QMouseEvent>

#include "thread.h"

class MainWindow : public QWidget{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsScene *scene;
    QGraphicsView * graphicsView;
signals:
    void changeBright(int new_bright);
public slots:
    void threadUpdate();
    void threadFinish();
    void setItem(QGraphicsItem* item);
private:
    int bright;
    bool threadWorkNow;
    Thread * thread;
    QTimer *timer;
};

#endif // MAINWINDOW_H
