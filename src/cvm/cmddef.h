#include "types.h"

#ifndef _CVM_CMDDEF_H
#define _CVM_CMDDEF_H

namespace canyon{

typedef enum command_index : uint16_t{
    null = 0x0,
    // mov指令
    mov_i8tr = 0x1,  // 存数据到默认寄存器
    mov_i64tr,
    mov_fm,  // 从内存地址读取数据到默认寄存器
    mov_tm,  // 从默认寄存器读取数据(低8位)，写入到内存地址
    mov_r8tr,  // 从寄存器地址读取数据，写入到内存地址
    mov_r8tr_if,
    mov_r8tr_ifn,
    mov_r64tr,
    mov_r64tr_if,
    mov_r64tr_ifn,
    mov_rmtr,
    mov_rmtr_if,
    mov_rmtr_ifn,
    mov_rtrm,
    mov_rtrm_if,
    mov_rtrm_ifn,

    // 保护模式指令 与 系统调用指令
    set_prot,  // 设置保护模式索引表
    jmp_prot,  // 跳转并开始保护
    stop_prot,  // 终止保护模式
    stop_pg,  // 中断程序 按照中断信息码查询程序使用内核镜像映射的中断处理程序地址
    stop,  // 停止运行
    sys,  // 跳转到内核区域的虚拟地址, 控制权交给内核空间, 并暂时转到内核模式

    // 跳转指令
    jmp_ti,
    jmp_ti_if,
    jmp_ti_ifn,
    jmp_tr,
    jmp_tr_if,
    jmp_tr_ifn,
    jmp_tm,
    jmp_tm_if,
    jmp_tm_ifn,

    // 基本数学运算
    l_sal8 = 0x20,  // 左移运算
    l_sal64,
    l_sar8,  // 右移运算
    l_sar64,

    l_and,
    l_or,
    l_xor,
    l_not,

    c_eq8,
    c_eq64,
    c_high8,
    c_high64,
    c_low8,
    c_low64,

    b_add8,
    b_add64,
    b_sub8,
    b_sub64,
    b_mcl8,
    b_mcl64,
    b_div8,
    b_div64,

    // 基本io控制
    io_im = 0x40,
    io_ir,
    io_irm,
    io_oi8,
    io_oi64,
    io_or8,
    io_or64,
    io_om,
} cmd_index;

}

#endif
