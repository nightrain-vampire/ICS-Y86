#include<stdio.h>
using namespace std;
class REGISTER{
    public:
        REGISTER& operator+(const REGISTER& r);//注意也是深拷贝，返回一个新的REGISTER
        char* get_val();//读取数据的接口为.get_val()
        bool write_val(REGISTER nval);//写数据的接口为.write_val()
    private:
        char val[8]={0};
};//封装一个64位寄存器类，既可以作为寄存器的基本单元，也可以作为存储临时64位变量的单元

class REGISTERS{
    public:
        char* get_val(int src);
        bool write_val(int dst,char* valW);
    private:
        REGISTER reg[15];//代表15个64位寄存器
};

class PC{
    public:
        PC(char*);//构造函数，传进去一个参数
        char* get_val();
        PC operator+(int i);//pc+int，返回一个新的PC类，注意是深拷贝不是浅拷贝
        bool refersh();//用valP更新PC
    private:
        REGISTER pc;
};

REGISTER valA,valB,valC,valE,valM;
REGISTERS registers;
PC pc,valP;
char icode,ifun,rA,rB;//warning:实际上icode、ifunc、rA、rB都是半个char，数据读取时要记得结合位运算