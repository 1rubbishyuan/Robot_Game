#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("robot"));
    this->setWindowIcon(QIcon(":/ress/k6j206ee3u385r81bpegckmaqtfwabu.png"));

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

