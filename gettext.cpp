#include "gettext.h"
#include "ui_gettext.h"

gettext::gettext(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gettext)
{
    ui->setupUi(this);
}

string gettext::mgettext()
{
    return (this->ui->textEdit->toPlainText().toStdString());
}

gettext::~gettext()
{
    delete ui;
}

void gettext::on_ok_clicked()
{
     emit this->sure();
}

