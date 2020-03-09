#ifndef SET_H
#define SET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>
class set : public QWidget
{
    Q_OBJECT
public:
    explicit set(QWidget *parent = 0);
    ~set();
    QString setbg[2];
    int i;
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // SET_H
