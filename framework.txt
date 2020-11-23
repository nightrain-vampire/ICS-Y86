15个基本register//64位 8char rax、rcx、rdx、rbx、rsp、rbp、rsi、rdi、r8、r9、r10、r11、r12、r13、r14
三个cc寄存器//8位 1char zf:0 sf:sign of:overflow
pc//64位 8char
datam//char[4e6]
optim//char[4e6]
stat//1个char，1~4
其余的一些全局变量
所有的都是写类
fetch(){//注意立即数是小端法存储
    halt;
    nop;
    cmovxx;//条件转移
    ir;
    mr;
    rm;
    OPq;
    jxx;
    call;
    ret;
    pushq;
    popq;
}//fetch中函数用来初始化一些全局变量，icode,ifunc,srcA,srcB,dstE,dstM其余所有函数都需要根据这两个给定参数
decode{
}//根据全局变量初始化valA,valB
execute{

}//计算出结果以及改变cc、valx
visit{

}//jxx、call、ret
writeback{

}//写回
refersh{

}






