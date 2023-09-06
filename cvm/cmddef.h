#ifndef _CVM_CMDDEF_H
#define _CVM_CMDDEF_H

typedef enum command_index{
    // mov指令
    mov_itr = 0x1,  // 存数据到默认寄存器
    mov_fm,  // 从内存地址读取数据到默认寄存器
    mov_tm,  // 从默认寄存器读取数据(低8位)，写入到内存地址
    mov_rtr,  // 从寄存器地址读取数据，写入到内存地址

    // 基本数学运算
    l_sal = 0x10,  // 左移运算
    l_sar,  // 右移运算
    l_and,
    l_or,
    l_xor,
    l_not,
    b_add,
    b_sub,
    b_mcl,
    b_div,  // 0x19
} cmd_index;

#endif
