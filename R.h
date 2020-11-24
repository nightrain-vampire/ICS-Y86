#pragma once
#include<stdio.h>
using namespace std;
union Val{
    char ch[8]={0};
    long long ll;
};
class REGISTER{
    public:
        REGISTER& operator+(const REGISTER& r);//注意也是深拷贝，返回一个新的REGISTER
        char* get_val();//读取数据的接口为.get_val()
        long long _get_val();//按照long long来解释val()
        bool write_val(const char* nval);//用char数组写数据的接口为.write_val()
        REGISTER& operator=(const REGISTER& r);//用REGISTER类可以直接赋值;
    private:
        Val val;
};//封装一个64位寄存器类，既可以作为寄存器的基本单元，也可以作为存储临时64位变量的单元

class REGISTERS{
    public:
        char* get_val(int src);
        bool write_val(int dst,const char* valW);
    private:
        REGISTER reg[15];//代表15个64位寄存器
};

// class PC{
//     public:
//         PC(){}
//         PC(const char* c){create(c);};//构造函数，传进去一个参数
//         char* get_val();
//         PC operator+(int i);//pc+int，返回一个新的PC类，注意是深拷贝不是浅拷贝
//         bool refersh();//用valP更新PC
//     private:
//         REGISTER pc;
//         void create(const char*);
// };


