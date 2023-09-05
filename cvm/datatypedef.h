#include "types.h"

#ifndef _CVM_DATATYPEDEF_H
#define _CVM_DATATYPEDEF_H
#pragma pack(1)

union cmddata{  // 共用区域定义
    UINT16 res;       // 寄存器地址
    UINT64 mem;   // 内存地址
    UINT8 data8;
    UINT16 data16;
    UINT32 data32;
    UINT64 data64;  // 数据
};

struct command{
    UINT16 cmd;  // 命令
    UINT16 res;  // 寄存器地址
    cmddata data;        // 寄存器地址2||内存地址||数据 共用一块区域
};

#pragma pack()
#endif
