#include "vm_template.hpp"
#include "types.h"
#include "datatypedef.h"
#include "cmddef.h"
#include "resdef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

template<UINT16 res_size=16>
class VM{
    public:
    /* static bool prot;  // 是否开保护模式
    static UINT64 memlen;  // 内存大小(字节)
    static UINT64 prot_res;  // 第一个寄存器(特殊所以分离)
    UINT64 res[res_size - 1];  // 寄存器数组, 大小由模板决定
    static char * mem;  // 内存地址 */
    bool prot;
    UINT64 memlen;
    UINT64 prot_res;
    UINT64 res[res_size - 1];
    char * mem;
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
        if(!(RES_RN(a)==RES_PR && !(isin_kernel(get_res(RES_LN))))){
            b = index % 8;
            val <<= (8 * (7 - b));
            if(a == 0){
                prot_res |= val;
            }
            else{
                res [a - 1] |= val;
            }
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
        if(!(index==RES_PR && !(isin_kernel(get_res(RES_LN))))){
            index = index / 8;
            if(index == 0){
                prot_res = value;
            }
            else{
                res[index - 1] = value;
            }
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
    void set_mem(UINT64 index, UINT8 value, UINT64 start=0, UINT64 end=memlen-1){
        if(!(isin_kernel(index+start) && !(isin_kernel(get_res(RES_LN))))){
            if(index+start <= end){
                mem[index+start] = value;
            }
        }
    }
    UINT8 get_mem(UINT64 index, UINT64 start=0, UINT64 end=memlen-1){
        if(index+start <= end){
            return(mem[index+start]);
        }
        else{
            return(0);
        }
    }
    bool isin_kernel(UINT64 adr){
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
    bool run_command(command cmd);
    void run(UINT64 entry0);
    ~VM(){}
};

#include "runners.hpp"

#ifdef vm_template
#undef vm_template
#endif

#endif
