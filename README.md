# ICS-Y86
这是崔晨昊、祁昊小组的Y86模拟器的自述文件

## 运行环境以及运行方法

本模拟器需要在**Windows**下运行

(由于读取dll库时采用的相对路径，所以请不要改变文件夹的顺序)

模拟器运行程序为：../gui/Y86模拟器.exe

**HINT**：由于用了tkinter包获取屏幕大小以及打开文件选取对话框，运行时较慢，同时**有可能**几秒钟后仍无法显示第一个文件选择的窗口。此时程序在后台运行，但是窗口没有刷出来，可以尝试在任务管理器中双击打开 。  ps:tkinter的这个函数确实不稳定，窗口刷出来很慢......如果一直无法运行，请联系我们小组修改代码。

![](.\gui\hint.png)

[^1]: 测试文件选择窗口无法刷出时可能的解决方法

### 运行方法

双击<u>**exe文件**</u>后静待几秒，弹出对话框。选择并打开要测试的.yo文件后(已经附在testexample文件夹中)，会弹出前端窗口，窗口的左侧显示15个寄存器的值，上端显示三个CC寄存器的值，中部和下部显示程序运行状态，以及5个流水线寄存器的值。

单击屏幕右下角的NEXT、按键盘→键、↓键、鼠标滚轮下滚(推荐用这个hh)均可以使CPU执行一个时间周期。

CPU状态为halt、domain error、invalid instructon时，前端不会再响应鼠标、键盘事件。

按下键盘A键，可以将模拟器设为自动运行，再次按下A键，仍切换回手动运行状态。(见窗口右上角AUTO、MANUAL标识)



本模拟器后端使用了C++编写，makefile用于编译产生动态链接库。前端使用python3编写，使用了pygame拓展包。(**想要用python运行.pyw程序的话**，由于代码应用了最近新发布的pygame2.0.0的一个实验性功能，如果之前安装了pygame包，请务必pip install --upgrade pygame)



## 文件依赖关系

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
main.cpp



CCH_QH.dll   编译出的dll库

↑
Y86模拟器.pyw



#### R.h:

包含REGISTER类(64位数据)、REGISTERS类的属性、方法的声明。在实现REGISTER类时，使用了union联合，可以将数据解释为longlong 或 char数组，前者方便内存的寻址，后者方便赋值。

#### F_Reg.h、D_Reg.h、E_Reg.h、W_Reg.h、W_Reg.h:

包含五个流水线寄存器类的属性、方法的声明

#### TOP.h TOP.cpp:

声明所有的全局变量

#### common.h:

用extern关键字声明全局变量，之后的文件include"common.h"即可

#### FETCH.h、DECODE.h、EXECUTE.h、MEMORY.h、WBACK.h

五个阶段类的属性、方法的声明。使用类来封装是为了便于使用统一的接口，以及在不同命名空间下用同一方法名，避免了函数的混乱。

#### main.cpp

为前端提供接口

#### COLOR.py

定义一些颜色常量

#### READ.py

调用ctype库，读取dll中的接口函数，做一些预处理

#### Y86模拟器.pyw

绘制主要的图形界面以及窗口事件响应