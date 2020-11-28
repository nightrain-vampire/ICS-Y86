#include"EXECUTE.h"
using namespace std;
void EXECUTE::execute()
{
    if(m_stat==3||W_reg.get_stat()==3){
        bubble();
        setcc=0;
    }
    else{
        setcc=1;
    }//不知道这样的顺序对不对
    write();
    read();
    (this->*func[icode][ifun])();//执行完毕后的结果放在valB中
    e_dstE=cond?dstE:0xF;
    e_valE=valB;
}

void EXECUTE::Initfunc()
{
    func[0][0]=&halt;
    func[1][0]=&nop;
    func[2][0]=&rrmovq;
    func[2][1]=&cmovle;
    func[2][2]=&cmovl;
    func[2][4]=&cmovne;
    func[2][5]=&cmovge;
    func[2][6]=&cmovg;
    func[3][0]=&irmovq;
    func[4][0]=&rmmovq;
    func[2][7]=&mrmovq;
    func[6][0]=&OPq_addq;
    func[6][1]=&OPq_subq;
    func[6][2]=&OPq_andq;
    func[6][3]=&OPq_xorq;
    func[7][0]=&jmp;
    func[7][1]=&jle;
    func[7][2]=&jl;
    func[7][3]=&je;
    func[7][4]=&jne;
    func[7][5]=&jge;
    func[7][6]=&jg;
    func[8][0]=&call;
    func[9][0]=&ret;
    func[0xA][0]=&pushq;
    func[0xB][0]=&popq;
}

void EXECUTE::bubble(){
    stat=0;
    icode=1;
    ifun=0;
    dstE=dstM=0xF;
}

void EXECUTE::write(){
    if(setcc){
        ZF=zf;
        OF=of;
        SF=sf;
    }
    M_reg.write_stat(stat);
    M_reg.write_icode(icode);
    M_reg.write_cnd(cond);
    M_reg.write_dstE(e_dstE);
    M_reg.write_dstM(dstM);
    M_reg.write_valE(valB);
    M_reg.write_valA(valA);
}

void EXECUTE::read(){
    dstE=E_reg.get_dstE();
    dstM=E_reg.get_dstM();
    valA=E_reg.get_valA();
    valB=E_reg.get_valB();
    valC=E_reg.get_valC();
}

void EXECUTE::halt()
{

}

void EXECUTE::nop()
{

}

void EXECUTE::rrmovq()
{
    valB=valA;
    cond=1;
}

void EXECUTE::cmovle()
{
    valB=valA;
    cond=(SF^OF)|ZF;
}

void EXECUTE::cmovl()
{
    valB=valA;
    cond=SF|OF;
}

void EXECUTE::cmove()
{
    valB=valA;
    cond=ZF;
}

void EXECUTE::cmovne()
{
    valB=valA;
    cond=!ZF;
}

void EXECUTE::cmovge()
{
    valB=valA;
    cond=!(SF^OF);
}

void EXECUTE::cmovg()
{
    valB=valA;
    cond=(!(SF^OF))&(!ZF);
}

void EXECUTE::irmovq()
{
    valB=valC;
}

void EXECUTE::rmmovq()
{
    valB.write_val(valB._get_val()+valC._get_val());
}

void EXECUTE::mrmovq()
{
    valB.write_val(valB._get_val()+valC._get_val());
}

void EXECUTE::OPq_addq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2+temp1;
    valB.write_val(out);
    zf=!out;
    of=(temp1^temp2)>=0&&(temp1^out)<0;//相加数同号，与结果异号
    sf=out<0;
}

void EXECUTE::OPq_subq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2-temp1;
    valB.write_val(out);
    zf=!out;
    of=(temp2^temp1)<0&&(temp2^out)<0;//负-正=正||正-负=负
    sf=out<0;
}

void EXECUTE::OPq_andq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2&temp1;
    valB.write_val(out);
    zf=!out;
    of=0;
    sf=out<0;
}

void EXECUTE::OPq_xorq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2^temp1;
    valB.write_val(out);
    zf=!out;
    of=0;
    sf=out<0;
}

void EXECUTE::jmp()//总是预测选择了条件分支
{
    cond=1;
}

void EXECUTE::jle()
{
    cond=(SF^OF)|ZF;
}

void EXECUTE::jl()
{
    cond=SF|OF;
}

void EXECUTE::je()
{
    cond=ZF;
}

void EXECUTE::jne()
{
    cond=!ZF;
}

void EXECUTE::jge()
{
    cond=!(SF^OF);
}

void EXECUTE::jg()
{
    cond=(!(SF^OF))&(!ZF);
}

void EXECUTE::call()
{
    valB.write_val(valB._get_val()-8);
}

void EXECUTE::ret()
{
    valB.write_val(valB._get_val()+8);
}

void EXECUTE::pushq()
{
    valB.write_val(valB._get_val()-8);
}

void EXECUTE::popq()
{
    valB.write_val(valB._get_val()+8);
}