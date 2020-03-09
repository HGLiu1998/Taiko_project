#ifndef ONI_H
#define ONI_H

#include <QWidget>
#include <cmath>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class oni : public QWidget
{
    Q_OBJECT
public:
    explicit oni(QWidget *parent = 0);
    ~oni();
    QString onibg[2];
    int i=0;
    int time=0;
    QTimer *onitimer;
protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // ONI_H
