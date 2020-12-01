#include"common.h"
using namespace std;
class WBACK
{
    public:
        WBACK(){};
        void wback();//直接调用它就行
        void read();
        void write();

       
        bool ifstall();
        
    private:
        char stat,icode,dstE,dstM;
        REGISTER valE,valM;
};