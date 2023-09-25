#ifndef _CVM_DLLEXPORT_H
#define _CVM_DLLEXPORT_H
#ifdef cvm_static
#define TEMPLATE_EXPORT
#else
#ifdef DLL_EXPORT
#define TEMPLATE_EXPORT __declspec(dllexport)
#else
#define TEMPLATE_EXPORT __declspec(dllimport)
#endif
#endif
#endif
