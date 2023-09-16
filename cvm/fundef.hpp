#include "vmclass.hpp"
#include "vm_template.hpp"
#include "types.h"
#include "datatypedef.h"
#include "resdef.h"
#include <cstdlib>

#ifndef _CVM_FUNDEF_HPP
#define _CVM_FUNDEF_HPP

vm_template
VM<res_size>::VM(){}

vm_template
VM<res_size>::VM(char * mem_i, UINT64 memlen_i){
    set_mem_adr(mem_i, memlen_i);
}

vm_template
VM<res_size>::VM(UINT64 memlen_i){
    mem = (char *)calloc(memlen_i, sizeof(char));
}

vm_template
void VM<res_size>::reset(){  // 重置
    prot = 0;
    memlen = 0;
    prot_res = 0;
    res = {};
    mem = 0;
}

vm_template
void VM<res_size>::set_mem_adr(char * mem_i, UINT64 memlen_i){  // 设置内存地址
    mem = mem_i;
    memlen = memlen_i;
}

vm_template
void VM<res_size>::set_res_chr(UINT16 index, UINT8 value){  // 写寄存器(按字节)
    UINT16 a, b;
    UINT64 val = value;
    a = index / 8;
    if(!(RES_RN(a)==RES_PR && !(isin_kernel(get_res(RES_LN))))){
        b = index % 8;
        val <<= (8 * (7 - b));
        if(a == 0)
            prot_res |= val;
        else
            res [a - 1] |= val;
    }
}

vm_template
UINT8 VM<res_size>::get_res_chr(UINT16 index){  // 读寄存器(按字节)
    UINT16 a, b;
    UINT64 val = 0, g = 0xff;
    a = index / 8;
    b = index % 8;
    g <<= (8 * (7 - b));
    if(a == 0)
        val = prot_res;
    else 
        val = res[a - 1];
    val &= g;
    val >>= (8 * (7 - b));
    return((UINT8)val);
}

vm_template
void VM<res_size>::set_res(UINT16 index, UINT64 value){  // 写寄存器
    if(!(index==RES_PR && !(isin_kernel(get_res(RES_LN))))){
        index = index / 8;
        if(index == 0)
            prot_res = value; 
        else
            res[index - 1] = value;
    }
}

vm_template
UINT64 VM<res_size>::get_res(UINT16 index){  // 读寄存器
    index = index / 8;
    if(index == 0)
        return(prot_res);
    else
        return(res[index]);
}

vm_template
void VM<res_size>::set_mem(UINT64 index, UINT8 value, UINT64 start=0, UINT64 end=0){
    if(end==0)end=memlen-1;  // 注意, 有可能导致安全问题, 注意防护
    if(!(isin_kernel(index+start) && !(isin_kernel(get_res(RES_LN))))){
        if(index+start <= end){
            mem[index+start] = value;
        }
    }
}

vm_template
UINT8 VM<res_size>::get_mem(UINT64 index, UINT64 start=0, UINT64 end=0){
    if(end==0)end=memlen-1;  // 注意, 有可能导致安全问题, 注意防护
    if(index+start <= end)
        return(mem[index+start]);
    else return(0);
}

vm_template
bool VM<res_size>::isin_kernel(UINT64 adr){
    if(prot){
        UINT64 index = get_res(RES_PR);
        UINT64 a=0, b=0, tmp=index;
        for(;index<tmp+8;index++){
            a |= get_mem(index);
            a<<=8;
        }
        tmp=index;
        for(;index<tmp+8;index++){
            b |= get_mem(index);
            b<<=8;
        }
        return((adr>=a) && (adr<=b));
    }
    else{
        return(true);
    }
}

vm_template
VM<res_size>::~VM(){}

#endif
