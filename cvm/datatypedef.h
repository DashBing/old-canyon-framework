#include "types.h"

#ifndef _CVM_DATATYPEDEF_H
#define _CVM_DATATYPEDEF_H
#pragma pack(1)

typedef struct cmd_two_res{
    UINT16 a;
    UINT16 b;
} cmd_resAB;

typedef union cmd_union_data{  // 共用区域定义
    cmd_two_res res;   // 寄存器地址
    UINT64 mem;   // 内存地址
    UINT64 data;  // 数据
} cmd_data;

typedef struct command_data{
    UINT16 cmd;  // 命令
    cmd_union_data data;        // 寄存器地址2||内存地址||数据 共用一块区域
} command;

#pragma pack()
#endif
