#include "types.h"
#include "datatypedef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

//#define res_len_type UINT16

#ifndef vm_template
#define vm_template template<UINT16 res_size=16>
#endif

vm_template
class VM{
    public:
    static bool prot;
    static UINT64 memlen;
    static UINT64 prot_res;
    UINT64 res[res_size - 1];
    static char * mem;
    public:
    VM(){}
    VM(char * mem_i, UINT64 memlen_i){
        set_mem(mem_i, memlen_i);
    }
    VM(UINT64 memlen_i){
        mem = (char *)calloc(memlen_i, sizeof(char));
    }
    void reset(){
        prot = 0;
        memlen = 0;
        prot_res = 0;
        res = {};
        mem = 0;
    }
    void set_mem(char * mem_i, UINT64 memlen_i){
        mem = mem_i;
        memlen = memlen_i;
    }
    void set_res_chr(UINT16 index, UINT8 value){
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
    UINT8 get_mem_chr(UINT16 index){
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
    void set_res(UINT16 index, UINT64 value){
        index = index / 8;
        if(index == 0){
            prot_res = value;
        }
        else{
            res[index - 1] = value;
        }
    }
    UINT64 get_res(UINT16 index){
        index = index / 8;
        if(index == 0){
            return(prot_res);
        }
        else{
            return(res[index]);
        }
    }
    void run_command();
    void run(UINT64 entry0);
};

//#undef res_len_type
#undef vm_template

#endif
