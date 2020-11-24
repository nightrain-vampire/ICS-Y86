#include"WBACK.h"
using namespace std;
void WBACK::wback()
{
    icode=0xF&(imemory[pc._get_val()]>>4);
    ifun=0xF&imemory[pc._get_val()];
    (this->*func[icode][ifun])();
}

void WBACK::Initfunc()
{
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

void WBACK::halt()
{

}

void WBACK::nop()
{

}

void WBACK::rrmovq()
{

}

void WBACK::cmovle()
{

}

void WBACK::cmovl()
{

}

void WBACK::cmove()
{

}

void WBACK::cmovne()
{

}

void WBACK::cmovge()
{

}

void WBACK::cmovg()
{

}

void WBACK::mrmove()
{

}

void WBACK::irmovq()
{

}

void WBACK::rmmovq()
{

}

void WBACK::mrmovq()
{

}

void WBACK::OPq_addq()
{

}

void WBACK::OPq_subq()
{

}

void WBACK::OPq_andq()
{

}

void WBACK::OPq_xorq()
{

}

void WBACK::jmp()
{

}

void WBACK::jle()
{

}

void WBACK::jl()
{

}

void WBACK::je()
{

}

void WBACK::jne()
{

}

void WBACK::jge()
{

}

void WBACK::jg()
{

}

void WBACK::call()
{

}

void WBACK::ret()
{

}

void WBACK::pushq()
{

}

void WBACK::popq()
{

}