#include"R.h"
char* REGISTER::get_val(){
    return val.ch;
}

bool REGISTER::write_val(const char* nval){
    for(int i=0;i!=8;i++)
        val.ch[i]=nval[i];
    return true;
}

long long REGISTER::_get_val(){
    return val.ll;
}

REGISTER& REGISTER::operator=(REGISTER& r){
    write_val(r.get_val());
    return *this;
}
//实现寄存器文件类
REGISTER REGISTERS::get_val(int src){
    return reg[src];
}

bool REGISTERS::write_val(int dst,const char* valM){
    reg[dst].write_val(valM);
    return true;
}

bool REGISTERS::write_val(int dst,REGISTER& r){
    reg[dst]=r;
    return true;
}


