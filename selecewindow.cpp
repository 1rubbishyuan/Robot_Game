#include "selecewindow.h"
#include"mypushbutton.h"
#include"playwindow.h"
#include<QPainter>
#include<fstream>
#include<QSound>
#include<QDebug>
using namespace std;
selecewindow::selecewindow(QWidget *parent) : MyMainWindow(parent)
{  this->setFixedSize(480,882);
   mypushbutton *btn=new mypushbutton(":/ress/BackButton.png",":/ress/BackButton.png",this);
   btn->resize(78,32);
   btn->move(this->width()-btn->width(),this->height()-btn->height());
   connect(btn,&mypushbutton::clicked,[=](){
       QSound::play(":/ress/BackButtonSound.wav");
       emit this->backpressed();
   });
   const int xoffset=80;
   const int yoffset=240;
   const int rowheight=530-240;//再调
   const int colwidth=240;
   mypushbutton *btn1[4];
   for(int i=0;i<4;i++){
       btn1[i]=new mypushbutton(":/ress/LevelIcon.png",":/ress/LevelIcon.png",this);
   }
   for(int i=0;i<4;i++){
       //playwindow *mplay=new playwindow(i+1,this);
       //mplay->setAttribute(Qt::WA_DeleteOnClose);
       //btn1[i]=new mypushbutton("D:\\qtqt\\robotgame\\ress\\LevelIcon.png",this);
       if(!havewinned(i+1)){
           btn1[i]->setEnabled(0);
           //设置图片
       }
       btn1[i]->setText(QString::number(i+1));
       btn1[i]->setFont(QFont("华文新魏",20));
       btn1[i]->resize(81,81);
       int row = i/2;
       int col=  i%2;
       int x=xoffset+col*colwidth;
       int y=yoffset+row*rowheight;
       btn1[i]->move(x,y);//位置之后再调
       connect(btn1[i],&mypushbutton::clicked,[=](){
           //qDebug()<<"sd";
           QSound::play(":/ress/ConFlipSound.wav");
           playwindow *mplay=new playwindow(i+1,this);
            mplay->setAttribute(Qt::WA_DeleteOnClose);
           this->hide();
           mplay->show();
           connect(mplay,&playwindow::backpressed,[=](){
               this->show();
               mplay->close();
           });
           connect(mplay,&playwindow::youwin,[=](){
               if(i<3){
               if(!btn1[i+1]->isEnabled()){
                   btn1[i+1]->setEnabled(1);
               }}
           });
       });
   }

}

bool selecewindow::havewinned(int i)
{       bool ans=0;
        fstream fin("D:\\qtqt\\robotgame\\record.txt");
        string s;
        while(!fin.eof()){
             fin>>s;
             if(s[0]==i+'0'){
                 ans=1;break;
             }
        }
       return ans;
}

void selecewindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix(":/ress/OtherSceneBg.png");
   painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
