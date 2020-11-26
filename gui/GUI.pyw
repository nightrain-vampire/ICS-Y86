#需要展示的有：15个寄存器的值、3个cc的值、pc的值，stat的值、内存的状况

import pygame
import sys
import os
import tkinter
from pygame._sdl2.video import Window
from COLOR import *

def app_path():
    if hasattr(sys, 'frozen'):
        return os.path.dirname(sys.executable)
    return os.path.dirname(__file__)

SCREEN_SIZE=[tkinter.Tk().winfo_screenwidth(),tkinter.Tk().winfo_screenheight()]
PATH=app_path()+'\\'#冻结路径
pygame.init()

#以下是对背景以及窗口大小、位置的设置
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
FONT_COLOR=BLACK#颜色

general_size=FONT.size('%rax')#general_size存的是所有单元的大小

#以下是一些需要绘制的surface对象列表的以及初始化
REGISTER_NAMES=['%rax','%rcx','%rdx','%rbx','%rsp','%rbp','%rsi','%rdi','%r8','%r9','%r10','%r11','%r12','%r13','%r14']
REGISTER_VALS=['0','0','0','0','0','0','0','0','0','0','0','0','0','0','0']
REGISTER_FONTS=[]
for i in range(0,15):
    temp_name_size=FONT.size(REGISTER_NAMES[i])
    temp_val_size=FONT.size(REGISTER_VALS[i])
    REGISTER_FONTS.append([FONT.render(REGISTER_NAMES[i],True,FONT_COLOR),(0,2*i*temp_name_size[1]),FONT.render(REGISTER_VALS[i],True,FONT_COLOR),(0,(2*i+1)*temp_name_size[1])])
    #warning:现在是append()，如果要动态更改数值，需要先清除

CC_NAMES=['%CF','%ZF','%SF']
CC_VALS=['0','0','0']
CC_FONTS=[]
for i in range(0,3):
    temp_name_size=FONT.size(CC_NAMES[i])
    temp_val_size=FONT.size(CC_VALS[i])
    CC_FONTS.append([FONT.render(CC_NAMES[i],True,FONT_COLOR),((2*i+2)*general_size[0],0),FONT.render(CC_VALS[i],True,FONT_COLOR),((2*i+2)*general_size[0]+0.5*(temp_name_size[0]-temp_val_size[0]),general_size[1])])
    #warning:同上

while True:
    screen.blit(BG,(0,0))
    screen.blit(mask,(0,0))
    for each in REGISTER_FONTS:
        screen.blit(each[0],each[1])
        screen.blit(each[2],each[3])
    for each in CC_FONTS:
        screen.blit(each[0],each[1])
        screen.blit(each[2],each[3])
    pygame.display.flip()
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            sys.exit()
    pygame.time.delay(30)


