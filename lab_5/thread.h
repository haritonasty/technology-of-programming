#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include <QGraphicsItem>
#include <QTime>
#include <QGraphicsScene>

class Thread:public QThread
{
    Q_OBJECT
public:
    explicit Thread(int thread);
    void run();
public slots:
    void changeBright(int new_bright);
signals:
    void getItem(QGraphicsItem * item);
private:
    int bright;
};

#endif // THREAD_H
