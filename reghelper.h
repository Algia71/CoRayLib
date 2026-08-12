// reghelper.h
//

#ifndef _REGHELPER_H
#define _REGHELPER_H

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


HRESULT DllRegisterClass(
    HMODULE hModule,
    const CLSID& clsid,
    LPCWSTR progId,
    LPCWSTR friendlyName,
    LPCWSTR threadingModel
);

HRESULT DllUnregisterClass(
    const CLSID& clsid,
    LPCWSTR progId
);

#endif // _REGHELPER_H
