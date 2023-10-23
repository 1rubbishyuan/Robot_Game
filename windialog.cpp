#include "windialog.h"
#include "ui_windialog.h"
#include<QPushButton>
#include<QDebug>
WinDialog::WinDialog(QString contents,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialog)
{
    ui->setupUi(this);
    //this->ui->label->setText(contents);
    this->setWindowTitle(QString("请输入参数"));
    this->ui->label->setFont(QFont("华文新魏",20));
     this->ui->label->setText(contents);
    // this->exec();//模态对话框
 }

WinDialog::~WinDialog()
{
    delete ui;
}

void WinDialog::mwrite(QString s)
{
     this->ui->label->setText(s);
}

void WinDialog::on_pushButton_clicked()
{
 emit this->gopressed();
 qDebug()<<"clicked";
}


void WinDialog::on_pushButton_2_clicked()
{
 emit this->cutpressed();
}

