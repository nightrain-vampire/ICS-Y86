#include"FETCH.h"
using namespace std;
void FETCH::fetch(){
    SelectPC();
    icode=0xF&(imemory[pc._get_val()]>>4);
    if(icode>0xB){
        stat=4;
        return;
    }
    ifun=0xF&imemory[pc._get_val()];
    if(ifun>0xB){
        stat=4;
        return;
    }
    stat=1;
    // printf("you called fetch!now pc is %x,icode:%d,ifun=%d\n",pc._get_val(),icode,ifun);
    (this->*func[icode][ifun])();
    if(icode==7||icode==8){
        predPC=valC;
    }
    else
        predPC=valP;
}

void FETCH::Initfunc(){
    for(int i=0;i<12;i++){
        for(int j=0;j<7;j++){
            func[i][j]=&invalid;
        }
    }
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
    stat=1;
    icode=1;
    ifun=0;
    rA=15;
    rB=15;
}

void FETCH::SelectPC(){
    if(M_reg.get_icode()==7&&!M_reg.get_cnd()){
        pc=M_reg.get_valA();
        printf("you called jxx return!nextpc:%d\n",pc._get_val());
    }
    else if(W_reg.get_icode()==9){
        pc=W_reg.get_valM();
    }
    else{
        pc=F_reg.get_val();
    }
}

void FETCH::write(){
    if(E_reg.get_icode()==5||E_reg.get_icode()==0xB&&(E_reg.get_dstM()==d_srcA||E_reg.get_dstM()==d_srcB)){
        return;
    }//D_stall
    D_reg.write_stat(stat);
    D_reg.write_icode(icode);
    D_reg.write_ifun(ifun);
    D_reg.write_rA(rA);
    D_reg.write_rB(rB);
    D_reg.write_valC(valC);
    D_reg.write_valP(valP);
}//对D流水线寄存器写值

void FETCH::invalid(){
    bubble();
    stat=4;
}

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
}

void FETCH::jle(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::jl(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::je(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::jne(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::jge(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
}

void FETCH::jg(){
    valC.write_val(imemory+pc._get_val()+1);
    valP.write_val(pc._get_val()+9);
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
