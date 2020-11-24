#include"EXECUTE.h"
using namespace std;
void EXECUTE::execute()
{
    icode=0xF&(imemory[pc._get_val()]>>4);
    ifun=0xF&imemory[pc._get_val()];
    (this->*func[icode][ifun])();
}

void EXECUTE::Initfunc()
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

void EXECUTE::halt()
{

}

void EXECUTE::nop()
{

}

void EXECUTE::rrmovq()
{

}

void EXECUTE::cmovle()
{

}

void EXECUTE::cmovl()
{

}

void EXECUTE::cmove()
{

}

void EXECUTE::cmovne()
{

}

void EXECUTE::cmovge()
{

}

void EXECUTE::cmovg()
{

}

void EXECUTE::mrmove()
{

}

void EXECUTE::irmovq()
{

}

void EXECUTE::rmmovq()
{

}

void EXECUTE::mrmovq()
{

}

void EXECUTE::OPq_addq()
{

}

void EXECUTE::OPq_subq()
{

}

void EXECUTE::OPq_andq()
{

}

void EXECUTE::OPq_xorq()
{

}

void EXECUTE::jmp()
{

}

void EXECUTE::jle()
{

}

void EXECUTE::jl()
{

}

void EXECUTE::je()
{

}

void EXECUTE::jne()
{

}

void EXECUTE::jge()
{

}

void EXECUTE::jg()
{

}

void EXECUTE::call()
{

}

void EXECUTE::ret()
{

}

void EXECUTE::pushq()
{

}

void EXECUTE::popq()
{

}