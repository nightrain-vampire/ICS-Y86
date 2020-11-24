#include"common.h"

class F_REGISTER
{
    public:
        F_REGISTER(){}

        char* read_predPC(){return predPC.get_val();}
        void write_predPC(const char* s){predPC.write_val(s);}

    private:
        REGISTER predPC;
};