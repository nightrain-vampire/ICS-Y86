#include"FETCH.h"
using namespace std;
void FETCH::fetch(){
    SelectPC();//pc已经是正确的pc了
    icode=0xF&(imemory[pc._get_val()]>>4);
    ifun=0xF&imemory[pc._get_val()];
    (this->*func[icode][ifun])();
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
    func[2][7]=&mrmove;
    func[3][0]=&irmovq;
    func[4][0]=&rmmovq;
    func[5][0]=&mrmove;
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

void FETCH::halt()
{

}

void FETCH::nop()
{

}

void FETCH::rrmovq()
{

}

void FETCH::cmovle()
{

}

void FETCH::cmovl()
{

}

void FETCH::cmove()
{

}

void FETCH::cmovne()
{

}

void FETCH::cmovge()
{

}

void FETCH::cmovg()
{

}

void FETCH::mrmove()
{

}

void FETCH::irmovq()
{

}

void FETCH::rmmovq()
{

}

void FETCH::mrmovq()
{

}

void FETCH::OPq_addq()
{

}

void FETCH::OPq_subq()
{

}

void FETCH::OPq_andq()
{

}

void FETCH::OPq_xorq()
{

}

void FETCH::jmp()
{

}

void FETCH::jle()
{

}

void FETCH::jl()
{

}

void FETCH::je()
{

}

void FETCH::jne()
{

}

void FETCH::jge()
{

}

void FETCH::jg()
{

}

void FETCH::call()
{

}

void FETCH::ret()
{

}

void FETCH::pushq()
{

}

void FETCH::popq()
{

}