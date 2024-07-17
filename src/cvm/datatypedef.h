#include "types.h"

#ifndef _CVM_DATATYPEDEF_H
#define _CVM_DATATYPEDEF_H

namespace canyon{

#pragma pack(push, 1)

typedef struct cmd_two_res{  // 用于同时存储两个寄存器地址的结构体
    uint16_t a;  // 寄存器A
    uint16_t b;  // 寄存器B
    uint16_t c;
} cmd_resAB;

typedef struct data64p8{
    uint8_t I0;
    uint8_t I1;
    uint8_t I2;
    uint8_t I3;
    uint8_t I4;
    uint8_t I5;
    uint8_t I6;
    uint8_t I7;
} datas_type;

typedef union cmd_union_data{  // 共用区域定义
    uint8_t data8;  // 8位数据
    cmd_two_res res;   // 寄存器地址
    datas_type datas;
    uint64_t mem;   // 内存地址
    uint64_t data64;  // 64位数据
} cmd_data;

typedef struct command_data{
    uint16_t cmd;  // 命令
    cmd_union_data data;        // 寄存器地址2||内存地址||数据 共用一块区域
} command;

#pragma pack(pop)

}

#endif
