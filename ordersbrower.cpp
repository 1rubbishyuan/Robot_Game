#include "ordersbrower.h"
#include "ui_ordersbrower.h"
#include<QPropertyAnimation>
ordersbrower::ordersbrower(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ordersbrower)
{
    ui->setupUi(this);
     this->ui->textBrowser->setFont(QFont("华文新魏",10));
}

void ordersbrower::writebrowser(QString s)
{
    this->ui->textBrowser->append(s);//拿下
}

void ordersbrower::jiantoumove(double y)
{
    QPropertyAnimation *animation=new QPropertyAnimation(this->ui->label,"geometry",this);
    animation->setStartValue(this->ui->label->geometry());
    animation->setEndValue(QRect(this->ui->label->x(),y,this->ui->label->width(),this->ui->label->height()));
    animation->setDuration(500);
    animation->start();
}

ordersbrower::~ordersbrower()
{
    delete ui;
}
