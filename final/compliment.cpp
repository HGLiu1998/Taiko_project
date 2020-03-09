#include "compliment.h"

compliment::compliment(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(120,60);
    bg[0]=":/Image/bad.png";
    bg[1]=":/Image/ok.png";
    bg[2]=":/Image/great.png";
    bgtimer = new QTimer(this);
    connect(bgtimer,SIGNAL(timeout()),this,SLOT(update()));
    bgtimer->start(8);
}
compliment::~compliment()
{

}
void compliment::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        pix.load(bg[i]);
        painter.drawPixmap(0,0,120,60,pix);
    }
    else if(i==1)
    {
        pix.load(bg[i]);
        painter.drawPixmap(0,0,60,60,pix);
    }
    else
    {
        pix.load(bg[i]);
        painter.drawPixmap(0,0,60,60,pix);
    }
}
