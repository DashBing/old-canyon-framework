#include "types.h"
#include "datatypedef.h"
#include "cmddef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

#ifndef vm_template
#define vm_template template<UINT16 res_size=16>
#endif

vm_template
class VM{
    public:
    static bool prot;  // 是否开保护模式
    static UINT64 memlen;  // 内存大小(字节)
    static UINT64 prot_res;  // 第一个寄存器(特殊所以分离)
    UINT64 res[res_size - 1];  // 寄存器数组, 大小由模板决定
    static char * mem;  // 内存地址
    public:
    VM(){}
    VM(char * mem_i, UINT64 memlen_i){
        set_mem_adr(mem_i, memlen_i);
    }
    VM(UINT64 memlen_i){
        mem = (char *)calloc(memlen_i, sizeof(char));
    }
    void reset(){  // 重置
        prot = 0;
        memlen = 0;
        prot_res = 0;
        res = {};
        mem = 0;
    }
    void set_mem_adr(char * mem_i, UINT64 memlen_i){  // 设置内存地址
        mem = mem_i;
        memlen = memlen_i;
    }
    void set_res_chr(UINT16 index, UINT8 value){  // 写寄存器(按字节)
        UINT16 a, b;
        UINT64 val = value;
        a = index / 8;
        b = index % 8;
        val <<= (8 * (7 - b));
        if(a == 0){
            prot_res |= val;
        }
        else{
            res [a - 1] |= val;
        }
    }
    UINT8 get_res_chr(UINT16 index){  // 读寄存器(按字节)
        UINT16 a, b;
        UINT64 val = 0, g = 0xff;
        a = index / 8;
        b = index % 8;
        g <<= (8 * (7 - b));
        if(a == 0){
            val = prot_res;
        }
        else{
            val = res[a - 1];
        }
        val &= g;
        val >>= (8 * (7 - b));
        return((UINT8)val);
    }
    void set_res(UINT16 index, UINT64 value){  // 写寄存器
        index = index / 8;
        if(index == 0){
            prot_res = value;
        }
        else{
            res[index - 1] = value;
        }
    }
    UINT64 get_res(UINT16 index){  // 读寄存器
        index = index / 8;
        if(index == 0){
            return(prot_res);
        }
        else{
            return(res[index]);
        }
    }
    void set_mem(UINT64 index, UINT8 value, UINT64 start=0, UINT64 end=memlen-1){}
    UINT8 get_mem(UINT64 index, UINT64 start=0, UINT64 end=memlen-1){
        return(0);
    }
    void run_command(command cmd);
    void run(UINT64 entry0);
    ~VM(){}
};

#include "runners.hpp"

#ifdef vm_template
#undef vm_template
#endif

#endif
