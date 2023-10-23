#include "guanjiabrowser.h"
#include "ui_guanjiabrowser.h"

guanjiabrowser::guanjiabrowser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guanjiabrowser)
{
    ui->setupUi(this);
    this->ui->textBrowser->setFont(QFont("华文新魏",15));
}

void guanjiabrowser::writebrowser(QString s)
{
    this->ui->textBrowser->append(s);
}

guanjiabrowser::~guanjiabrowser()
{
    delete ui;
}
