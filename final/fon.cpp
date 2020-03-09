#include "fon.h"

fon::fon(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(20,50);
    gb[0]=":/Image/bad.png";
    gb[1]=":/Image/ok.png";
    gb[2]=":/Image/great.png";
}
fon::~fon()
{

}
fon::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        pix.load(gb[i]);
        painter.drawPixmap(0,0,20,50,pix);
    }
    else if(i==1)
    {
        pix.load(gb[i]);
        painter.drawPixmap(0,0,20,50,pix);
    }
    else
    {
        pix.load(gb[i]);
        painter.drawPixmap(0,0,20,50,pix);
    }
}
