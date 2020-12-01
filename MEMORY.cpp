#include"MEMORY.h"
using namespace std;
void MEMORY::memory()
{
    //将上个周期的数据写入全局变量和W流水线寄存器
    write();
    getGlobal();
    //如果接收到传气泡信号
    //等效为nop，传递气泡
    if(ifbubble())
    {
        bubble();
    }
    //否则正常计算
    else
    {
        getAddr();
        renewstat();
        read_memory();
        write_memory();
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

void MEMORY::renewstat()
{
    bool sig1=(icode==4||icode==5||icode==8||icode==0xA||icode==9||icode==0xB);
    bool sig2=(Addr._get_val()<0||Addr._get_val()>=800000);
    bool dem_error=sig1&&sig2;
    if(dem_error)
    {
        stat=3;
    }
    else
    {
        stat=M_reg.get_stat();
    }
}

bool MEMORY::ifbubble()
{
    bool sig1=stat!=1;
    bool sig2=W_reg.get_stat()!=1;
    return sig1||sig2;
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
}

void MEMORY::getGlobal()
{
     //拉出全局变量
    //如果报错请添加对应的全局变量
    m_valM=valM;
    //M_dstE=dstE;
    //M_dstM=dstM;
    //M_valA=valA;
    //M_valE=valE;
    //M_icode=icode;
    //M_Cnd=Cnd;
}

void MEMORY::read_memory()
{
    if(stat==1)
    {
        if(icode==5||icode==9||icode==0xB)
        {
            valM.write_val(dmemory[Addr._get_val()]);
        }
        else
        {
            REGISTER none;
            valM.write_val(none.get_val());
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
            for(long long i=address;i<address+8;i++)
            {
                dmemory[i]=temp[i-address];
            }
        }
    }
}