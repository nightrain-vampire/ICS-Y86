from ctypes import *
pDLL = windll.LoadLibrary("../CCH_QH.dll")

def refresh_reg():
    return [\
    str(pDLL.get_rax()),\
    str(pDLL.get_rcx()),\
    str(pDLL.get_rdx()),\
    str(pDLL.get_rbx()),\
    str(pDLL.get_rsp()),\
    str(pDLL.get_rbp()),\
    str(pDLL.get_rsi()),\
    str(pDLL.get_rdi()),\
    str(pDLL.get_r8()),\
    str(pDLL.get_r9()),\
    str(pDLL.get_r10()),\
    str(pDLL.get_r11()),\
    str(pDLL.get_r12()),\
    str(pDLL.get_r13()),\
    str(pDLL.get_r14())]

def refresh_cc():
    return [str(pDLL.get_ZF()),str(pDLL.get_SF()),str(pDLL.get_SF())]
