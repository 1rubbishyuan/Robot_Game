#include "mrobots.h"
#include<QPainter>
#include<QPropertyAnimation>
#include<QDebug>
mrobots::mrobots(QString wu, QString get, QWidget *parent) : QLabel(parent)
{
    getfou=0;
    this->wu=wu;
    this->get=get;
    this->setContentsMargins(30,30,0,80);
}

void mrobots::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    if(getfou==0){pix.load(wu);}
    else{pix.load(get);}
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    QLabel::paintEvent(e);
}

void mrobots::yundong(int x)
{   if(x==innum){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(160+(x-1)*150,480,this->width(),this->height()));
    animation->setDuration(500);
    animation->start();}
}

void mrobots::mhide(int x)
{
    if(x==innum){
        this->hide();
    }
}
