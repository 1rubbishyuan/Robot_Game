#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
//#include<cstring>
#include <QMainWindow>
#include"mymainwindow.h"
#include"mymap.h"
#include<fstream>
#include"ordersbrower.h"
#include"windialog.h"
#include"mrobots.h"
#include<QLabel>
#include<guanjiabrowser.h>
using namespace std;
class playwindow : public MyMainWindow
{
    Q_OBJECT
public:
   playwindow(int level,QWidget *parent = nullptr);
    void read();
    void inbox();
    void outbox();
    void add(string s);
    void sub(string s);
    void copyto(string s);
    void copyfrom(string s);
    void jump(string s);
    void jumpifzero(string s);
    bool keyong(string ss);
    void game();
    bool judgewin();
    void showplay();
signals:
   void backpressed();
   void youwin();
   void youlose();
   void ji();
   void toinbox();
   void tooutbox();
   void toadd(int x);
   void tosub(int x);
   void tocopyfrom(int x);
   void tocopyto(int x);
   void tojump();
   void tojumpifzero();
//   void inwukuaihide(int x);
//   void inwukuaimove(int x);
//   void outwukuaimove(int x);
   //void timetogettext();
private:
    int level;
    mymap themap;
    string s[1001];
    string textcontent="vanish";
    ofstream fout;
    int jifou;
    ordersbrower ob;
    int  biaohao_of_mid ;
    int recordtake[1001];
    int fuketake;
    int recordmid[1001];
    int fukemid;
    guanjiabrowser gb;
protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // PLAYWINDOW_H
