#ifndef _CVM_CMDDEF_H
#define _CVM_CMDDEF_H

typedef enum command_index{
    // mov指令
    mov_itr = 0x1,  // 存数据到默认寄存器
    mov_fm = 0x2,  // 从内存地址读取数据到默认寄存器
    mov_tm = 0x3,  // 从默认寄存器读取数据(低8位)，写入到内存地址
    mov_rtr = 0x4,  // 从寄存器地址读取数据，写入到内存地址

    // 基本数学运算
    l_sal = 0x10,  // 左移运算
    l_sar = 0x11,  // 右移运算
    l_and = 0x12,
    l_or = 0x13,
    l_xor = 0x14,
    l_not = 0x15,
    b_add = 0x16,
    b_sub = 0x17,
    b_mcl = 0x18,
    b_div = 0x19,
} cmd_index;

#endif
