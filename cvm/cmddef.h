#ifndef _CVM_CMDDEF_H
#define _CVM_CMDDEF_H

typedef enum command_index{
    // mov指令
    mov_itr = 0x1,  // 存数据到默认寄存器
    mov_fm,  // 从内存地址读取数据到默认寄存器
    mov_tm,  // 从默认寄存器读取数据(低8位)，写入到内存地址
    mov_rtr,  // 从寄存器地址读取数据，写入到内存地址

    // 保护模式指令 与 系统调用指令
    set_prot = 0x10,  // 设置保护模式索引表
    jmp_protect,  // 跳转并开始保护
    stop,  // 中断程序 按照中断信息码查询程序使用内核镜像映射的中断处理程序地址
    call,  // 跳转到内核区域的虚拟地址, 控制权交给内核空间, 并暂时转到内核模式

    // 跳转指令
    jmp_ti_if = 0x20,
    jmp_ti_ifn,
    jmp_tr_if,
    jmp_tr_ifn,

    // 基本数学运算
    l_sal = 0x30,  // 左移运算
    l_sar,  // 右移运算
    l_and,
    l_or,
    l_xor,
    l_not,

    c_eq,
    c_high,
    c_low,

    b_add,  // 0x39
    b_sub,
    b_mcl,
    b_div,  // 0x3c
} cmd_index;

#endif
