#ifndef COMPLIMENT_H
#define COMPLIMENT_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class compliment : public QWidget
{
    Q_OBJECT
public:
    explicit compliment(QWidget *parent = 0);
    ~compliment();
    QString bg[3];
    int i;
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer *bgtimer;
signals:

public slots:
};

#endif // COMPLIMENT_H
