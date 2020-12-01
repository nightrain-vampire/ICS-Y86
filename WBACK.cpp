#include"WBACK.h"
using namespace std;
void WBACK::wback()
{
    read();
    if (ifstall())
    {
        stat=2;
    }
    else if(icode==1){
        return;
    }
    else {
        write();
    }
}

void WBACK::read(){
    stat=W_reg.get_stat();
    icode=W_reg.get_icode();
    dstE=W_reg.get_dstE();
    dstM=W_reg.get_dstM();
    valE=W_reg.get_valE();
    valM=W_reg.get_valM();
}

void WBACK::write()
{
    if(dstE!=0xF)
    {
        registers.write_val(dstE,valE);
    }
    if(dstM!=0xF)
    {
        registers.write_val(dstM,valM);
    }
}

bool WBACK::ifstall()
{
    return stat!=1;
}