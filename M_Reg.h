#pragma once
#include"R.h"

class M_REGISTER
{
    public:
        M_REGISTER(){}

        //读取函数
        char get_stat(){return M_stat;}
        char get_icode(){return M_icode;}
        char get_cnd(){return M_cnd;}
        char get_dstE(){return M_dstE;}
        char get_dstM(){return M_dstM;}
        REGISTER get_valE(){return M_valE;}
        REGISTER get_valA(){return M_valA;}

        //写入函数
        void write_stat(const char s){M_stat=s;}
        void write_icode(const char s){M_icode=s;}
        void write_cnd(const char s){M_cnd=s;}
        void write_dstE(const char s){M_dstE=s;}
        void write_dstM(const char s){M_dstM=s;}
        void write_valE(const REGISTER& s){M_valE=s;}
        void write_valA(const REGISTER& s){M_valA=s;}

    private:
        char M_stat;
        char M_icode;
        char M_cnd;
        REGISTER M_valE,M_valA;
        char M_dstE,M_dstM;
};