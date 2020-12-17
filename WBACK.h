#include"common.h"
using namespace std;
class WBACK
{
    public:
        WBACK(){};
        void wback();//直接调用它就行
        void read();
        void write();

        char get_icode(){return icode;}
        char get_ifun(){return ifun;}

    private:
        char stat=1,icode,dstE,dstM,ifun;
        REGISTER valE,valM;
};