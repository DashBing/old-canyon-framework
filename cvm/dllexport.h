#ifndef _CVM_DLLEXPORT_H
#define _CVM_DLLEXPORT_H
#ifdef cvm_static
#define TEMPLATE_EXPORT
#else
#define TEMPLATE_EXPORT __declspec(dllexport)
#endif
#endif
