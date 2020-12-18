#include"WBACK.h"
using namespace std;
void WBACK::wback()
{
    read();
    if (stat!=1)
    {
        return;
    }
    else if(icode==1){
        bubble();
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
    ifun=W_reg.get_ifun();
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

void WBACK::bubble()
{
    stat=1;
    icode=1;
    ifun=0;
    REGISTER none;
    valE=none;
    valM=none;
    dstE=0xF;
    dstM=0xF;
}