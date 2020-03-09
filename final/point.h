#ifndef POINT_H
#define POINT_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>


class point : public QWidget
{
    Q_OBJECT
public:
    explicit point(QWidget *parent = 0);
    ~point();
    int i;//red or blue
    int j=0;
    QString small[3][2];
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer *pointtimer;
signals:

public slots:
};

#endif // POINT_H
