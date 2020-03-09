#include "set.h"

set::set(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(360,100);
    setbg[0]=":/Image/list1.png";
    setbg[1]=":/Image/list2.png";
}
set::~set()
{

}
void set::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    if(i==0)
    {
        pix.load(setbg[0]);
        painter.drawPixmap(0,0,360,100,pix);
    }
    else
    {
        pix.load(setbg[1]);
        painter.drawPixmap(0,0,360,100,pix);
    }
}
