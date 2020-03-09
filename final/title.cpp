#include "title.h"

title::title(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(800,800);
}
title::~title()
{

}

void title::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/master.png");
    painter.drawPixmap(0,600,700,150,pix);

}
