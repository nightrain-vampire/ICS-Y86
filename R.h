#pragma once
#include<stdio.h>
using namespace std;
union Val{
    char ch[8];
    long long ll;
};

class REGISTER{
    public:
        REGISTER(){val.ll=0;}//默认构造函数
        char* get_val();//读取数据的接口为.get_val()
        long long _get_val();//按照long long来解释val()
        bool write_val(const char* nval);//用char数组写数据的接口为.write_val()
        bool write_val(long long nval);
        REGISTER& operator=(REGISTER r);//用REGISTER类可以直接赋值;
    private:
        Val val;
};//封装一个64位寄存器类，既可以作为寄存器的基本单元，也可以作为存储临时64位变量的单元

class REGISTERS{
    public:
        REGISTER get_val(int src);
        bool write_val(int dst,const char* valW);
        bool write_val(int dst,REGISTER& r);
    private:
        REGISTER reg[15];//代表15个64位寄存器
};

