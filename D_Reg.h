#include"common.h"

class D_REGISTER
{
    public:
        D_REGISTER(){}

        //读取函数
        char get_stat(){return D_stat;}
        char get_icode(){return D_icode;}
        char get_ifun(){return D_ifun;}
        char get_rA(){return D_rA;}
        char get_rB(){return D_rB;}
        char* get_valC(){return D_valC.get_val();}
        char* get_valP(){return D_valP.get_val();}

        //写入函数
        void write_stat(const char s){D_stat=s;}
        void write_icode(const char s){D_icode=s;}
        void write_ifun(const char s){D_ifun=s;}
        void write_rA(const char s){D_rA=s;}
        void write_rB(const char s){D_rB=s;}
        void write_valC(const char* s){D_valC.write_val(s);}
        void write_valP(const char* s){D_valP.write_val(s);}

    private:
        //数据成员
        char D_stat;
        char D_icode;
        char D_ifun;
        char D_rA,D_rB;
        REGISTER D_valC,D_valP;
};