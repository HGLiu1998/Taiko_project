#ifndef ARROW_H
#define ARROW_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
class Arrow : public QWidget
{
    Q_OBJECT
public:
    explicit Arrow(QWidget *parent = 0);
    ~Arrow();
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // ARROW_H
