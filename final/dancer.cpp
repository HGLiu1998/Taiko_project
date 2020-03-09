#include "dancer.h"

dancer::dancer(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(130,200);
    bg[0]=":/Image/dancer_4n1.png";
    bg[1]=":/Image/dancer_4n2.png";
    bg[2]=":/Image/dancer_4n3.png";
    bg[3]=":/Image/dancer_4n4.png";
    bg[4]=":/Image/dancer_4n5.png";
    bg[5]=":/Image/dancer_4n6.png";
    bg[6]=":/Image/dancer_4n7.png";
    bg[7]=":/Image/dancer_4n8.png";
    bg[8]=":/Image/dancer_4n9.png";
    bg[9]=":/Image/dancer_4n10.png";
    bg[10]=":/Image/dancer_4n11.png";
    bg[11]=":/Image/dancer_4n12.png";
    bg[12]=":/Image/dancer_4n13.png";
    bg[13]=":/Image/dancer_4n14.png";
    bg[14]=":/Image/dancer_4n15.png";
    bg[15]=":/Image/dancer_4n16.png";
    dancetimer = new QTimer(this);
    connect(dancetimer,SIGNAL(timeout()),this,SLOT(update()));
    dancetimer->start(8);
}
dancer::~dancer()
{

}
void dancer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    int h=0;
    if(h==0)
    {
        i++;
        if(i==15)    h=1;
    }
    if(h==1)
    {
        i--;
        if(i==0)    h=0;
    }
    pix.load(bg[i]);
    painter.drawPixmap(0,0,120,60,pix);

}
