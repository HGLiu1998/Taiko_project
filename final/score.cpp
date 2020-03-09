#include "score.h"

score::score(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(35,35);
    scoreimg[0]=":/Image/0.png";
    scoreimg[1]=":/Image/1.png";
    scoreimg[2]=":/Image/2.png";
    scoreimg[3]=":/Image/3-3.png";
    scoreimg[4]=":/Image/4-4.png";
    scoreimg[5]=":/Image/5-5.png";
    scoreimg[6]=":/Image/6.png";
    scoreimg[7]=":/Image/7.png";
    scoreimg[8]=":/Image/8.png";
    scoreimg[9]=":/Image/9.png";
    scoretimer = new QTimer(this);
    connect(scoretimer,SIGNAL(timeout()),this,SLOT(update()));
    scoretimer->start(8);
}
score::~score()
{

}
void score::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(scoreimg[i%10]);
    painter.drawPixmap(0,0,35,35,pix);
}
