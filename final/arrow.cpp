#include "arrow.h"

Arrow::Arrow(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(41,27);
}
Arrow::~Arrow()
{

}
void Arrow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/steer.png");
    painter.drawPixmap(0,0,41,27,pix);
}
