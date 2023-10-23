#include "playwindow.h"
#include"mypushbutton.h"
#include"mymap.h"
#include<QDebug>
#include<QLabel>
#include<fstream>
#include<QMessageBox>
#include<QTimer>
#include<QEventLoop>
#include<QPainter>
#include<guanjiabrowser.h>//"D:\qtqt\robotgame\guanqia.txt"
#include"windialog.h"
#include"gettext.h"
#include"gamebutton.h"
#include<QSound>
#include<QPropertyAnimation>
#include"ordersbrower.h"
/*1.QString转换String
string s = qstr.toStdString();
2.String转换QString
QString qstr2 = QString::fromStdString(s);
 */
using namespace std;
playwindow::playwindow(int level,QWidget *parent) : MyMainWindow(parent)
{
    ifstream fin;
    fin.open("D:\\qtqt\\robotgame\\guanqia.txt");
    string guanjia;
    while (!(guanjia[0] == '#' && guanjia[1] == level+ '0')) {
           getline(fin, guanjia);
       };

    do{
        getline(fin,guanjia);
        this->gb.writebrowser(QString::fromStdString(guanjia));
    }while(guanjia!="end");
    gb.setAttribute(Qt::WA_DeleteOnClose);
    gb.setWindowIcon(QIcon(":/ress/k6j206ee3u385r81bpegckmaqtfwabu.png"));
    gb.setWindowTitle(QString("orders"));
    gb.move(this->x()-gb.width()+540,this->y()+120);
    gb.show();
    gb.setFixedSize(gb.width(),gb.height());
    mrobots*outwukuai=new mrobots(":/ress/wukuai.jpg",":/ress/wukuai.jpg",this);
    outwukuai->setAttribute(Qt::WA_DeleteOnClose);
    outwukuai->resize(40,40);
    outwukuai->move(555,350);
    outwukuai->hide();
    mrobots*inwukuai=new mrobots(":/ress/wukuai.jpg",":/ress/wukuai.jpg",this);
    inwukuai->setAttribute(Qt::WA_DeleteOnClose);
    inwukuai->resize(40,40);
    inwukuai->move(83,350);
    inwukuai->setFont(QFont("华文新魏",15));
    inwukuai->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    inwukuai->setText(QString::number(this->themap.mmap[level].ins[0].num));
//    mrobots *inwukuai[this->themap.mmap[level].shuliang.ik];
//    for(int i=0;i<this->themap.mmap[level].shuliang.ik;i++){
//         inwukuai[i]=new mrobots(":/ress/wukuai.jpg",":/ress/wukuai.jpg",this);
//         inwukuai[i]->resize(40,40);
//         inwukuai[i]->move(83,350+i*70);
//         inwukuai[i]->setText(QString::number(this->themap.mmap[level].ins[i].num));
//         inwukuai[i]->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//         inwukuai[i]->setFont(QFont("华文新魏",15));
//         inwukuai[i]->show();
//         inwukuai[i]->innum=i+1;
//         connect(this,&playwindow::inwukuaihide,inwukuai[i],&mrobots::mhide);
//    }
   // inwukuai[this->themap.mmap[level].some.in_number-1]->hide();
    mrobots *kongdi[4];
    for(int i=0;i<this->themap.mmap[level].shuliang.num_of_mid;i++){
        kongdi[i]=new mrobots(":/ress/wukuai.jpg",":/ress/wukuai.jpg",this);
    }
    for(int i=0;i<this->themap.mmap[level].shuliang.num_of_mid;i++){
        kongdi[i]->resize(61,61);
        kongdi[i]->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
        kongdi[i]->setFont(QFont("华文新魏",15));
        if(level<=3){
        kongdi[i]->move(160+i*150,480);}
         if(level==4){
            kongdi[i]->move(160+i*100,480);
         }
        kongdi[i]->show();
    }
    ob.setAttribute(Qt::WA_DeleteOnClose);
    ob.setWindowIcon(QIcon("D:\\qtqt\\robotgame\\ress\\k6j206ee3u385r81bpegckmaqtfwabu.png"));
    ob.setWindowTitle(QString("orders"));
    ob.move(this->x()+this->width()+540,this->y()+120);
    ob.show();

    //mrobor(":/ress/kongrobot.jpg","",this);
    mrobots *mrobor=new mrobots(":/ress/kongrobot.jpg",":/ress/grtrobotwithback.jpg",this);
    mrobor->resize(60,80);
    mrobor->move(340,370);
    QLabel *robotlable=new QLabel(mrobor);
    robotlable->setFont(QFont("华文新魏",10));
    robotlable->resize(30,30);
    robotlable->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    robotlable->move(12,3);
    QPixmap pix(":/ress/kongrobot.jpg");
    //pix.scaled(mrobor.size(),Qt::KeepAspectRatio);
    //pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    //ui->label->setScaledContents(true);
    //mrobor.setScaledContents(1);
    // mrobor.setPixmap(pix);
    mrobor->show();
    connect(this,&playwindow::toinbox,[=](){
        fuketake++;
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
        animation->setEndValue(QRect(150,300,mrobor->width(),mrobor->height()));
        animation->setDuration(500);
        animation->start();
        QTimer::singleShot(1000,[=](){
            mrobor->getfou=1;
            inwukuai->hide();
             robotlable->setText(QString::number(this->themap.mmap[level].ins[this->themap.mmap[level].some.in_number-1].num));
            mrobor->update();
            //emit this->inwukuaihide(this->themap.mmap[level].some.in_number);
            inwukuai->move(inwukuai->x(),490);
            inwukuai->setText(QString::number(this->themap.mmap[level].ins[this->themap.mmap[level].some.in_number].num));
           if(this->themap.mmap[level].some.in_number != this->themap.mmap[level].shuliang.ik){
            QTimer::singleShot(500,[=](){
                inwukuai->show();
                QPropertyAnimation *an=new QPropertyAnimation(inwukuai,"geometry",this);
                an->setStartValue(inwukuai->geometry());
                an->setEndValue(QRect(inwukuai->x(),350,inwukuai->width(),inwukuai->height()));
                an->setDuration(1000);
                an->start();
            });}

        });
    });
    connect(this,&playwindow::tooutbox,[=](){
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
        animation->setEndValue(QRect(470,300,mrobor->width(),mrobor->height()));
        animation->setDuration(500);
        animation->start();
        QTimer::singleShot(1000,[=](){
            //使得机器人手上没图，也要让物块放下
            robotlable->setText(" ");
            outwukuai->setText(QString::number(recordtake[fuketake-1]));
            outwukuai->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
            outwukuai->setFont(QFont("华文新魏",15));
            outwukuai->show();
            QPropertyAnimation *an=new QPropertyAnimation(outwukuai,"geometry",this);
            an->setStartValue(outwukuai->geometry());
            an->setEndValue(QRect(outwukuai->x(),490,outwukuai->width(),outwukuai->height()));
            an->setDuration(1000);
            an->start();
            QTimer::singleShot(1100,[=](){
                outwukuai->hide();
                outwukuai->move(555,350);
            });
            mrobor->getfou=0;
            mrobor->update();
        });
    });
    connect(this,&playwindow::tocopyfrom,[=](){
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
        if(level<=3){
         animation->setEndValue(QRect(160+(biaohao_of_mid-1)*150,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        if(level==4){
             animation->setEndValue(QRect(160+(biaohao_of_mid-1)*100,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        animation->setDuration(500);
        animation->start();
        QTimer::singleShot(1500,[=](){ robotlable->setText(QString::number(recordtake[fuketake++]));});
        //mrobor->setText(QString::number(recordtake[fuketake++]));
         mrobor->getfou=1;
    });
    //connect(this,&playwindow::tocopyfrom,mrobor,&mrobots::yundong);
    connect(this,&playwindow::tocopyto,[=](){
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
       if(level<=3){
        animation->setEndValue(QRect(160+(biaohao_of_mid-1)*150,480-mrobor->height(),mrobor->width(),mrobor->height()));}
       if(level==4){
            animation->setEndValue(QRect(160+(biaohao_of_mid-1)*100,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        animation->setDuration(500);
        animation->start();
        QTimer::singleShot(1000,[=](){kongdi[biaohao_of_mid-1]->setText(QString::number(recordmid[fukemid++]));});
        //kongdi[biaohao_of_mid-1]->setText(QString::number(recordmid[fukemid++]));
    });
    connect(this,&playwindow::toadd,[=](){
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
        if(level<=3){
         animation->setEndValue(QRect(160+(biaohao_of_mid-1)*150,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        if(level==4){
             animation->setEndValue(QRect(160+(biaohao_of_mid-1)*100,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        animation->setDuration(500);
        animation->start();
        QTimer::singleShot(1000,[=](){ robotlable->setText(QString::number(recordtake[fuketake++]));});
    });
    connect(this,&playwindow::tosub,[=](){
        QPropertyAnimation *animation=new QPropertyAnimation(mrobor,"geometry",this);
        animation->setStartValue(mrobor->geometry());
        if(level<=3){
         animation->setEndValue(QRect(160+(biaohao_of_mid-1)*150,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        if(level==4){
             animation->setEndValue(QRect(160+(biaohao_of_mid-1)*100,480-mrobor->height(),mrobor->width(),mrobor->height()));}
        animation->setDuration(500);
        animation->start();
       QTimer::singleShot(1000,[=](){robotlable->setText(QString::number(recordtake[fuketake++]));});
    });
    jifou=0;
    fukemid=0;
    fuketake=0;
    this->setFixedSize(this->width(),this->height());
    this->level=level;
    mypushbutton *btn=new mypushbutton(":/ress/BackButton.png",":/ress/BackButtonSelected.png",this);
    btn->resize(78,32);
    btn->move(this->width()-btn->width(),this->height()-btn->height());
    // mymap themap;//mmap允许我访问这一关的信息,关卡关闭后可以自动还原
    connect(btn,&mypushbutton::clicked,[=](){
        ofstream fout("D:\\qtqt\\robotgame\\order.txt");
        fout<<"begin"<<endl;
        fout.close();
        QSound::play(":/ress/BackButtonSound.wav");
        emit this->backpressed();
    });
    //绘制按钮时不可用的直接为红色且不允许点击，只有允许使用的是绿色
    string box[9]={"inbox","outbox","copyfrom","copyto", "add", "sub" ,"jump" ,"jumpifzero","OK"};
    for(int i=0;i<8;i++){
        gamebutton *btn=new gamebutton(QString(":/ress/b%1.jpg").arg(i),QString(":/ress/c%1.png").arg(i),this);
        btn->resize(100,30);
        btn->move(this->width()-btn->width(),50+i*(btn->height()+5));//这里可以塞动画
        if(!keyong(box[i])){
            btn->keyongfou=0;
            btn->setEnabled(0);
        }
        //btn->setText(QString::fromStdString(box[i]));
        if(i<=1){
        connect(btn,&gamebutton::clicked,[=](){
           ofstream fout("D:\\qtqt\\robotgame\\order.txt",ios::app);
            fout<<box[i]<<endl;
            fout.close();
           this->ob.writebrowser(QString::fromStdString(box[i]));
            themap.mmap[level].shuliang.ork++;
            btn->longer();
            btn->setEnabled(0);
            QTimer::singleShot(180,[=](){
                btn->shorter();
            });
            QTimer::singleShot(380,[=](){
                QSound::play(":/ress/TapButtonSound.wav");
                btn->setEnabled(1);
            });
        });}
        else{
            connect(btn,&gamebutton::clicked,[=](){
                 gettext *shuru=new gettext(this);
                 shuru->setAttribute(Qt::WA_DeleteOnClose);
                 shuru->setWindowTitle("请输入参数");
                 btn->longer();
                 btn->setEnabled(0);
                 QTimer::singleShot(180,[=](){
                     btn->shorter();
                 });
                 QTimer::singleShot(350,[=](){
                     QSound::play(":/ress/TapButtonSound.wav");
                     btn->setEnabled(1);
                     shuru->show();
                       });
                 connect(shuru,&gettext::sure,[=](){
                     textcontent=shuru->mgettext();
                     string ms=box[i];
                     //qDebug()<<QString::fromStdString(textcontent);
                     ms+=" ";ms+=textcontent;
                     this->ob.writebrowser(QString::fromStdString(ms));
                     fout.open("D:\\qtqt\\robotgame\\order.txt",ios::app);
                     fout<<box[i]<<" ";
                     fout<<textcontent<<endl;
                     fout.close();
                     //qDebug()<<QString::number(timetogettext);
                     shuru->close();
                      themap.mmap[level].shuliang.ork++;
                 });
                // themap.mmap[level].shuliang.ork++;
           });
        }
    }
    mypushbutton *btn2=new mypushbutton(":/ress/LevelIcon.png",":/ress/LevelIcon.png",this);
    btn2->resize(80,80);
    btn2->move(this->width()-btn2->width(),80+8*(30+5));
    btn2->setText(QString("OK"));
    connect(btn2,&mypushbutton::clicked,[=](){
       //ofstream fout("D:\\qtqt\\robotgame\\order.txt",ios::app);
        //fout<<box[i]<<endl;
        //fout.close();
        //themap.mmap[level].shuliang.ork++;
         //ofstream fout("D:\\qtqt\\robotgame\\order.txt",ios::app);
         //fout<<box[8]<<endl;
         //fout.close();
         //themap.mmap[level].shuliang.ork++;
      QSound::play(":/ress/BackButtonSound.wav");
      game();
    if(!jifou){  QTimer::singleShot(500,[=](){
          showplay();
      });}
    });
    connect(this,&playwindow::youwin,[=](){
        WinDialog *mwin=new WinDialog(QString("You win!"),this);
        mwin->setWindowTitle("神！");
        connect(mwin,&WinDialog::gopressed,[=](){
            mwin->close();
            emit this->backpressed();
        });
        connect(mwin,&WinDialog::cutpressed,[=](){
            mwin->close();
            this->close();
        });
        mwin->exec();
    });
         connect(this,&playwindow::ji,[=](){

         WinDialog *youji=new WinDialog(QString("Error on instruction %1").arg(QString::number(this->themap.mmap[level].some.now_num_of_order-1)),this);
         if(!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 4, "jump")){
             youji->mwrite(QString("Error on instruction %1").arg(QString::number(this->themap.mmap[level].some.now_num_of_order)));
         }
         connect(youji,&WinDialog::gopressed,[=](){
             youji->close();
             emit this->backpressed();
         });
         connect(youji,&WinDialog::cutpressed,[=](){
             youji->close();
             this->close();
         });
         youji->exec();
     });
}
void playwindow::read()
{

}
void playwindow::inbox()
{
    if (this->themap.mmap[level].some.in_number ==this->themap.mmap[level].shuliang.ik ) {//等号后改为总输入传送带上的个数。
        //cout << "Error on instruction "<<this->themap.mmap[level].some.now_num_of_order;
        //exit(0);
        jifou=1;
    }
    else {
        this->themap.mmap[level].robot.now = this->themap.mmap[level].ins[this->themap.mmap[level].some.in_number].num;
        recordtake[fuketake]=themap.mmap[level].robot.now;
        fuketake++;
        this->themap.mmap[level].robot.have = 1;
        this->themap.mmap[level].ins[this->themap.mmap[level].some.in_number].take = 1;
        this->themap.mmap[level].some.in_number++;
    }
}
void playwindow::outbox()
{
    if (this->themap.mmap[level].robot.have == 0) {//改变光标位置,结束游戏
        //cout << "Error on instruction " << some.now_num_of_order;
       // exit(0);
        jifou=1;
    }
    else {
        for (int i = 0; i < this->themap.mmap[level].shuliang.ok; i++) {
            if (this->themap.mmap[level].robot.now == this->themap.mmap[level].outs[i].num && this->themap.mmap[level].outs[i].right == 0) {
               this->themap.mmap[level]. outs[i].right = 1;
                break;
            }
        }
        this->themap.mmap[level].robot.have = 0; this->themap.mmap[level].robot.now = 0;
    }
}
void playwindow::add(string s)
{
    int k = 1, biaohao_of_mid = 0;
        for (int i = s.length() - 1; i >= 4; i--) {
            int last_num = (s[i] - '0') * k;
            k *= 10;
            biaohao_of_mid += last_num;
        }
        if (biaohao_of_mid > this->themap.mmap[level].shuliang.num_of_mid || this->themap.mmap[level].mids[biaohao_of_mid].vanish == 1 || this->themap.mmap[level].robot.have == 0) {
            jifou=1;
        }
        else {
            this->themap.mmap[level].robot.now += this->themap.mmap[level].mids[biaohao_of_mid].num;
            recordtake[fuketake]=themap.mmap[level].robot.now;
            fuketake++;
        }

}
void playwindow::sub(string s)
{
    int k = 1, biaohao_of_mid = 0;
        for (int i = s.length() - 1; i >= 4; i--) {
            int last_num = (s[i] - '0') * k;
            k *= 10;
            biaohao_of_mid += last_num;
        }
        if (biaohao_of_mid > this->themap.mmap[level].shuliang.num_of_mid || this->themap.mmap[level].mids[biaohao_of_mid].vanish == 1 || this->themap.mmap[level].robot.have == 0) {
           // cout << "Error on instruction " << some.now_num_of_order;
           // exit(0);
            jifou=1;
        }
        else {
           this->themap.mmap[level]. robot.now -= this->themap.mmap[level].mids[biaohao_of_mid].num;
            recordtake[fuketake]=themap.mmap[level].robot.now;
            fuketake++;
        }
}
void playwindow::copyto(string s)
{
    int k = 1, biaohao_of_mid = 0;
        for (int i = s.length() - 1; i >= 7; i--) {
            int last_num = (s[i] - '0') * k;
            k *= 10;
            biaohao_of_mid += last_num;
        }
        if (biaohao_of_mid > this->themap.mmap[level].shuliang.num_of_mid || this->themap.mmap[level].robot.have == 0) {
            //cout << "Error on instruction " << some.now_num_of_order;
            //exit(0);
            jifou=1;
        }
        else {this->themap.mmap[level]. mids[biaohao_of_mid].num = this->themap.mmap[level].robot.now;
            recordmid[fukemid]=this->themap.mmap[level]. mids[biaohao_of_mid].num;
               fukemid++;
            this->themap.mmap[level].mids[biaohao_of_mid].vanish = 0;
        }
}
void playwindow::copyfrom(string s)
{
    int k = 1, biaohao_of_mid = 0;
        for (int i = s.length() - 1; i >= 9; i--) {
            int last_num = (s[i] - '0') * k;
            k *= 10;
            biaohao_of_mid += last_num;
        }
        if (biaohao_of_mid > this->themap.mmap[level].shuliang.num_of_mid || this->themap.mmap[level].mids[biaohao_of_mid].vanish == 1) {
            //cout << "Error on instruction " << some.now_num_of_order;
           // exit(0);
            jifou=1;
        }
        else {
            this->themap.mmap[level].robot.now = this->themap.mmap[level].mids[biaohao_of_mid].num;
            recordtake[fuketake]=themap.mmap[level].robot.now;
            fuketake++;
            this->themap.mmap[level].robot.have = 1;
        }
}
void playwindow::jump(string s)
{
    int k = 1, to_num_of_step = 0;
        for (int i = s.length() - 1; i >= 5; i--) {
            int last_num = (s[i] - '0') * k;
            k *= 10;
            to_num_of_step += last_num;
        }
        if (to_num_of_step >= this->themap.mmap[level].shuliang.ork) {
            //this->themap.mmap[level].some.now_num_of_order++;
            jifou=1;
        }
        else {
            this->themap.mmap[level].some.now_num_of_order = to_num_of_step;
        }
}
void playwindow::jumpifzero(string s)
{
    int k = 1, to_num_of_step = 0;
       for (int i = s.length() - 1; i >= 11; i--) {
           int last_num = (s[i] - '0') * k;
           k *= 10;
           to_num_of_step += last_num;
       }
       if (to_num_of_step >= this->themap.mmap[level].shuliang.ork || this->themap.mmap[level].robot.have == 0) {
           //cout << "Error on instruction " << this->themap.mmap[level].some.now_num_of_order;
           //exit(0);
           jifou=1;
          // this->themap.mmap[level].some.now_num_of_order++;
       }
       else {
           if (this->themap.mmap[level].robot.now == 0) this->themap.mmap[level].some.now_num_of_order = to_num_of_step;
           else { this->themap.mmap[level].some.now_num_of_order++; }
       }
}

bool playwindow::keyong(string ss)
{
           bool ans = 0;
           for (int i = 0; i < this->themap.mmap[level].shuliang.keyongork; i++) {
               if (ss == this->themap.mmap[level].orders[i]) { ans = 1; break; }
           }
           //ans = 0;
       return ans;
}



void playwindow::game()
{
    ifstream fin("D:\\qtqt\\robotgame\\order.txt");
  //  qDebug()<<QString::number(this->themap.mmap[level].shuliang.ork);
    for (int i = 1; i <= this->themap.mmap[level].shuliang.ork; i++) {
               getline(fin, s[i]);
               if(s[i]=="begin"||s[i]=="")getline(fin, s[i]);
               //qDebug() <<QString::fromStdString(s[i]) << endl;
               if(s[i]=="OK")break;
           }
           fin.close();
           //fin.close();
     //fin.open("D:\\qtqt\\robotgame\\order.txt");
    while (this->themap.mmap[level].some.now_num_of_order <= this->themap.mmap[level].shuliang.ork) {
               //getline(fin, s);//jump未真正实现跳跃，考虑使用s数组，注意getline的先读取回车,当前步数从1开始，jump后不再++,inbox的改动查看是否完成
               //cout << s[some.now_num_of_order] << endl;//调换jump和jumoifzero的顺序,判断可用集合,最重要的是jump的修改,ork改为输入的总命令数，用keyongork表示可用指令集里的操作数
              //函数基本只有inbox,keyong,jumpifzero需要改动，其余改动在于当前执行到指令几
                //cout <<some.now_num_of_order<<" "<< s[some.now_num_of_order] << endl;
               //qDebug()<<QString::number(themap.mmap[level].some.now_num_of_order);
               if(jifou==1){

                   break;
               }
               if (s[this->themap.mmap[level].some.now_num_of_order] == "inbox") {
                   if (this->themap.mmap[level].some.in_number == this->themap.mmap[level].shuliang.ik) {
                        break;
                   }
                  // cout << 1 << endl;
                   //this->showkeyong(this->themap.mmap[level].some, "inbox", shuliang, orders);
                   this->inbox();
                   this->themap.mmap[level].some.now_num_of_order++;
                   //shownow();//在这里指定坐标打印
               }
               else if (s[this->themap.mmap[level].some.now_num_of_order] == "outbox") {
                 //  cout << 2 << endl;
                  // shownow();
                  // showkeyong(some, "outbox", shuliang, orders);
                   outbox();
                   this->themap.mmap[level].some.now_num_of_order++;//每步动作对应的图像动作,指令移动
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 3, "add")) {
                   //showkeyong(some, "add", shuliang, orders);
                   add(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->themap.mmap[level].some.now_num_of_order++;
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 3, "sub")) {
                   //showkeyong(some, "sub", shuliang, orders);
                   sub(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->themap.mmap[level].some.now_num_of_order++;
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 6, "copyto")) {
                   //showkeyong(some, "copyto", shuliang, orders);
                   copyto(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->themap.mmap[level].some.now_num_of_order++;
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 8, "copyfrom")) {
                  //showkeyong(some, "copyfrom", shuliang, orders);
                   copyfrom(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->themap.mmap[level].some.now_num_of_order++;
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 10, "jumpifzero")) {
                   //showkeyong(some, "jumpifzero", shuliang, orders);
                   jumpifzero(s[this->themap.mmap[level].some.now_num_of_order]);
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 4, "jump")) {
                  // showkeyong(some, "jump", shuliang, orders);
                   jump(s[this->themap.mmap[level].some.now_num_of_order]);
               }
           }
          ofstream fout("D:\\qtqt\\robotgame\\order.txt");
          fout<<"begin"<<endl;
          fout.close();
          if(jifou){emit this->ji(); return ;}
//          if(judgewin()){
//              QSound::play(":/ress/LevelWinSound.wav");
//              emit this->youwin();
//              //QSound::play(":/ress/LevelWinSound.wav");
//              ofstream fout("D:\\qtqt\\robotgame\\record.txt",ios::app);
//              fout<<(char)(level+1+'0')<<endl;
//              fout.close();
//          }
//          else{
//              emit this->youlose();
//              WinDialog *mlose=new WinDialog(QString("You lose!"),this);
//              connect(mlose,&WinDialog::gopressed,[=](){
//                  emit this->backpressed();
//                  mlose->close();
//              });
//              connect(mlose,&WinDialog::cutpressed,[=](){
//                  mlose->close();
//                  this->close();
//              });
//              mlose->show();
//              //qDebug()<<"caisi";
//          }

          // fstream fsm;
          // fsm.open("D:\\qtqt\\robotgame\\order.txt", std::fstream::out | std::ios_base::trunc);
          //在记事本完全为空的情况下可以支持一局游戏

}

bool playwindow::judgewin()
{
    bool ans=1;
    for (int i = 0; i <this->themap.mmap[level].shuliang.ok; i++) {
        if (this->themap.mmap[level].outs[i].right == 0) {
            ans = 0; break;
        }
    }
    return ans;
}
void playwindow::showplay()
{   this->fukemid=0;
    this->fuketake=0;
    this->themap.mmap[level].some.in_number=0;
    this->themap.mmap[level].some.now_num_of_order=1;
    //qDebug()<<QString::number(this->themap.mmap[level].shuliang.ork);
    while (this->themap.mmap[level].some.now_num_of_order <= this->themap.mmap[level].shuliang.ork) {
               if(jifou==1){
                   break;
               }
               //qDebug()<<QString::fromStdString(s[this->themap.mmap[level].some.now_num_of_order]);
               if (s[this->themap.mmap[level].some.now_num_of_order] == "inbox") {
                   if (this->themap.mmap[level].some.in_number == this->themap.mmap[level].shuliang.ik) {
                        break;
                   }
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                  // qDebug()<<"jin";
                   this->themap.mmap[level].some.in_number++;
                   emit this->toinbox();
                   this->themap.mmap[level].some.now_num_of_order++;
                   QEventLoop eventloop;
                   QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                   eventloop.exec();
               }
               else if (s[this->themap.mmap[level].some.now_num_of_order] == "outbox") {
                   emit this->tooutbox();
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                   this->themap.mmap[level].some.now_num_of_order++;//每步动作对应的图像动作,指令移动
                   QEventLoop eventloop;
                   QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                   eventloop.exec();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 3, "add")) {
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                   int k = 1;biaohao_of_mid = 0;
                       for (int i = s[this->themap.mmap[level].some.now_num_of_order].length() - 1; i >= 4; i--) {
                           int last_num = (s[this->themap.mmap[level].some.now_num_of_order][i] - '0') * k;
                           k *= 10;
                           biaohao_of_mid += last_num;
                       }
                   emit this->toadd(biaohao_of_mid);
                   this->themap.mmap[level].some.now_num_of_order++;
                       QEventLoop eventloop;
                       QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                       eventloop.exec();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 3, "sub")) {
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                   int k = 1; biaohao_of_mid = 0;
                       for (int i = s[this->themap.mmap[level].some.now_num_of_order].length() - 1; i >= 4; i--) {
                           int last_num = (s[this->themap.mmap[level].some.now_num_of_order][i] - '0') * k;
                           k *= 10;
                           biaohao_of_mid += last_num;
                       }
                  emit this->tosub(biaohao_of_mid);
                   this->themap.mmap[level].some.now_num_of_order++;
                       QEventLoop eventloop;
                       QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                       eventloop.exec();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 6, "copyto")) {
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                   int k = 1; biaohao_of_mid = 0;
                       for (int i = s[this->themap.mmap[level].some.now_num_of_order].length() - 1; i >= 7; i--) {
                           int last_num = (s[this->themap.mmap[level].some.now_num_of_order][i] - '0') * k;
                           qDebug()<<QString::number((int)(s[this->themap.mmap[level].some.now_num_of_order][i]-'0'));
                           k *= 10;
                           biaohao_of_mid += last_num;
                       }
                       qDebug()<<QString::number(biaohao_of_mid);
                  emit this->tocopyto(biaohao_of_mid);
                   this->themap.mmap[level].some.now_num_of_order++;
                       QEventLoop eventloop;
                       QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                       eventloop.exec();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 8, "copyfrom")) {
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);
                   int k = 1;biaohao_of_mid = 0;
                       for (int i = s[this->themap.mmap[level].some.now_num_of_order].length() - 1; i >= 9; i--) {
                           int last_num = (s[this->themap.mmap[level].some.now_num_of_order][i] - '0') * k;
                           qDebug()<<QString::number((int)(s[this->themap.mmap[level].some.now_num_of_order][i]-'0'));
                           k *= 10;
                           biaohao_of_mid += last_num;
                       }
                       qDebug()<<QString::number(biaohao_of_mid);
                   emit this->tocopyfrom(biaohao_of_mid);
                   this->themap.mmap[level].some.now_num_of_order++;
                       QEventLoop eventloop;
                       QTimer::singleShot(1600, &eventloop, SLOT(quit()));
                       eventloop.exec();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 10, "jumpifzero")) {
                   jumpifzero(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);

                   emit this->tojumpifzero();
               }
               else if (!s[this->themap.mmap[level].some.now_num_of_order].compare(0, 4, "jump")) {
                     jump(s[this->themap.mmap[level].some.now_num_of_order]);
                   this->ob.jiantoumove((themap.mmap[level].some.now_num_of_order-1)*17.33);

                  emit this->tojump();
               }
           }
    if(judgewin()){
        QSound::play(":/ress/LevelWinSound.wav");
        emit this->youwin();
        //QSound::play(":/ress/LevelWinSound.wav");
        ofstream fout("D:\\qtqt\\robotgame\\record.txt",ios::app);
        fout<<(char)(level+1+'0')<<endl;
        fout.close();
    }
    else{
        emit this->youlose();
        WinDialog *mlose=new WinDialog(QString("You lose!"),this);
        mlose->setWindowTitle("你好菜");
        connect(mlose,&WinDialog::gopressed,[=](){
            emit this->backpressed();
            mlose->close();
        });
        connect(mlose,&WinDialog::cutpressed,[=](){
            mlose->close();
            this->close();
        });
        mlose->exec();
        //qDebug()<<"caisi";
    }
}
void  playwindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPixmap pix(":/ress/playscence.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void playwindow::closeEvent(QCloseEvent *event)
{
    ofstream fout("D:\\qtqt\\robotgame\\order.txt");
    fout<<"begin"<<endl;
    fout.close();
    MyMainWindow::closeEvent(event);

}
