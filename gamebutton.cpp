#include "gamebutton.h"
#include<QPropertyAnimation>
#include<QPainter>
gamebutton::gamebutton(QString keyongpix,QString bukeyongpix,QWidget *parent) : QPushButton(parent)
{
    keyongfou=1;
    this->keyongpix=keyongpix;
    this->bukeyongpix=bukeyongpix;
}
void gamebutton::longer()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x()-20,this->y(),this->width()+20,this->height()));
    animation->setDuration(150);
    animation->start();
}
void gamebutton::shorter()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x()+20,this->y(),this->width()-20,this->height()));
    animation->setDuration(150);
    animation->start();
}
void gamebutton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    if(keyongfou){pix.load(keyongpix);}
    else{pix.load(bukeyongpix);}
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

