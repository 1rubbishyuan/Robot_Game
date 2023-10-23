#ifndef MYMAP_H
#define MYMAP_H
#include"mydatas.h"
#include<QMap>

class mymap
{
public:
    mymap();
    QMap<int,mydatas> mmap;
        mydatas datas[4];
};

#endif // MYMAP_H
