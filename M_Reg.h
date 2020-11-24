#include"common.h"

class M_REGISTER
{
    public:
        M_REGISTER(){}

    private:
        char M_stat;
        char M_icode;
        char M_cnd;
        REGISTER M_valE,M_valA;
        char M_dstE,M_dstM;
};