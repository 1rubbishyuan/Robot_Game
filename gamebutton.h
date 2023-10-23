#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H

#include <QWidget>
#include<QPushButton>
class gamebutton : public QPushButton
{
    Q_OBJECT
public:
    explicit gamebutton(QString keyongpix,QString bukeyongpix, QWidget *parent = nullptr);
    void longer();
    void shorter();
    bool keyongfou;
signals:
protected:
    void paintEvent(QPaintEvent *e);
private:
    QString keyongpix;
    QString bukeyongpix;

};

#endif // GAMEBUTTON_H
