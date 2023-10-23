#ifndef GUANJIABROWSER_H
#define GUANJIABROWSER_H

#include <QWidget>

namespace Ui {
class guanjiabrowser;
}

class guanjiabrowser : public QWidget
{
    Q_OBJECT

public:
    explicit guanjiabrowser(QWidget *parent = nullptr);
    void writebrowser(QString s);
    ~guanjiabrowser();

private:
    Ui::guanjiabrowser *ui;
};

#endif // GUANJIABROWSER_H
