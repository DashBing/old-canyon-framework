#include "vmclass.hpp"
#include "cmddef.h"
#include "datatypedef.h"
#include "resdef.h"

#ifndef _CVM_RUNNERS_HPP
#define _CVM_RUNNERS_HPP

#ifndef vm_template
#define vm_template template<UINT16 res_size=16>
#define _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#endif

vm_template
void VM<res_size>::run_command(command cmd){
    enum cmd_data tmp = cmd.cmd;
    switch (tmp){

    case mov_i8tr:  // 将指令数据中的数据写到寄存器
        set_res_chr(RES_DE, cmd.data.data8);
        break;
    case mov_i64tr:
        set_res(RES_DE, cmd.data.data64);
        break;
    case mov_fm:  // 将内存数据写到寄存器
        set_res_chr(RES_DE, get_mem(cmd.data.mem));
        break;
    case mov_tm:  // 将默认寄存器的数据写到内存
        set_mem(cmd.data.mem, get_res_chr(RES_DE));
        break;
    case mov_r8tr:
        set_res_chr(cmd.data.res.b, get_res_chr(cmd.data.res.a));
        break;
    case mov_r64tr:
        set_res(cmd.data.res.b, get_res(cmd.data.res.a));
        break;



    case jmp_ti_if:
        if(get_res(RES_DE)){
            set_res(RES_LN, cmd.data.data64);
        }
        break;
    case jmp_ti_ifn:
        if(!(get_res(RES_DE))){
            set_res(RES_LN, cmd.data.data64);
        }
        break;
    case jmp_tr_if:
        if(get_res(cmd.data.res.a)){
            set_res(RES_LN, cmd.data.res.b);
        }
        break;
    case jmp_tr_ifn:
        if(!(get_res(cmd.data.res.a))){
            set_res(RES_LN, cmd.data.res.b);
        }
        break;
    case jmp_tm_if:
        if(get_res(RES_DE)){
            set_res(RES_LN, get_mem(cmd.data.mem));
        }
        break;
    case jmp_tm_ifn:
        if(!(get_res(RES_DE))){
            set_res(RES_LN, get_mem(cmd.data.mem));
        }
        break;



    case l_sal8:
        set_res_chr(RES_DE, get_res_chr(cmd.data.res.a)<<get_res_chr(cmd.data.res.b));
        break;
    case l_sal64:
        set_res(RES_DE, get_res(cmd.data.res.a)<<get_res_chr(cmd.data.res.b));
        break;

    default:
        break;
    }
}

vm_template
void VM<res_size>::run(UINT64 entry0){
    //
}

#ifdef _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#undef vm_template
#undef _CVM_RUNNERS_HPP_INLINEDEF_VM_TEMP
#endif

#endif
