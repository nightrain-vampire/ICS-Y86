#include"MEMORY.h"
using namespace std;
void MEMORY::fetch()
{
    icode=0xF&(imemory[pc._get_val()]>>4);
    ifun=0xF&imemory[pc._get_val()];
    (this->*func[icode][ifun])();
}

void MEMORY::Initfunc()
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

void MEMORY::halt()
{

}

void MEMORY::nop()
{

}

void MEMORY::rrmovq()
{

}

void MEMORY::cmovle()
{

}

void MEMORY::cmovl()
{

}

void MEMORY::cmove()
{

}

void MEMORY::cmovne()
{

}

void MEMORY::cmovge()
{

}

void MEMORY::cmovg()
{

}

void MEMORY::mrmove()
{

}

void MEMORY::irmovq()
{

}

void MEMORY::rmmovq()
{

}

void MEMORY::mrmovq()
{

}

void MEMORY::OPq_addq()
{

}

void MEMORY::OPq_subq()
{

}

void MEMORY::OPq_andq()
{

}

void MEMORY::OPq_xorq()
{

}

void MEMORY::jmp()
{

}

void MEMORY::jle()
{

}

void MEMORY::jl()
{

}

void MEMORY::je()
{

}

void MEMORY::jne()
{

}

void MEMORY::jge()
{

}

void MEMORY::jg()
{

}

void MEMORY::call()
{

}

void MEMORY::ret()
{

}

void MEMORY::pushq()
{

}

void MEMORY::popq()
{

}