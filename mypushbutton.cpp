#include "mypushbutton.h"
#include<QPainter>
#include<QPropertyAnimation>
mypushbutton::mypushbutton(QString beginpix,QString endpix ,QWidget *parent) : QPushButton(parent)
{
    keyongfou=1;
     this->setStyleSheet("QPushButton{border:0px;}");
     this->beginpix=beginpix;
    this->endpix=endpix;
    this->stat1=released;
    this->playstat=moveout;

}
void mypushbutton::paintEvent(QPaintEvent *e){

    QPainter painter(this);
    QPixmap pix;
    if(this->stat1==pressed||!keyongfou){
        pix.load(this->endpix);
    }
    else{
        pix.load(this->beginpix);
    }
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
     painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter|Qt::AlignVCenter,this->text());
}
void mypushbutton::moveup(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(150);
    animation->start();
}
void mypushbutton::movedown(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(150);
    animation->start();
}

void mypushbutton::longer()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x()-20,this->y(),this->width()+20,this->height()));
    animation->setDuration(150);
    animation->start();
}

void mypushbutton::shorter()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x()+20,this->y(),this->width()-20,this->height()));
    animation->setDuration(150);
    animation->start();
}
void mypushbutton::mousePressEvent(QMouseEvent *e){
    stat1=pressed;
    update();
    QPushButton::mousePressEvent(e);

}
void mypushbutton::mouseReleaseEvent(QMouseEvent *e){
    stat1=released;
    update();
    QPushButton::mouseReleaseEvent(e);
}

