#include<stdio.h>
using namespace std;
class REGISTER{
    public:
        REGISTER& operator+(const REGISTER& r);//注意也是深拷贝，返回一个新的REGISTER
        char* get_val();//读取数据的接口为.get_val()
        bool write_val(const char* nval);//写数据的接口为.write_val()
    private:
        char val[8]={0};
};//封装一个64位寄存器类，既可以作为寄存器的基本单元，也可以作为存储临时64位变量的单元

class REGISTERS{
    public:
        char* get_val(int src);
        bool write_val(int dst,const char* valW);
    private:
        REGISTER reg[15];//代表15个64位寄存器
};

class PC{
    public:
        PC(const char* c){create(c);};//构造函数，传进去一个参数
        char* get_val();
        PC operator+(int i);//pc+int，返回一个新的PC类，注意是深拷贝不是浅拷贝
        bool refersh();//用valP更新PC
    private:
        REGISTER pc;
        void create(const char*);
};

REGISTER valA,valB,valC,valE,valM;
REGISTERS registers;
PC pc,valP;
char icode,ifun,rA,rB;//warning:实际上icode、ifunc、rA、rB都是半个char，数据读取时要记得结合位运算
char imemory[8000000];
/*
    *实现部分
*/

//对寄存器函数的实现
//REGISTER当做64位的单元
//既可以作为寄存器
//也可以作为临时的64位的变量或者立即数
char* REGISTER::get_val()
{
    return val;
}

bool REGISTER::write_val(const char* nval)
{
    for(int i=0;i!=8;i++)
    {
        val[i]=nval[i];
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

//实现PC类
void PC::create(const char* c)
{
    pc.write_val(c);
}

char* PC::get_val()
{
    return pc.get_val();
}

bool PC::refersh()
{
    pc.write_val(valP.get_val());
    return true;
}