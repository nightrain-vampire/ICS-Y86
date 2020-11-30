#include"main.h"
#include<string.h>
FETCH Fetch;
DECODE Decode;
EXECUTE Execute;
MEMORY Memory;
WBACK Wback;

extern "C" void CCH_QH(){
    printf("you have called me!\n");
    Fetch.fetch();
    printf("fetch runs well!\n");
    Decode.decode();
    printf("decode runs well!\n");
    Execute.execute();
    printf("execute runs well!\n");
    //Memory.memory();
    //printf("memory runs well!\n");
    //Wback.wback();
    //printf("writeback runs well!\n");
}

extern "C" void init_imemory(char* s){
    for(int i=0;i<strlen(s);i++)
        imemory[i]=s[i]-'0';
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
