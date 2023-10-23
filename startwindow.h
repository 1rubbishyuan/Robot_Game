#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include"mymainwindow.h"
#include"selecewindow.h"
class startwindow : public MyMainWindow
{
    Q_OBJECT
public:
    explicit startwindow(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
signals:
private:
    selecewindow mselect;
};

#endif // STARTWINDOW_H
