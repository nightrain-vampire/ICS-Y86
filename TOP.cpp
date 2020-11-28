#include"TOP.h"
using namespace std;
REGISTERS registers;
char imemory[800000];
char dmemory[800000];
char ZF,OF,CF,e_dstE,m_stat;
F_REGISTER F_reg;
D_REGISTER D_reg;
E_REGISTER E_reg;
M_REGISTER M_reg;
W_REGISTER W_reg;
REGISTER e_valE,m_valM;
//生成其他的全局变量