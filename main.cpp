#include"main.h"
#include<string.h>
FETCH Fetch;
DECODE Decode;
EXECUTE Execute;
MEMORY Memory;
WBACK Wback;

extern "C" void CCH_QH(){
    Memory.write();
    Execute.write();
    Fetch.write();
    Decode.write();

    // printf("herea\n");
    Wback.wback();
    // printf("hereb\n");
    Memory.memory();
    // printf("herec\n");
    Execute.execute();
    // printf("hered\n");
    Decode.decode();
    // printf("heree\n");
    Fetch.fetch();
    // printf("heref\n");
}

extern "C" void init_imemory(char* s){
    char temp;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0'&&s[i]<='9')
            temp=s[i]-'0';
        else temp=s[i]-'a'+10;
        if(i%2){//奇数，放在char的右边
            imemory[i/2]&=(temp|0xf0);
        }
        else{//偶数，放在char的左边
            imemory[i/2]=(0xFF&(temp<<4))|0x0f;
        }
    }
}//初始化指令数组

//15个寄存器的值接口
extern "C" long long get_rax(){return registers.get_val(0)._get_val();}
extern "C" long long get_rcx(){return registers.get_val(1)._get_val();}
extern "C" long long get_rdx(){return registers.get_val(2)._get_val();}
extern "C" long long get_rbx(){return registers.get_val(3)._get_val();}
extern "C" long long get_rsp(){return registers.get_val(4)._get_val();}
extern "C" long long get_rbp(){return registers.get_val(5)._get_val();}
extern "C" long long get_rsi(){return registers.get_val(6)._get_val();}
extern "C" long long get_rdi(){return registers.get_val(7)._get_val();}
extern "C" long long get_r8(){return registers.get_val(8)._get_val();}
extern "C" long long get_r9(){return registers.get_val(9)._get_val();}
extern "C" long long get_r10(){return registers.get_val(10)._get_val();}
extern "C" long long get_r11(){return registers.get_val(11)._get_val();}
extern "C" long long get_r12(){return registers.get_val(12)._get_val();}
extern "C" long long get_r13(){return registers.get_val(13)._get_val();}
extern "C" long long get_r14(){return registers.get_val(14)._get_val();}

//3个CC寄存器的值接口
extern "C" int get_ZF(){return int(ZF);}
extern "C" int get_SF(){return int(SF);}
extern "C" int get_OF(){return int(OF);}

//读取运行内存
extern "C" int get_imemory(int index){return imemory[index];}

//读取
extern "C" int get_STAT(){return W_reg.get_stat();}

//读取各个流水线寄存器的值
//F_reg
extern "C" long long F_reg_predPC(){return F_reg.get_val()._get_val();}

//D_reg
extern "C" int D_reg_stat(){return D_reg.get_stat();}
extern "C" int D_reg_icode(){return D_reg.get_icode();}
extern "C" int D_reg_ifun(){return D_reg.get_ifun();}
extern "C" int D_reg_rA(){return D_reg.get_rA();}
extern "C" int D_reg_rB(){return D_reg.get_rB();}
extern "C" long long D_reg_valC(){return D_reg.get_valC()._get_val();}
extern "C" long long D_reg_valP(){return D_reg.get_valP()._get_val();}

//E_reg
extern "C" int E_reg_stat(){return E_reg.get_stat();}
extern "C" int E_reg_icode(){return E_reg.get_icode();}
extern "C" int E_reg_ifun(){return E_reg.get_ifun();}
extern "C" int E_reg_dstE(){return E_reg.get_dstE();}
extern "C" int E_reg_dstM(){return E_reg.get_dstM();}
extern "C" int E_reg_srcA(){return E_reg.get_srcA();}
extern "C" int E_reg_srcB(){return E_reg.get_srcB();}
extern "C" long long E_reg_valC(){return E_reg.get_valC()._get_val();}
extern "C" long long E_reg_valA(){return E_reg.get_valA()._get_val();}
extern "C" long long E_reg_valB(){return E_reg.get_valB()._get_val();}

//M_reg
extern "C" int M_reg_stat(){return M_reg.get_stat();}
extern "C" int M_reg_icode(){return M_reg.get_icode();}
extern "C" int M_reg_cnd(){return M_reg.get_cnd();}
extern "C" int M_reg_dstE(){return M_reg.get_dstE();}
extern "C" int M_reg_dstM(){return M_reg.get_dstM();}
extern "C" long long M_reg_valE(){return M_reg.get_valE()._get_val();}
extern "C" long long M_reg_valA(){return M_reg.get_valA()._get_val();}

//W_reg
extern "C" int W_reg_stat(){return W_reg.get_stat();}
extern "C" int W_reg_icode(){return W_reg.get_icode();}
extern "C" int W_reg_dstE(){return W_reg.get_dstE();}
extern "C" int W_reg_dstM(){return W_reg.get_dstM();}
extern "C" long long W_reg_valE(){return W_reg.get_valE()._get_val();}
extern "C" long long W_reg_valM(){return W_reg.get_valM()._get_val();}
