#include"common.h"

class W_REGISTER
{
    public:
        W_REGISTER(){}

    private:
        char W_stat;
        char W_icode;
        REGISTER W_valE,W_valM;
        char W_dstE,W_dstM;
};