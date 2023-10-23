#ifndef ROBOTERS_H
#define ROBOTERS_H

#include <QObject>
#include<QLabel>
class roboters : public QLabel
{
    Q_OBJECT
public:
    explicit roboters(QString wu,QString get, QObject *parent = nullptr);
    int getfou=0;
signals:

};

#endif // ROBOTERS_H
