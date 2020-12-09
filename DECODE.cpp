#include"DECODE.h"
using namespace std;
void DECODE::decode()
{
    read();
    if(stat!=1){
        return;
    }
    if(icode==1){
        bubble();
    }
    else{
        cal_dstE();
        cal_dstM();
        cal_srcA();
        cal_srcB();
        valA=SelFwdA(srcA);
        valB=FwdB(srcB);
        d_srcA=srcA;
        d_srcB=srcB;
    }
}

//void DECODE::invalid()
//{
    //bubble();
    //stat=4;
//}

//指令非法，返回true
//bool DECODE::islegal()
//{
    //if(icode==2||icode==4||icode==5||icode==6)
    //{
        //if(rA<0||rA>0xE||rB<0||rB>0xE||rA==rB){
            //return true;
        //}
    //}
    //else if (icode==3)
    //{
        //if(rA!=0xF||rB<0||rB>0xE||rA==rB){
            //return true;
        //}
    //}
    //else if (icode==0xA||icode==0xB)
    //{
        //if(rA<0||rA>0xE||rB!=0xF||rA==rB){
            //return true;
        //}
    //}
    //return false;
//}

void DECODE::cal_dstE()
{
    //获取dstE
    if(icode==6||icode==2||icode==3)
    {
        dstE=rB;
    }
    else if(icode==0xA||icode==0xB||icode==8||icode==9)
    {
        dstE=4;
    }
    else
    {
        dstE=0xF;
    }
}

void DECODE::cal_dstM()
{
    //获取dstM
    if(icode==5||icode==0xB)
    {
        dstM=rA;
    }
    else
    {
        dstM=0xF;
    }
}

void DECODE::cal_srcA()
{
    //获取srcA
    if(icode==2||icode==4||icode==6||icode==0xA)
    {
        srcA=rA;
    }
    else if (icode==9||icode==0xB)
    {
        srcA=4;
    }
    else
    {
        srcA=0xF;
    }
}

void DECODE::cal_srcB()
{
    //获取srcB
    if(icode==4||icode==5||icode==6)
    {
        srcB=rB;
    }
    else if (icode==8||icode==9||icode==0xA||icode==0xB)
    {
        srcB=4;
    }
    else
    {
        srcB=0xF;
    }
}

void DECODE::write()
{
    if(ifbubble())
    {
        bubble();
    }//如果要插气泡就在写之前改值
    E_reg.write_stat(stat);
    E_reg.write_icode(icode);
    E_reg.write_ifun(ifun);
    E_reg.write_valC(valC);
    E_reg.write_dstE(dstE);
    E_reg.write_dstM(dstM);
    E_reg.write_srcA(srcA);
    E_reg.write_srcB(srcB);
    E_reg.write_valA(valA);
    E_reg.write_valB(valB);
}

void DECODE::read()
{
    stat=D_reg.get_stat();
    icode=D_reg.get_icode();
    ifun=D_reg.get_ifun();
    rA=D_reg.get_rA();
    rB=D_reg.get_rB();
    valC=D_reg.get_valC();
    valP=D_reg.get_valP();
}

void DECODE::bubble()
{
    icode=1;
    ifun=0;
    dstE=dstM=srcA=srcB=0xF;
    REGISTER none;
    valC=none,valP=none;
}

REGISTER DECODE::SelFwdA(char d_rval)
{
    if(icode==8||icode==7)
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
        if(d_rval!=0xF)
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
    if(d_rval==e_dstE&&d_rval!=0xf)
    {
        return e_valE;
    }
    else if (d_rval==M_reg.get_dstM()&&d_rval!=0xf)
    {
        return m_valM;
    }
    else if (d_rval==M_reg.get_dstE()&&d_rval!=0xf)
    {
        return M_reg.get_valE();
    }
    else if (d_rval==W_reg.get_dstM()&&d_rval!=0xf)
    {
        return W_reg.get_valM();
    }
    else if (d_rval==W_reg.get_dstE()&&d_rval!=0xf)
    {
        return W_reg.get_valE();
    }
    else
    {
        if(d_rval!=0xF)
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
    bool sig1=E_reg.get_icode()==7&&!e_Cnd;
    bool sig2=E_reg.get_icode()==5||E_reg.get_icode()==0xB;
    bool sig3=E_reg.get_dstM()==d_srcA||E_reg.get_dstM()==d_srcB;
    return sig1||(sig2&&sig3);
}

// bool DECODE::ifstall()
// {
//     bool sig1=(E_reg.get_icode()==5||E_reg.get_icode()==0xB);
//     bool sig2=(srcA==E_reg.get_dstM()||srcB==E_reg.get_dstM());
//     return sig1&&sig2;
// }