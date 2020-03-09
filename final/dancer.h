#ifndef DANCER_H
#define DANCER_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class dancer : public QWidget
{
    Q_OBJECT
public:
    explicit dancer(QWidget *parent = 0);
    ~dancer();
    QString bg[16];
    int i=0;
    QTimer *dancetimer;
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // DANCER_H
