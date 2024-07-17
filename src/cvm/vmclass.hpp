#include "types.h"
#include "datatypedef.h"
#include "resdef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

namespace canyon{

static bool prot;  // 是否开保护模式
static uint64_t memlen;  // 内存大小(字节)
static uint64_t prot_res;  // 第一个寄存器(特殊所以分离)
static char * mem;  // 内存地址

class VM{
    public:
    uint64_t res[res_size - 1];  // 寄存器数组, 大小由模板决定
    uint64_t prot_start, prot_end;

    public:
    VM();
    VM(char * mem_i, uint64_t memlen_i);
    VM(uint64_t memlen_i);

    public:
    void clean_res();
    void init();

    public:
    void reset();
    void set_mem_adr(char * mem_i, uint64_t memlen_i);

    public:
    void set_res_chr(uint16_t index, uint8_t value);
    uint8_t get_res_chr(uint16_t index);
    void set_res(uint16_t index, uint64_t value);
    uint64_t get_res(uint16_t index);
    void set_mem(uint64_t index, uint8_t value);
    uint8_t get_mem(uint64_t index);

    public:
    bool isin_kernel(uint64_t adr);
    bool mem_acc_w(uint64_t index);
    bool res_acc_w(uint16_t index);

    public:
    bool run_command(command cmd);
    void run(uint64_t entry0=0);

    public:
    ~VM(){};
};

}

#ifdef cvm_static
#include "fundef.hpp"
#include "runners.hpp"
#endif

#endif
