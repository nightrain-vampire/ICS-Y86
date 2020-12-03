#pragma once
#include"R.h"
using namespace std;
class F_REGISTER{
    public:
        F_REGISTER(){};
        REGISTER get_val(){return pc;};//读数据
        void write_val(REGISTER predPC){pc=predPC;}//写数据
    private:
        REGISTER pc;//初值是0
};