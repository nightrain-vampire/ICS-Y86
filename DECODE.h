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
        bool ifstall();

        REGISTER SelFwdA(char d_rval);
        REGISTER FwdB(char d_rval);
    private:
        REGISTER valC,valP;
        char stat,icode,ifun,rA,rB;
        //void (DECODE::*func[12][7])();
        REGISTER valA,valB;
        char dstE,dstM,srcA,srcB;
};