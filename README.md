# ICS-Y86
复旦大学ICS PJ作业

---

持续更新中...
文件依赖关系：
R.h
↑
F_Reg.h、D_Reg.h、E_Reg.h、W_Reg.h、W_Reg.h
↑
TOP.h TOP.cpp
↑
common.h
↑
FETCH.h、DECODE.h、EXECUTE.h、MEMORY.h、WBACK.h
↑
main.cpp主执行函数
↑
python文件



#### R.h:

包含REGISTER类(64位数据)、REGISTERS类的属性、方法的声明。在实现REGISTER类时，使用了union联合，可以将数据解释为longlong 或 char数组，前者方便内存的寻址，后者方便赋值。

#### F_Reg.h、D_Reg.h、E_Reg.h、W_Reg.h、W_Reg.h:

包含五个流水线寄存器类的属性、方法的声明

#### TOP.h TOP.cpp:

声明所有的全局变量

#### common.h:

用extern关键字声明全局变量，之后的文件include"common.h"即可

#### FETCH.h、DECODE.h、EXECUTE.h、MEMORY.h、WBACK.h“

五个阶段类的属性、方法的声明。使用类来封装是为了便于使用统一的接口，以及在不同命名空间下用同一方法名，避免了函数的混乱。

