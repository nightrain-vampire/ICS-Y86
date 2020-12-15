import pygame
import sys
import os
import tkinter
import tkinter.filedialog
from pygame._sdl2.video import Window
from COLOR import *
from READ import *
def app_path():
    if hasattr(sys, 'frozen'):
        return os.path.dirname(sys.executable)
    return os.path.dirname(__file__)#冻结路径，防止pyinstaller打包时当前文件夹路径被覆盖

def init_ins():
    out=''
    #f=tkinter.filedialog.askopenfile()#用tkinter可视化打开文件
    f=open("../testexample_honor/ldriver.yo")
    lastlen=0
    lastadd=0
    add=0
    for line in f:#将yo文件处理为指令字符串
        if line[0:5].strip()!='':
            add=int(line[0:5],16)
            out+=(add-lastadd-lastlen//2)*'00'#将空着的用"0"补全
            out+=line[7:28].strip()
            lastadd=add
            lastlen=len(line[7:28].strip())
    f.close()
    return out

tk=tkinter.Tk()
tk.withdraw()

pDLL.init_imemory(init_ins().encode())#将指令传给c程序。用.encode()的方法让字符串成为二进制编码
SCREEN_SIZE=[tk.winfo_screenwidth(),tk.winfo_screenheight()]#用tkinter获当前屏幕大小
PATH=app_path()+'\\'#冻结路径
pygame.init()

#以下是对背景以及窗口大小、位置、标题、图标的设置
icon=pygame.image.load(PATH+'Y86.ico')
pygame.display.set_icon(icon) 
pygame.display.set_caption('Y86模拟器')
BG=pygame.image.load(PATH+'bg.jpg')
BG_SIZE=BG.get_size()#获得图片大小
WINDOW_RATE=5/6#设置窗口高度占屏幕的比例
fbs=(int(BG_SIZE[0]*(SCREEN_SIZE[1]*WINDOW_RATE)/BG_SIZE[1]),int(SCREEN_SIZE[1]*WINDOW_RATE))#窗口大小自适应
BG=pygame.transform.scale(BG,fbs)#缩放图片
os.environ['SDL_VIDEO_CENTERED'] = '1'#居中显示
OPACITY=150#设置蒙板透明度
mask=pygame.Surface(fbs)
mask.fill(WHITE)#蒙板设为白色
mask.set_alpha(OPACITY)
screen=pygame.display.set_mode(fbs)
Window.from_display_module()

#以下是一些关于字体的常量设定
SYS_FONT='Verdana'#字体
FONT=pygame.font.SysFont(SYS_FONT,15)#字号
FONT_COLOR=BLACK#颜色统一为黑色

general_size=FONT.size('%rax')#general_size存的是所有单元的大小

NEXT_NAME="NEXT"
NEXT_size=FONT.size(NEXT_NAME)

REG_POS=(2*general_size[0]+2*general_size[0],0.8*fbs[1])
REG_GRID={'stat':REG_POS[0]+2*general_size[0],\
    'icode':REG_POS[0]+4*general_size[0],\
    'ifun':REG_POS[0]+6*general_size[0],\
    'cnd':REG_POS[0]+6*general_size[0],\
    'rA':REG_POS[0]+11*general_size[0],\
    'rB':REG_POS[0]+12.5*general_size[0],\
    'valC':REG_POS[0]+8*general_size[0],\
    'valE':REG_POS[0]+8*general_size[0],\
    'valA':REG_POS[0]+13*general_size[0],\
    'valM':REG_POS[0]+13*general_size[0],\
    'valB':REG_POS[0]+13*general_size[0],\
    'valP':REG_POS[0]+14*general_size[0],\
    'dstE':REG_POS[0]+18*general_size[0],\
    'dstM':REG_POS[0]+20*general_size[0],\
    'srcA':REG_POS[0]+18*general_size[0],\
    'srcB':REG_POS[0]+20*general_size[0],\
    'predPC':REG_POS[0]+2*general_size[0]}

Ins=[[FONT.render("halt",True,FONT_COLOR)],\
    [FONT.render("nop",True,FONT_COLOR)],\
    [FONT.render("rrmovq",True,FONT_COLOR),FONT.render("cmovle",True,FONT_COLOR),FONT.render("cmovl",True,FONT_COLOR),FONT.render("cmove",True,FONT_COLOR),FONT.render("cmovne",True,FONT_COLOR),FONT.render("cmovge",True,FONT_COLOR),FONT.render("cmovg",True,FONT_COLOR)],\
    [FONT.render("irmovq",True,FONT_COLOR)],\
    [FONT.render("rmmovq",True,FONT_COLOR)],\
    [FONT.render("mrmovq",True,FONT_COLOR)],\
    [FONT.render("addq",True,FONT_COLOR),FONT.render("subq",True,FONT_COLOR),FONT.render("andq",True,FONT_COLOR),FONT.render("xorq",True,FONT_COLOR)],\
    [FONT.render("jmp",True,FONT_COLOR),FONT.render("jle",True,FONT_COLOR),FONT.render("jl",True,FONT_COLOR),FONT.render("je",True,FONT_COLOR),FONT.render("jne",True,FONT_COLOR),FONT.render("jge",True,FONT_COLOR),FONT.render("jg",True,FONT_COLOR)],\
    [FONT.render("call",True,FONT_COLOR)],\
    [FONT.render("ret",True,FONT_COLOR)],\
    [FONT.render("pushq",True,FONT_COLOR)],\
    [FONT.render("popq",True,FONT_COLOR)]]

STAT=1

def refresh():
    CC_NAMES=['%ZF','%SF','%OF']
    CC_VALS=refresh_cc()
    CC_FONTS=[]
    for i in range(0,3):
        temp_name_size=FONT.size(CC_NAMES[i])
        temp_val_size=FONT.size(CC_VALS[i])
        CC_FONTS.append([FONT.render(CC_NAMES[i],True,FONT_COLOR),((2*i+6)*general_size[0],0),FONT.render(CC_VALS[i],True,FONT_COLOR),((2*i+6)*general_size[0]+0.5*(temp_name_size[0]-temp_val_size[0]),general_size[1])])
        #warning:同上
    for each in CC_FONTS:
        screen.blit(each[0],each[1])
        screen.blit(each[2],each[3])

    REGISTER_NAMES=['%rax','%rcx','%rdx','%rbx','%rsp','%rbp','%rsi','%rdi','%r8','%r9','%r10','%r11','%r12','%r13','%r14']
    REGISTER_VALS=refresh_reg()
    REGISTER_FONTS=[]
    for i in range(0,15):
        temp_name_size=FONT.size(REGISTER_NAMES[i])
        temp_val_size=FONT.size(REGISTER_VALS[i])
        REGISTER_FONTS.append([FONT.render(REGISTER_NAMES[i],True,FONT_COLOR),(0,2*i*temp_name_size[1]),FONT.render(REGISTER_VALS[i],True,FONT_COLOR),(0,(2*i+1)*temp_name_size[1])])
    for each in REGISTER_FONTS:
        screen.blit(each[0],each[1])
        screen.blit(each[2],each[3])

    F_reg_name=['predPC']
    F_reg_val=refresh_F_reg()
    F_reg_FONTS=[[FONT.render(F_reg_name[0]+':'+F_reg_val[0],True,FONT_COLOR),(REG_GRID[F_reg_name[0]],REG_POS[1]+3*general_size[1])]]
    for each in F_reg_FONTS:
        screen.blit(each[0],each[1])

    F_ins=refresh_F()
    screen.blit(Ins[int(F_ins[0])][int(F_ins[1])],(REG_POS[0]-general_size[0],REG_POS[1]+1.5*general_size[1]))

    D_reg_name=['stat','icode','ifun','rA','rB','valC','valP']
    D_reg_val=refresh_D_reg()
    D_reg_FONTS=[]
    temp_len=len(D_reg_name)
    for i in range(0,temp_len):
        D_reg_FONTS.append([FONT.render(D_reg_name[i]+':'+D_reg_val[i],True,FONT_COLOR),(REG_GRID[D_reg_name[i]],REG_POS[1]-0*general_size[1])])
    for each in D_reg_FONTS:
        screen.blit(each[0],each[1])

    D_ins=refresh_D()
    screen.blit(Ins[int(D_ins[0])][int(D_ins[1])],(REG_POS[0]-general_size[0],REG_POS[1]-1.5*general_size[1]))

    E_reg_name=['stat','icode','ifun','dstE','dstM','srcA','srcB','valC','valA','valB']
    E_reg_val=refresh_E_reg()
    E_reg_FONTS=[]
    temp_len=len(E_reg_name)
    for i in range(0,temp_len):
        E_reg_FONTS.append([FONT.render(E_reg_name[i]+':'+E_reg_val[i],True,FONT_COLOR),(REG_GRID[E_reg_name[i]],REG_POS[1]-(3-(i==9 or i==5 or i==6))*general_size[1])])
    for each in E_reg_FONTS:
        screen.blit(each[0],each[1])

    E_ins=refresh_E()
    screen.blit(Ins[int(E_ins[0])][int(E_ins[1])],(REG_POS[0]-general_size[0],REG_POS[1]-4.5*general_size[1]))

    M_reg_name=['stat','icode','cnd','dstE','dstM','valE','valA']
    M_reg_val=refresh_M_reg()
    M_reg_FONTS=[]
    temp_len=len(M_reg_name)
    for i in range(0,temp_len):
        M_reg_FONTS.append([FONT.render(M_reg_name[i]+':'+M_reg_val[i],True,FONT_COLOR),(REG_GRID[M_reg_name[i]],REG_POS[1]-6*general_size[1])])
    for each in M_reg_FONTS:
        screen.blit(each[0],each[1])

    M_ins=refresh_M()
    screen.blit(Ins[int(M_ins[0])][int(M_ins[1])],(REG_POS[0]-general_size[0],REG_POS[1]-7.5*general_size[1]))

    W_reg_name=['stat','icode','dstE','dstM','valE','valM']
    W_reg_val=refresh_W_reg()
    W_reg_FONTS=[]

    W_ins=refresh_W()
    screen.blit(Ins[int(W_ins[0])][int(W_ins[1])],(REG_POS[0]-general_size[0],REG_POS[1]-10.5*general_size[1]))

    temp_len=len(W_reg_name)
    for i in range(0,temp_len):
        W_reg_FONTS.append([FONT.render(W_reg_name[i]+':'+W_reg_val[i],True,FONT_COLOR),(REG_GRID[W_reg_name[i]],REG_POS[1]-9*general_size[1])])
    for each in W_reg_FONTS:
        screen.blit(each[0],each[1])

flag=0
speed=5#自动运行模式下的帧率
run=1
AUTO=0
while True:
    screen.blit(BG,(0,0))
    screen.blit(mask,(0,0))
    screen.blit(FONT.render(NEXT_NAME,True,FONT_COLOR),(fbs[0]-NEXT_size[0],fbs[1]-NEXT_size[1]))
    #screen.blit(FONT.render(DMEMORY_NAME,True,FONT_COLOR),DMEMORY_POS)
    screen.blit(FONT.render("PIPLINE REGIETERS:",True,FONT_COLOR),(REG_POS[0]-1.5*general_size[0],REG_POS[1]-12*general_size[1]))
    screen.blit(FONT.render("F_reg:",True,FONT_COLOR),(REG_POS[0],REG_POS[1]+3*general_size[1]))
    screen.blit(FONT.render("D_reg:",True,FONT_COLOR),(REG_POS[0],REG_POS[1]-0*general_size[1]))
    screen.blit(FONT.render("E_reg:",True,FONT_COLOR),(REG_POS[0],REG_POS[1]-3*general_size[1]))
    screen.blit(FONT.render("M_reg:",True,FONT_COLOR),(REG_POS[0],REG_POS[1]-6*general_size[1]))
    screen.blit(FONT.render("W_reg:",True,FONT_COLOR),(REG_POS[0],REG_POS[1]-9*general_size[1]))
    refresh()
    STAT=refresh_STAT()
    if STAT==1:
        screen.blit(FONT.render("RUNNING!",True,FONT_COLOR),(fbs[0]*0.6,fbs[1]*0.3))
    if STAT==2:
        run=0
        AUTO=0
        screen.blit(FONT.render("HALT!",True,FONT_COLOR),(fbs[0]*0.6,fbs[1]*0.3))
    if STAT==3:
        run=0
        AUTO=0
        screen.blit(FONT.render("DOMAIN ERROR!",True,FONT_COLOR),(fbs[0]*0.6,fbs[1]*0.3))
    if STAT==4:
        run=0
        AUTO=0
        screen.blit(FONT.render("INVALID INSTRUSTION!",True,FONT_COLOR),(fbs[0]*0.6,fbs[1]*0.3))
    if flag:
        pDLL.CCH_QH()
        flag=0 or AUTO
    screen.blit(FONT.render("MODE:",True,FONT_COLOR),(fbs[0]-4*general_size[0],0))
    if(AUTO):
        screen.blit(FONT.render("AUTO",True,FONT_COLOR),(fbs[0]-2*general_size[0],0))
    else:
        screen.blit(FONT.render("MANUAL",True,FONT_COLOR),(fbs[0]-2*general_size[0],0))
    pygame.display.flip()
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type==pygame.MOUSEBUTTONDOWN:
            if(event.pos[0]>fbs[0]-NEXT_size[0] and event.pos[1]>fbs[1]-NEXT_size[1]):
                flag=run
            if(event.button==5):
                flag=run
        if event.type==pygame.KEYDOWN:
            if(event.key==pygame.K_EQUALS and AUTO==1):
                speed+=2
            if(event.key==pygame.K_MINUS and AUTO==1):
                speed-=2
                if speed<2:
                    speed=2
            if(event.key==pygame.K_RIGHT or event.key==pygame.K_DOWN):
                flag=run
            elif(run==1 and AUTO==0 and event.key==pygame.K_a):
                flag=1
                AUTO=1
            elif(AUTO==1 and event.key==pygame.K_a):
                flag=0
                AUTO=0
                speed=5
    if AUTO:
        pygame.time.delay(1000//speed)#自动运行的帧率设为5
    else:
        pygame.time.delay(30)


