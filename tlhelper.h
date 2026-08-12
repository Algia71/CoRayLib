// tlhelper.h
//

#ifndef _TLHELPER_H
#define _TLHELPER_H

#include <objbase.h>


HRESULT LoadTypeInfo(
	HMODULE hModule,
	REFIID riid,
	ITypeInfo** pti
);

#endif // _TLHELPER_H
