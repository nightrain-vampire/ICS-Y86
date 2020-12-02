#pragma once
#include"R.h"

class W_REGISTER
{
    public:
        W_REGISTER(){}

        //读取函数
        char get_stat(){return W_stat;}
        char get_icode(){return W_icode;}
        char get_dstE(){return W_dstE;}
        char get_dstM(){return W_dstM;}
        REGISTER get_valE(){return W_valE;}
        REGISTER get_valM(){return W_valM;}

        //写入函数
        void write_stat(const char s){W_stat=s;}
        void write_icode(const char s){W_icode=s;}
        void write_dstE(const char s){W_dstE=s;}
        void write_dstM(const char s){W_dstM=s;}
        void write_valE(REGISTER s){W_valE=s;}
        void write_valM(REGISTER s){W_valM=s;}

    private:
        char W_stat=1;
        char W_icode;
        REGISTER W_valE,W_valM;
        char W_dstE,W_dstM;
};