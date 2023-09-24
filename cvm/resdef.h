#ifndef _CVM_RESDEF_H
#define _CVM_RESDEF_H

#define RES_RN(n) ((n)*8)
#define RES_RN_DE(n) (((n)-(n)%8)/8)

#define RES_PR RES_RN(0)
#define RES_LN RES_RN(1)
#define RES_DE RES_RN(2)

#endif
