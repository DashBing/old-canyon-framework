#include "types.h"

#include "vmclass.hpp"
#include "datatypedef.h"
#include "resdef.h"
#include "inc_clibs.hpp"

#ifndef _CVM_FUNDEF_HPP
#define _CVM_FUNDEF_HPP

namespace canyon{

VM::VM(){
    init();
}

VM::VM(char * mem_i, uint64_t memlen_i){
    init();
    set_mem_adr(mem_i, memlen_i);
}

VM::VM(uint64_t memlen_i){
    init();
    mem = (char *)calloc(memlen_i, sizeof(char));
}

void VM::clean_res(){
    for(uint16_t i = 0; i<res_size-1; i++){
        res[i] = 0;
    }
}

void VM::init(){
    clean_res();
    prot_start = 0;
    prot_end = 0;
}

void VM::reset(){  // 重置
    prot = 0;
    prot_res = 0;
    init();
    memlen = 0;
    mem = 0;
}

void VM::set_mem_adr(char * mem_i, uint64_t memlen_i){  // 设置内存地址
    mem = mem_i;
    memlen = memlen_i;
}

void VM::set_res_chr(uint16_t index, uint8_t value){  // 写寄存器(按字节)
    uint16_t a, b;
    uint64_t val = value;
    a = index / 8;
    if(res_acc_w(index)){
        b = index % 8;
        val <<= (8 * (7 - b));
        if(a == 0)
            prot_res |= val;
        else
            res [a - 1] |= val;
    }
}

uint8_t VM::get_res_chr(uint16_t index){  // 读寄存器(按字节)
    uint16_t a, b;
    uint64_t val = 0, g = 0xff;
    a = index / 8;
    b = index % 8;
    g <<= (8 * (7 - b));
    if(a == 0)
        val = prot_res;
    else 
        val = res[a - 1];
    val &= g;
    val >>= (8 * (7 - b));
    return((uint8_t)val);
}

void VM::set_res(uint16_t index, uint64_t value){  // 写寄存器
    if(res_acc_w(index)){
        index = index / 8;
        if(index == 0)
            prot_res = value; 
        else
            res[index - 1] = value;
    }
}

uint64_t VM::get_res(uint16_t index){  // 读寄存器
    index = index / 8;
    if(index == 0)
        return(prot_res);
    else
        return(res[index]);
}

void VM::set_mem(uint64_t index, uint8_t value){
    uint64_t start=prot_start, end=prot_end;
    if(end==0)end=memlen-1;  // 注意, 有可能导致安全问题, 注意防护
    if(mem_acc_w(index)){
        if(index+start <= end){
            mem[index+start] = value;
        }
    }
}

uint8_t VM::get_mem(uint64_t index){
    uint64_t start=prot_start, end=prot_end;
    if(end==0)end=memlen-1;  // 注意, 有可能导致安全问题, 注意防护
    if(index+start <= end)
        return(mem[index+start]);
    else return(0);
}

bool VM::isin_kernel(uint64_t adr){
    if(prot){
        uint64_t index = get_res(RES_PR);
        uint64_t a=0, b=0, tmp=index;
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

bool VM::mem_acc_w(uint64_t index){
    uint64_t start=prot_start;
    return(!(isin_kernel(index+start) && !(isin_kernel(get_res(RES_LN)))));
}

bool VM::res_acc_w(uint16_t index){
    return(!(RES_RN(RES_RN_DE(index))==RES_PR && !(isin_kernel(get_res(RES_LN)))));
}

}

#endif
