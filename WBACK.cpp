#include"WBACK.h"
using namespace std;
void WBACK::wback()
{
    if (ifstall())
    {
        stat=2;
    }
    else
    {
        write();
    }
}

void WBACK::write()
{
    if(dstE!='F')
    {
        registers.write_val(dstE,valE);
    }
    if(dstM!='F')
    {
        registers.write_val(dstM,valM);
    }
}

bool WBACK::ifstall()
{
    return stat!=1;
}