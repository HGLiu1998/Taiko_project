#ifndef TAKU_H
#define TAKU_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class taku : public QWidget
{
    Q_OBJECT
public:
    explicit taku(QWidget *parent = 0);
    QString go[5];
    int i=0;
    int j=0;
    ~taku();
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer *gotimer;
signals:

public slots:
};

#endif // TAKU_H
