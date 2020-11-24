#include"common.h"

class W_REGISTER
{
    public:
        W_REGISTER(){}

        //读取函数
        char get_stat(){return W_stat;}
        char get_icode(){return W_icode;}
        char get_dstE(){return W_dstE;}
        char get_dstM(){return W_dstM;}
        char* get_valE(){return W_valE.get_val();}
        char* get_valM(){return W_valM.get_val();}

        //写入函数
        void write_stat(const char s){W_stat=s;}
        void write_icode(const char s){W_icode=s;}
        void write_dstE(const char s){W_dstE=s;}
        void write_dstM(const char s){W_dstM=s;}
        void write_valE(const char* s){W_valE.write_val(s);}
        void write_valM(const char* s){W_valM.write_val(s);}

    private:
        char W_stat;
        char W_icode;
        REGISTER W_valE,W_valM;
        char W_dstE,W_dstM;
};