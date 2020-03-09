#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class score : public QWidget
{
    Q_OBJECT
public:
    explicit score(QWidget *parent = 0);
    int i=0;
    ~score();
protected:
    void paintEvent(QPaintEvent *);

private:
    QString scoreimg[10];

    int total=0;
    QTimer *scoretimer;
signals:

public slots:
};

#endif // SCORE_H
