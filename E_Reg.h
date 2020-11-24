#pragma once
#include"R.h"

class E_REGISTER
{
    public:
        E_REGISTER(){}

        //读取函数
        char get_stat(){return E_stat;}
        char get_icode(){return E_icode;}
        char get_ifun(){return E_ifun;}
        char get_dstE(){return E_dstE;}
        char get_dstM(){return E_dstM;}
        char get_srcA(){return E_srcA;}
        char get_srcB(){return E_srcB;}
        REGISTER get_valC(){return E_valC;}
        REGISTER get_valA(){return E_valA;}
        REGISTER get_valB(){return E_valB;}

        //写入函数
        void write_stat(const char s){E_stat=s;}
        void write_icode(const char s){E_icode=s;}
        void write_ifun(const char s){E_ifun=s;}
        void write_dstE(const char s){E_dstE=s;}
        void write_dstM(const char s){E_dstM=s;}
        void write_srcA(const char s){E_srcA=s;}
        void write_srcB(const char s){E_srcB=s;}
        void write_valC(const REGISTER& s){E_valC=s;}
        void write_valA(const REGISTER& s){E_valA=s;}
        void write_valB(const REGISTER& s){E_valB=s;}

    private:
        //data member
        char E_stat;
        char E_icode;
        char E_ifun;
        REGISTER E_valC,E_valA,E_valB;
        char E_dstE,E_dstM;
        char E_srcA,E_srcB;
};