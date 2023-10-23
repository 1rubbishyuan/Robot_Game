#include "mymap.h"
#include<cstring>
using namespace std;
mymap::mymap()
{
    datas[0].shuliang.ik=3;datas[0].shuliang.keyongork=2;datas[0].shuliang.ok=3;datas[0].shuliang.num_of_mid=0;
    datas[0].orders[0]="inbox",datas[0].orders[1]="outbox";
    datas[0].ins[0].num=1,datas[0].ins[1].num=2,datas[0].ins[2].num=3;
    datas[0].outs[0].num=1,  datas[0].outs[1].num=2,  datas[0].outs[2].num=3;
    mmap.insert(1,datas[0]);
    //第二关
    string m[8]={"inbox", "outbox", "copyfrom", "copyto", "add", "sub", "jump", "jumpifzero"};
    int mm[8]={3 ,9 ,5 ,1, -2 ,-2, 9 ,-9 };
    int mmm[8]={-6 ,6, 4 ,-4 ,0 ,0 ,18 ,-18};
    datas[1].shuliang.ik=8;datas[1].shuliang.keyongork=8;datas[1].shuliang.ok=8;datas[1].shuliang.num_of_mid=3;
    for(int i=0;i<8;i++){
        datas[1].orders[i]=m[i];
        datas[1].ins[i].num=mm[i];
        datas[1].outs[i].num=mmm[i];
    }
    mmap.insert(2,datas[1]);
    //第三关
    string m3[8]={"inbox", "outbox", "copyfrom", "copyto", "add", "sub", "jump", "jumpifzero"};
    int mm3[8]={6, 2, 7 ,7 ,-9, 3 ,-3, -3 };
    datas[2].shuliang.ik=8;datas[2].shuliang.keyongork=8;datas[2].shuliang.ok=2;datas[2].shuliang.num_of_mid=3;
    for(int i=0;i<8;i++){
        datas[2].orders[i]=m3[i];
        datas[2].ins[i].num=mm3[i];
    }
    datas[2].outs[0].num=7,datas[2].outs[1].num=-3;
    mmap.insert(3,datas[2]);
    //自定义第四关
    string m4[8]={"inbox", "outbox", "copyfrom", "copyto", "add", "sub", "jump", "jumpifzero"};
    int mm4[4]={1,2,2,4};
    datas[3].shuliang.ik=2;datas[3].shuliang.keyongork=8;datas[3].shuliang.ok=2;datas[3].shuliang.num_of_mid=4;
  for(int i=0;i<8;i++){
   datas[3].orders[i]=m4[i];
  }
    for(int i=0;i<4;i++){
        datas[3].ins[i].num=mm4[i];
    }
    datas[3].outs[0].num=1,datas[3].outs[1].num=2;datas[3].outs[2].num=4;
    mmap.insert(4,datas[3]);

}
