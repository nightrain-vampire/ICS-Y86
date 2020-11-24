#pragma once
#include"R.h"
using namespace std;
class F{//F流水线寄存器，需要实现的功能有：读入一个REGISTER类的PredictPC、输出一个REGISTER类的predPC
    public:
        F(){};
        // void bubble();
        REGISTER get_val();//读数据
        bool write_val(const REGISTER& PredictPC);//写数据

    private:
        REGISTER predPC;//初值是0
};