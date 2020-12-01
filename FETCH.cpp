#include"FETCH.h"
using namespace std;
void FETCH::fetch(){
    SelectPC();//将pc置为正确的pc，并且对预测错误、ret等情况进行插入气泡的处理
    write();//先进行一次write，把前一次的结果传给D流水线寄存器
    icode=0xF&(imemory[pc._get_val()]>>4);
    Initfunc();
    if(icode>0xB){
        stat=4;
        return;
    }
    ifun=0xF&imemory[pc._get_val()];
    if(ifun>6||!(func[icode][ifun])){
        stat=4;
        return;
    }
    (this->*func[icode][ifun])();
    printf("i'am here!%d\n",valP._get_val());
    F_reg.write_val(valP);
}

void FETCH::Initfunc(){
    func[0][0]=&halt;
    func[1][0]=&nop;
    func[2][0]=&rrmovq;
    func[2][1]=&cmovle;
    func[2][2]=&cmovl;
    func[2][3]=&cmove;
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

void FETCH::bubble(){
    stat=0;
    icode=1;
    ifun=0;
    rA=15;
    rB=15;
}

void FETCH::SelectPC(){
    if(M_reg.get_icode()==7&&!e_Cnd){
        pc=M_reg.get_valA();
        bubble();
        F_reg.disable();
    }//遇到ret，插入bubble，且将F__reg置为不可修改
    else if(!(E_reg.get_icode()==5||E_reg.get_icode()==0xB&&(E_reg.get_dstM()==d_srcA||E_reg.get_dstM()==d_srcB))\
    &&(D_reg.get_icode()==9||E_reg.get_icode()==9||M_reg.get_icode()==9)){
        bubble();
        F_reg.disable();
    }//遇到
    else{
        pc=F_reg.get_val();
        F_reg.enable();
    }
    if(W_reg.get_icode()==9)
        pc=W_reg.get_valM();
}//从M_valA、W_valM、predPC中选取合适的更新pc

void FETCH::write(){
    D_reg.write_stat(stat);
    D_reg.write_icode(icode);
    D_reg.write_ifun(ifun);
    D_reg.write_rA(rA);
    D_reg.write_rB(rB);
    D_reg.write_valC(valC);
    D_reg.write_valP(valP);
}//对D流水线寄存器写值

void FETCH::halt(){
    stat=2;
}

void FETCH::nop(){
    bubble();
    valP.write_val(pc._get_val()+1);
}

void FETCH::rrmovq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmovle(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmovl(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmove(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmovne(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmovge(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::cmovg(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::irmovq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valC.write_val(imemory+pc._get_val()+2);
    valP.write_val(pc._get_val()+10);
}

void FETCH::rmmovq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valC.write_val(imemory+pc._get_val()+2);
    valP.write_val(pc._get_val()+10);
}

void FETCH::mrmovq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valC.write_val(imemory+pc._get_val()+2);
    valP.write_val(pc._get_val()+10);
}

void FETCH::OPq_addq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::OPq_subq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::OPq_andq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::OPq_xorq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::jmp(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::jle(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::jl(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::je(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::jne(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::jge(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::jg(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
    F_reg.write_val(valC);
}

void FETCH::call(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::ret(){
    valP.write_val(pc._get_val()+1);
}

void FETCH::pushq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}

void FETCH::popq(){
    rA=0xF&(imemory[pc._get_val()+1]>>4);
    rB=0xF&imemory[pc._get_val()+1];
    valP.write_val(pc._get_val()+2);
}
