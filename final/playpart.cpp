#include "playpart.h"

playpart::playpart(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(1800,200);
    listbg[0]=":/Image/list.png";
    listbg[1]=":/Image/hitred.png";
    listbg[2]=":/Image/hitblue.png";
}
playpart::~playpart()
{

}
void playpart::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0){
        pix.load(listbg[0]);
        painter.drawPixmap(0,0,1800,200,pix);
    }
    else if(i==1)
    {
        pix.load(listbg[1]);
        painter.drawPixmap(0,0,1800,200,pix);
        i=0;
    }
    else
    {
        pix.load(listbg[2]);
        painter.drawPixmap(0,0,1800,200,pix);
        i=0;
    }
}
