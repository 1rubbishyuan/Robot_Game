#ifndef SELECEWINDOW_H
#define SELECEWINDOW_H

#include <QMainWindow>
#include"mymainwindow.h"
class selecewindow : public MyMainWindow
{
    Q_OBJECT
public:
    explicit selecewindow(QWidget *parent = nullptr);
    bool havewinned(int i);
signals:
    void backpressed();
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // SELECEWINDOW_H
