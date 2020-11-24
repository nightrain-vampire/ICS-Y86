#include"F_Reg.h"
using namespace std;
REGISTER F::get_val(){
    return predPC;
}
bool F::write_val(const REGISTER& PredictPC){
    predPC=PredictPC;
    return 1;
}