#include"common.h"
using namespace std;
class EXECUTE
{
    public:
        EXECUTE(){Initfunc();};
        void execute();//直接调用它就行
        void Initfunc();//初始化函数指针数组
        void bubble();
        void write();
        void read();
        void halt();
        void nop();
        void rrmovq();
        void cmovle();
        void cmovl();
        void cmove();
        void cmovne();
        void cmovge();
        void cmovg();
        void irmovq();
        void rmmovq();
        void mrmovq();
        void OPq_addq();
        void OPq_subq();
        void OPq_andq();
        void OPq_xorq();
        void jmp();
        void jle();
        void jl();
        void je();
        void jne();
        void jge();
        void jg();
        void call();
        void ret();
        void pushq();
        void popq();
    private:
        REGISTER valA,valB,valC;
        char cond,stat,icode,ifun,dstE,dstM;
        char zf,of,sf,setcc;
        void (EXECUTE::*func[12][7])();
};