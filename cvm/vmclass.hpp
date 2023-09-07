#include "types.h"
#include "datatypedef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

#define res_len_type UINT16

#ifndef _CVM_template_VM
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
    void set_res(UINT16 index, UINT8 value){
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
    char get_mem_chr(){}
    void run_command();
    void run(UINT64 entry0);
};

#undef res_len_type
#undef vm_template

#endif
