#include"main.h"
FETCH Fetch;
DECODE Decode;
EXECUTE Execute;
MEMORY Memory;
WBACK Wback;

extern "C" void CCH_QH(){
    Fetch.fetch();
    Decode.decode();
    Execute.execute();
    Memory.memory();
    Wback.wback();
}

