#include "oni.h"

oni::oni(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(250,250);
    onibg[0]=":/Image/purple1.png";
    onibg[1]=":/Image/purple2.png";
    onitimer = new QTimer(this);
    connect(onitimer,SIGNAL(timeout()),this,SLOT(update()));
    onitimer->start(8);
}
oni::~oni()
{

}
void oni::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        pix.load(onibg[i]);
        painter.drawPixmap(0,0,250,250,pix);
    }
    else
    {
        pix.load(onibg[i]);
        painter.drawPixmap(0,0,250,250,pix);
        if(time<10)
            time++;
        else
        {
            i=0;
            time=0;
        }
    }
}
