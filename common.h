#pragma once
#include"TOP.h"
#include<stdio.h>
extern REGISTERS registers;
extern char imemory[800000];
extern char enable[800000];
extern F_REGISTER F_reg;
extern D_REGISTER D_reg;
extern E_REGISTER E_reg;
extern M_REGISTER M_reg;
extern W_REGISTER W_reg;
extern char ZF,OF,SF,e_dstE,m_stat,e_Cnd,d_srcA,d_srcB;
extern REGISTER e_valE,m_valM,predPC;
extern Val instr_length;