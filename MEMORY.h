#include"common.h"
using namespace std;
class MEMORY
{
    public:
        MEMORY(){};
        void memory();//直接调用它就行
        void bubble();

        bool ifbubble();

        void renewstat();
        void getAddr();

        void write();
        void read();
        void read_memory();
        void write_memory();
        
    private:
        REGISTER valE,valA,valM;
        char stat=1,icode,Cnd,dstE,dstM;
        //void (MEMORY::*func[12][7])();
        REGISTER Addr;
};