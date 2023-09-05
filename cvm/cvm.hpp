#ifndef _CVM_HPP
#define _CVM_HPP

#pragma pack(1)
union cmddata{  // 共用区域定义
    unsigned short res;       // 寄存器地址
    unsigned long long mem;   // 内存地址
    unsigned long long data;  // 数据
};

struct command{
    unsigned short cmd;  // 命令
    unsigned short res;  // 寄存器地址
    cmddata data;        // 寄存器地址2||内存地址||数据 共用一块区域
};
#pragma pack()

class VM{
    public:
    
};

#endif
