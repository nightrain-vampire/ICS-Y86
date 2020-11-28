#include"DECODE.h"
using namespace std;
void DECODE::decode()
{
    if(ifbubble())
    {
        bubble();
    }
    else if (ifstall())
    {
        stat='2';
    }
    else
    {
        write();
        cal_dstE();
        cal_dstM();
        cal_srcA();
        cal_srcB();
        valA=SelFwdA(srcA);
        valB=FwdB(srcB);
    }
    
}

void DECODE::cal_dstE()
{
    //获取dstE
    if(icode=='6'||icode=='2'||icode=='3')
    {
        dstE=rB;
    }
    else if(icode=='A'||icode=='B'||icode=='8'||icode=='9')
    {
        dstE='4';
    }
    else
    {
        dstE='F';
    }
}

void DECODE::cal_dstM()
{
    //获取dstM
    if(icode=='5'||icode=='B')
    {
        dstM=rA;
    }
    else
    {
        dstM='F';
    }
}

void DECODE::cal_srcA()
{
    //获取srcA
    if(icode=='2'||icode=='4'||icode=='6'||icode=='A')
    {
        srcA=rA;
    }
    else if (icode=='9'||icode=='B')
    {
        srcA='4';
    }
    else
    {
        srcA='F';
    }
}

void DECODE::cal_srcB()
{
    //获取srcB
    if(icode=='4'||icode=='5'||icode=='6')
    {
        srcB=rB;
    }
    else if (icode=='8'||icode=='9'||icode=='A'||icode=='B')
    {
        srcB='4';
    }
    else
    {
        srcB='F';
    }
}

void DECODE::write()
{
    E_reg.write_stat(D_reg.get_stat());
    E_reg.write_icode(D_reg.get_icode());
    E_reg.write_ifun(D_reg.get_ifun());
    E_reg.write_valC(D_reg.get_valC());
    E_reg.write_dstE(dstE);
    E_reg.write_dstM(dstM);
    E_reg.write_srcA(srcA);
    E_reg.write_srcB(srcB);
    E_reg.write_valA(valA);
    E_reg.write_valB(valB);
}

void DECODE::bubble()
{
    icode='1';
}

REGISTER DECODE::SelFwdA(char d_rval)
{
    if(icode=='8'||icode=='7')
    {
        return valP;
    }
    else if(d_rval==e_dstE)
    {
        return e_valE;
    }
    else if (d_rval==M_reg.get_dstM())
    {
        return m_valM;
    }
    else if (d_rval==M_reg.get_dstE())
    {
        return M_reg.get_valE();
    }
    else if (d_rval==W_reg.get_dstM())
    {
        return W_reg.get_valM();
    }
    else if (d_rval==W_reg.get_dstE())
    {
        return W_reg.get_valE();
    }
    else
    {
        if(d_rval!='F')
        {
            return registers.get_val(d_rval);
        }
        else
        {
            REGISTER temp;
            return temp;
        }
    }
    
}

REGISTER DECODE::FwdB(char d_rval)
{
    if(d_rval==e_dstE)
    {
        return e_valE;
    }
    else if (d_rval==M_reg.get_dstM())
    {
        return m_valM;
    }
    else if (d_rval==M_reg.get_dstE())
    {
        return M_reg.get_valE();
    }
    else if (d_rval==W_reg.get_dstM())
    {
        return W_reg.get_valM();
    }
    else if (d_rval==W_reg.get_dstE())
    {
        return W_reg.get_valE();
    }
    else
    {
        if(d_rval!='F')
        {
            return registers.get_val(d_rval);
        }
        else
        {
            REGISTER temp;
            return temp;
        }
    }
}

bool DECODE::ifbubble()
{
    bool sig1=(E_reg.get_icode()=='7'&&(!e_Cnd));
    bool sig2=!(E_reg.get_icode()=='5'||E_reg.get_icode()=='B');
    bool sig3=(srcA==E_reg.get_dstM()||srcB==E_reg.get_dstM());
    bool sig4=(D_reg.get_icode()=='9'||E_reg.get_icode()=='9'||M_reg.get_icode()=='9');
    return sig1||sig2&&sig3&&sig4;
}

bool DECODE::ifstall()
{
    bool sig1=(E_reg.get_icode()=='5'||E_reg.get_icode()=='B');
    bool sig2=(srcA==E_reg.get_dstM()||srcB==E_reg.get_dstM());
    return sig1&&sig2;
}