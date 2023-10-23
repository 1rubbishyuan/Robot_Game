#ifndef MYDATAS_H
#define MYDATAS_H
#include<string>
using namespace std;
class mydatas
{
public:
    mydatas();
    struct shuliangs
    {
         int ik, ork=0, ok ,num_of_mid ,keyongork;//输入积木数，输入的指令数量，要输出的积木数，空地数，可用指令集合中的指令数
    }shuliang;
    struct my_in {
        bool take = 0;//是否被拿走
        int num = 0;//数字
    }ins[20];
    //int num_of_mid=0;这个指关卡的总空地数
    struct my_mid {
        bool vanish = 1;//空地是否为空
        int num = 0;//数字
    }mids[20];
    struct my_out {
        int num = 0;//数字
        bool right = 0;//是否输出了该结果
    }outs[20];
    struct robots
    {
        int now = 0;//机器人手上的积木数字
        bool have = 0;//机器人手上有没有东西
    }robot;
    struct some_information {
        int in_number = 0;//目前传送带上的未被拿走的积木的最小标号
        int now_num_of_order = 1;//现在在第几步指令
    }some;
    string orders[20];//可用指令集合
};

#endif // MYDATAS_H
