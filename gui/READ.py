from ctypes import *
pDLL = windll.LoadLibrary("../CCH_QH.dll")
pDLL.get_rax.restype=c_longlong
pDLL.get_rax.restype=c_longlong
pDLL.get_rcx.restype=c_longlong
pDLL.get_rdx.restype=c_longlong
pDLL.get_rbx.restype=c_longlong
pDLL.get_rsp.restype=c_longlong
pDLL.get_rbp.restype=c_longlong
pDLL.get_rsi.restype=c_longlong
pDLL.get_rdi.restype=c_longlong
pDLL.get_r8.restype=c_longlong
pDLL.get_r9.restype=c_longlong
pDLL.get_r10.restype=c_longlong
pDLL.get_r11.restype=c_longlong
pDLL.get_r12.restype=c_longlong
pDLL.get_r13.restype=c_longlong
pDLL.get_r14.restype=c_longlong

pDLL.get_r14.restype=c_longlong
pDLL.get_r14.restype=c_longlong
pDLL.get_r14.restype=c_longlong
pDLL.get_r14.restype=c_longlong
pDLL.get_r14.restype=c_longlong
pDLL.get_r14.restype=c_longlong

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
    return [str(pDLL.get_ZF()),str(pDLL.get_SF()),str(pDLL.get_OF())]

def refresh_dmemory():
    ret=[]
    temp=""
    for i in range(0,80):
        temp+=str(pDLL.get_imemory(i))
        if i%2==1:
            temp+=" "
        if i%8==7:
            ret.append(temp)
            temp=""
    return ret

def refresh_STAT():
    return pDLL.get_STAT()

def refresh_F_reg():
    return [hex(pDLL.F_reg_predPC())]

pDLL.D_reg_valC.restype=c_longlong
pDLL.D_reg_valP.restype=c_longlong
def refresh_D_reg():
    return [\
    str(pDLL.D_reg_stat()),\
    str(pDLL.D_reg_icode()),\
    str(pDLL.D_reg_ifun()),\
    str(pDLL.D_reg_rA()),\
    str(pDLL.D_reg_rB()),\
    str(pDLL.D_reg_valC()),\
    str(pDLL.D_reg_valP())]

pDLL.E_reg_valC.restype=c_longlong
pDLL.E_reg_valA.restype=c_longlong
pDLL.E_reg_valB.restype=c_longlong
def refresh_E_reg():
    return [\
    str(pDLL.E_reg_stat()),\
    str(pDLL.E_reg_icode()),\
    str(pDLL.E_reg_ifun()),\
    str(pDLL.E_reg_dstE()),\
    str(pDLL.E_reg_dstM()),\
    str(pDLL.E_reg_srcA()),\
    str(pDLL.E_reg_srcB()),\
    str(pDLL.E_reg_valC()),\
    str(pDLL.E_reg_valA()),\
    str(pDLL.E_reg_valB())]

pDLL.M_reg_valA.restype=c_longlong
pDLL.M_reg_valE.restype=c_longlong
def refresh_M_reg():
    return [\
    str(pDLL.M_reg_stat()),\
    str(pDLL.M_reg_icode()),\
    str(pDLL.M_reg_cnd()),\
    str(pDLL.M_reg_dstE()),\
    str(pDLL.M_reg_dstM()),\
    str(pDLL.M_reg_valE()),\
    str(pDLL.M_reg_valA())]

pDLL.W_reg_valE.restype=c_longlong
pDLL.W_reg_valM.restype=c_longlong
def refresh_W_reg():
    return [\
    str(pDLL.W_reg_stat()),\
    str(pDLL.W_reg_icode()),\
    str(pDLL.W_reg_dstE()),\
    str(pDLL.W_reg_dstM()),\
    str(pDLL.W_reg_valE()),\
    str(pDLL.W_reg_valM())]

def refresh_F():
    return [\
    str(pDLL.F_icode()),\
    str(pDLL.F_ifun())]

def refresh_D():
    return [\
    str(pDLL.D_icode()),\
    str(pDLL.D_ifun())]

def refresh_E():
    return [\
    str(pDLL.E_icode()),\
    str(pDLL.E_ifun())]

def refresh_M():
    return [\
    str(pDLL.M_icode()),\
    str(pDLL.M_ifun())]


def refresh_W():
    return [\
    str(pDLL.W_icode()),\
    str(pDLL.W_ifun())]
