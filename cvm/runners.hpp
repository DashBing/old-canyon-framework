#include "vmclass.hpp"
#include "cmddef.h"
#include "datatypedef.h"

#ifndef _CVM_RUNNERS_HPP
#define _CVM_RUNNERS_HPP

#ifndef vm_template
#define vm_template template<UINT16 res_size=16>
#define _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#endif

vm_template
void VM::run_command(command cmd){
    enum cmd_data tmp = cmd.cmd;
    switch (tmp){
    case mov_i8tr:  // 将指令数据中的数据写到寄存器
        set_res_chr();
        break;
    default:
        break;
    }
}

vm_template
void VM::run(UINT64 entry0){
    //
}

#ifdef _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#undef vm_template
#undef _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#endif

#endif
