#include"MEMORY.h"
using namespace std;
void MEMORY::memory()
{
    read();
    if(icode==1)
    {
        bubble();
    }
    else
    {
        getAddr();
        renewstat();
        read_memory();
        write_memory();
        m_valM=valM;
        m_stat=stat;
    }
}

void MEMORY::getAddr()
{
    if(icode==4||icode==5||icode==8||icode==0xA)
    {
        Addr=valE;
    }
    else if(icode==9||icode==0xB)
    {
        Addr=valA;
    }
}

void MEMORY::read(){
    valE=M_reg.get_valE();
    valA=M_reg.get_valA();
    stat=M_reg.get_stat();
    icode=M_reg.get_icode();
    Cnd=M_reg.get_cnd();
    dstE=M_reg.get_dstE();
    dstM=M_reg.get_dstM();
    ifun=M_reg.get_ifun();
}

void MEMORY::renewstat()
{
    bool sig1=(icode==4||icode==5||icode==8||icode==0xA||icode==9||icode==0xB);
    bool sig2=(Addr._get_val()<0||Addr._get_val()>=800000);
    bool sig3=(icode==4)&&(enable[Addr._get_val()]==0);
    bool dem_error=sig1&&sig2||sig3;
    if(dem_error)
    {
        stat=3;
    }
}

void MEMORY::bubble()
{
    icode=1;
    REGISTER none;
    valE=none;
    valA=none;
    valM=none;
    Addr=none;
    dstE=0xF;
    dstM=0xF;
}

void MEMORY::write()
{
    W_reg.write_icode(icode);
    W_reg.write_stat(stat);
    W_reg.write_valE(valE);
    W_reg.write_valM(valM);
    W_reg.write_dstE(dstE);
    W_reg.write_dstM(dstM);
    W_reg.write_ifun(ifun);
}


void MEMORY::read_memory()
{
    if(stat==1)
    {
        if(icode==5||icode==9||icode==0xB)
        {
            valM.write_val(imemory+Addr._get_val());
        }
        else
        {
            valM.write_val(0LL);
        }
    }
}

void MEMORY::write_memory()
{
    if(stat==1)
    {
        if(icode==4||icode==8||icode==0xA)
        {
            char* temp=valA.get_val();
            long long address=Addr._get_val();
            for(int i=0;i<8;i++)
            {
                imemory[i+address]=temp[i];
            }
        }
    }
}