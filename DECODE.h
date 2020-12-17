#include"common.h"
using namespace std;
class DECODE
{
    public:
        DECODE(){};
        void decode();//直接调用它就行
        void bubble();
        void write();
        void read();

        void cal_dstE();
        void cal_dstM();
        void cal_srcA();
        void cal_srcB();

        bool ifbubble();

        //void invalid();
        //bool islegal();

        REGISTER SelFwdA(char d_rval);
        REGISTER SelFwdB(char d_rval);

        char get_icode(){return icode;}
        char get_ifun(){return ifun;}
        
    private:
        REGISTER valC,valP;
        char stat=1,icode,ifun,rA,rB;
        //void (DECODE::*func[12][7])();
        REGISTER valA,valB;
        char dstE,dstM,srcA,srcB;
};