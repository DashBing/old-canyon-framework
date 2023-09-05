#include "types.h"
#include "datatypedef.h"

#ifndef _CVM_VMCLASS_HPP
#define _CVM_VMCLASS_HPP

#ifndef _CVM_template_VM template
#define _CVM_template_VM template <UINT64 mem_size, UINT16 res_size=16, class res_data_type=UINT64>
#endif

_CVM_template_VM
class VM{
    protected:
    public:
    VM();
    ~VM();
};

#endif
