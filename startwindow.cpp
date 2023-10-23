#include "startwindow.h"
#include<QPushButton>
#include"mypushbutton.h"
#include<QPainter>
#include<QTimer>
#include<QSound>
startwindow::startwindow(QWidget *parent) : MyMainWindow (parent)
{this->setFixedSize(837,726);
   this->setWindowTitle(QString("start"));
  mypushbutton *btn =new mypushbutton(QString(":/ress/k6j206ee3u385r81bpegckmaqtfwabu.png"),QString(":/ress/k6j206ee3u385r81bpegckmaqtfwabu.png"),this);
  btn->resize(211,211);
  btn->move((this->width()-btn->width())/2,400);
  connect(btn,&mypushbutton::clicked,[=](){

      btn->movedown();
      QSound::play(":/ress/TapButtonSound.wav");
      btn->setEnabled(0);
      QTimer::singleShot(160,[=](){
          btn->moveup();
       });
      QTimer::singleShot(320,[=](){
         btn->setEnabled(1);
         this->hide();
         mselect.show();
      });
  });
  connect(&mselect,&selecewindow::backpressed,[=](){
      this->show();
      mselect.hide();
  });
}

void startwindow::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   QPixmap pix(":/ress/startbejing.png");
   painter.drawPixmap(0,0,this->width(),this->height(),pix);
}


