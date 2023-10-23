#ifndef MROBOTS_H
#define MROBOTS_H

#include <QWidget>
#include<QLabel>
class mrobots : public QLabel
{
    Q_OBJECT
public:
    explicit mrobots(QString wu,QString get ,QWidget *parent = nullptr);
    int getfou;
    int innum;
signals:
protected:
   void paintEvent(QPaintEvent *e);
public slots:
   void yundong(int x);
   void mhide(int x);
 private:
    QString wu;
    QString get;

};

#endif // MROBOTS_H
