#include"common.h"
using namespace std;
class WBACK
{
    public:
        WBACK(){};
        void wback();//直接调用它就行
        //void bubble();
        void write();

       //bool ifbubble();
        bool ifstall();
        
    private:
        //REGISTER pc,valC,valP;
        //char stat,icode,ifun,rA,rB;
        //void (WBACK::*func[12][7])();
        char stat,icode,dstE,dstM;
        REGISTER valE,valM;
};