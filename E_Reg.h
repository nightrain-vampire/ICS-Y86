#include"common.h"

class E_REGISTER
{
    public:
        E_REGISTER(){}

    private:
        //data member
        char E_stat;
        char E_icode;
        char E_ifun;
        REGISTER E_valC,E_valA,E_valB;
        char E_dstE,E_dstM;
        char E_srcA,E_srcB;
};