#ifndef PLAYPART_H
#define PLAYPART_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class playpart : public QWidget
{
    Q_OBJECT
public:
    explicit playpart(QWidget *parent = 0);
    ~playpart();
    int i=0;
    QTimer *hittimer;
protected:
    void paintEvent(QPaintEvent *event);
private:
    QString listbg[3];
signals:

public slots:
};

#endif // PLAYPART_H
