#include "taku.h"

taku::taku(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(300,200);
    //this->setFixedSize(94,85);
    go[0]=":/Image/tako.png";
    go[1]=":/Image/redright.png";
    go[2]=":/Image/redleft.png";
    go[3]=":/Image/blueright.png";
    go[4]=":/Image/blueleft.png";
    gotimer = new QTimer(this);
    connect(gotimer,SIGNAL(timeout()),this,SLOT(update()));
    gotimer->start(8);
}
taku::~taku()
{

}
void taku::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        pix.load(go[i]);
        painter.drawPixmap(0,0,300,200,pix);
    }
    if(i==1)
    {
        pix.load(go[i]);
        painter.drawPixmap(0,0,300,200,pix);
        if(j<=10)
            j++;
        else
        {
            j=0;
            i=0;
        }
    }
    if(i==2)
    {
        pix.load(go[i]);
        painter.drawPixmap(0,0,300,200,pix);
        if(j<=10)
            j++;
        else
        {
            j=0;
            i=0;
        }
    }
    if(i==3)
    {
        pix.load(go[i]);
        painter.drawPixmap(0,0,300,200,pix);
        if(j<=10)
            j++;
        else
        {
            j=0;
            i=0;
        }
    }
    if(i==4)
    {
        pix.load(go[i]);
        painter.drawPixmap(0,0,300,200,pix);
        if(j<=10)
            j++;
        else
        {
            j=0;
            i=0;
        }
    }
}
