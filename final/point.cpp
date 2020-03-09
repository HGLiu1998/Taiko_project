#include "point.h"

point::point(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(100,100);
    //this->setFixedSize(43,42);
    small[0][0]=":/Image/red1.png";
    small[0][1]=":/Image/red2.png";
    small[1][0]=":/Image/blue1.png";
    small[1][1]=":/Image/blue2.png";
    /*pointtimer = new QTimer(this);
    connect(pointtimer,SIGNAL(timeout()),this,SLOT(update()));
    pointtimer->start(10);*/
}
point::~point()
{

}
void point::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        if(j==0)
        {
            pix.load(small[0][0]);
            painter.drawPixmap(0,0,100,100,pix);
            j++;
        }
        else
        {
            pix.load(small[0][1]);
            painter.drawPixmap(0,0,100,100,pix);
            j--;
        }
    }
    else if(i==1)
    {
        if(j==0)
        {
            pix.load(small[1][0]);
            painter.drawPixmap(0,0,100,100,pix);
            j++;
        }
        else
        {
            pix.load(small[1][1]);
            painter.drawPixmap(0,0,100,100,pix);
            j--;
        }
    }
    else
    {
        painter.drawPixmap(0,0,100,100,pix);
    }
}
