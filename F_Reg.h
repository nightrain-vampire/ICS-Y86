#pragma once
#include"R.h"
using namespace std;
class F_REGISTER{
    public:
        F_REGISTER(){};
        REGISTER get_val(){return predPC;};//读数据
        void write_val(REGISTER PredictPC){if(flag) predPC=PredictPC;}//写数据
        void disable(){flag=0;}//置为不可更改
        void enable(){flag=0;}
    private:
        REGISTER predPC;//初值是0
        int flag=1;
};