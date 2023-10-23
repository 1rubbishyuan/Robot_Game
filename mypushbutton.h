#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    enum selectstats{kexuan,winned,suo};
    enum pressstats{pressed,released};
    enum playbuttonstats{movein,moveout};
     mypushbutton(QString beginpix,QString endpix ,QWidget *parent = nullptr);
  void moveup();
  void movedown();
  void longer();
  void shorter();
  bool keyongfou;
signals:
protected:
     void paintEvent(QPaintEvent *e);
     void mousePressEvent(QMouseEvent *e);
     void mouseReleaseEvent(QMouseEvent *e);
private:
    selectstats stat;
    pressstats stat1;
    QString beginpix,endpix;
    playbuttonstats playstat;

};

#endif // MYPUSHBUTTON_H
