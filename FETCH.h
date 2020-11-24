#include"common.h"
using namespace std;
class FETCH{
    public:
        FETCH(){Initfunc();};
        void fetch();//直接调用它就行
        void Initfunc();//初始化函数指针数组
        void SelectPC();//从M_valA、W_valM、predPC中选取合适的更新pc
        void halt();
        void nop();
        void rrmovq();
        void cmovle();
        void cmovl();
        void cmove();
        void cmovne();
        void cmovge();
        void cmovg();
        void mrmove();
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
        REGISTER pc,valC,valP;
        char stat,icode,ifun,rA,rB;
        void (FETCH::*func[12][7])();
};