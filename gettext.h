#ifndef GETTEXT_H
#define GETTEXT_H

#include <QDialog>
#include<cstring>
using namespace std;
namespace Ui {
class gettext;
}

class gettext : public QDialog
{
    Q_OBJECT

public:
    explicit gettext(QWidget *parent = nullptr);
    string mgettext();
    ~gettext();

private slots:
    void on_ok_clicked();
signals:
    void sure();
private:
    Ui::gettext *ui;
};

#endif // GETTEXT_H
