#include "types.h"
#include "datatypedef.h"
#include "vm_template.hpp"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

static bool prot;  // 是否开保护模式
static UINT64 memlen;  // 内存大小(字节)
static UINT64 prot_res;  // 第一个寄存器(特殊所以分离)
static char * mem;  // 内存地址

vm_template
class VM{
    public:
    UINT64 res[res_size - 1];  // 寄存器数组, 大小由模板决定
    UINT64 prot_start, prot_end;
    public:
    VM();
    VM(char * mem_i, UINT64 memlen_i);
    VM(UINT64 memlen_i);
    void clean_res();
    void init();
    void reset();
    void set_mem_adr(char * mem_i, UINT64 memlen_i);
    void set_res_chr(UINT16 index, UINT8 value);
    UINT8 get_res_chr(UINT16 index);
    void set_res(UINT16 index, UINT64 value);
    UINT64 get_res(UINT16 index);
    void set_mem(UINT64 index, UINT8 value);
    UINT8 get_mem(UINT64 index);
    bool isin_kernel(UINT64 adr);
    bool mem_acc_w(UINT64 index);
    bool res_acc_w(UINT16 index);
    bool run_command(command cmd);
    void run(UINT64 entry0=0);
    ~VM(){};
};

typedef VM<16> VMBasic;

#ifdef cvm_static
#include "fundef.hpp"
#include "runners.hpp"
#endif

#endif
