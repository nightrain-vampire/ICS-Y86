#include"R.h"
/*
    *实现部分
*/

//对寄存器函数的实现
//REGISTER当做64位的单元
//既可以作为寄存器
//也可以作为临时的64位的变量或者立即数
char* REGISTER::get_val()
{
    return val.ch;
}

bool REGISTER::write_val(const char* nval)
{
    for(int i=0;i!=8;i++)
    {
        val.ch[i]=nval[i];
    }
    return true;
}

//实现寄存器文件类
char* REGISTERS::get_val(int src)
{
    return reg[src].get_val();
}

bool REGISTERS::write_val(int dst,const char* valM)
{
    for(int i=0;i!=8;i++)
    {
        reg[dst].write_val(valM);
    }
    return true;
}