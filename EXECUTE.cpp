#include"EXECUTE.h"
using namespace std;
void EXECUTE::execute()
{
    read();
    if(stat!=1) return;
    // printf("you called execute!now icode=%d,ifun=%d\n",icode,ifun);
    (this->*func[icode][ifun])();//执行完毕后的结果放在valB中
    setcc=(E_reg.get_icode()==6)&&(m_stat==1)&&(W_reg.get_stat()==1);
    if(setcc){
        // printf("you have setcc!\n");
        ZF=zf;
        SF=sf;
        OF=of;
    }
    e_valE=valB;
    e_Cnd=cond;
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
    func[5][0]=&mrmovq;
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
    stat=1;
    icode=1;
    ifun=0;
    dstE=dstM=0xF;
}

void EXECUTE::write(){
    if(W_reg.get_stat()!=1){
        return;
    }//W_stall
    M_reg.write_stat(stat);
    M_reg.write_icode(icode);
    M_reg.write_cnd(cond);
    M_reg.write_dstE(dstE);
    M_reg.write_dstM(dstM);
    M_reg.write_valE(valB);
    M_reg.write_valA(valA);
}

void EXECUTE::read(){
    stat=E_reg.get_stat();
    icode=E_reg.get_icode();
    ifun=E_reg.get_ifun();
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
    bubble();
}

void EXECUTE::rrmovq()
{
    valB=valA;
    e_dstE=dstE;
}

void EXECUTE::cmovle()
{
    valB=valA;
    cond=(SF^OF)|ZF;
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::cmovl()
{
    valB=valA;
    cond=SF|OF;
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::cmove()
{
    valB=valA;
    cond=ZF;
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::cmovne()
{
    valB=valA;
    cond=!ZF;
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::cmovge()
{
    valB=valA;
    cond=!(SF^OF);
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::cmovg()
{
    valB=valA;
    cond=(!(SF^OF))&(!ZF);
    e_dstE=cond?dstE:0xF;
}

void EXECUTE::irmovq()
{
    valB=valC;
    e_dstE=dstE;
}

void EXECUTE::rmmovq()
{
    valB.write_val(valB._get_val()+valC._get_val());
    e_dstE=dstE;
}

void EXECUTE::mrmovq()
{
    valB.write_val(valB._get_val()+valC._get_val());
    e_dstE=dstE;
}

void EXECUTE::OPq_addq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2+temp1;
    valB.write_val(out);
    zf=!out;
    of=(temp1^temp2)>=0&&(temp1^out)<0;//相加数同号，与结果异号
    sf=out<0;
    printf("you called %lld add %lld!zf=%d of=%d sf=%d\n",temp2,temp1,zf,of,sf);
    e_dstE=dstE;
}

void EXECUTE::OPq_subq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2-temp1;
    valB.write_val(out);
    zf=!out;
    of=(temp2^temp1)<0&&(temp2^out)<0;//负-正=正||正-负=负
    sf=out<0;
    printf("you called %lld sub %lld!zf=%d of=%d sf=%d\n",temp2,temp1,zf,of,sf);
    e_dstE=dstE;
}

void EXECUTE::OPq_andq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2&temp1;
    valB.write_val(out);
    zf=!out;
    of=0;
    sf=out<0;
    printf("you called %lld and %lld!zf=%d of=%d sf=%d\n",temp2,temp1,zf,of,sf);
    e_dstE=dstE;
}

void EXECUTE::OPq_xorq()
{
    long long temp1=valA._get_val(),temp2=valB._get_val();
    long long out=temp2^temp1;
    valB.write_val(out);
    zf=!out;
    of=0;
    sf=out<0;
    printf("you called %lld xor %lld!zf=%d of=%d sf=%d\n",temp2,temp1,zf,of,sf);
    e_dstE=dstE;
}

void EXECUTE::jmp()//总是预测选择了条件分支
{
    cond=1;
    e_dstE=dstE;
}

void EXECUTE::jle()
{
    cond=(SF^OF)|ZF;
    printf("you called cond!SF=%d OF=%d ZF=%d,cond=%d\n",SF,OF,ZF,cond);
    e_dstE=dstE;
}

void EXECUTE::jl()
{
    cond=SF|OF;
    e_dstE=dstE;
}

void EXECUTE::je()
{
    cond=ZF;
    e_dstE=dstE;
}

void EXECUTE::jne()
{
    cond=!ZF;
    e_dstE=dstE;
}

void EXECUTE::jge()
{
    cond=!(SF^OF);
    e_dstE=dstE;
}

void EXECUTE::jg()
{
    cond=(!(SF^OF))&(!ZF);
    e_dstE=dstE;
}

void EXECUTE::call()
{
    valB.write_val(valB._get_val()-8);
    e_dstE=dstE;
}

void EXECUTE::ret()
{
    valB.write_val(valB._get_val()+8);
    e_dstE=dstE;
}

void EXECUTE::pushq()
{
    valB.write_val(valB._get_val()-8);
    e_dstE=dstE;
}

void EXECUTE::popq()
{
    valB.write_val(valB._get_val()+8);
    e_dstE=dstE;
}