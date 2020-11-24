#include"common.h"

class F_REGISTER
{
    public:
        F_REGISTER(){}

        char read_predPC(){return predPC;}
        void write_predPC(const char s){predPC=s;}

    private:
        char predPC;
};