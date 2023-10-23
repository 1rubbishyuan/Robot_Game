#ifndef ORDERSBROWER_H
#define ORDERSBROWER_H

#include <QWidget>

namespace Ui {
class ordersbrower;
}

class ordersbrower : public QWidget
{
    Q_OBJECT

public:
    explicit ordersbrower(QWidget *parent = nullptr);
    void writebrowser(QString s);
    void jiantoumove(double y);
    ~ordersbrower();

private:
    Ui::ordersbrower *ui;
};

#endif // ORDERSBROWER_H
