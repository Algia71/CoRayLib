// tlhelper.cpp
//

#include "tlhelper.h"


HRESULT LoadTypeInfo(
	HMODULE hModule,
    REFIID riid,
	ITypeInfo** pti
)
{
    *pti = NULL;

    wchar_t szModulePath[MAX_PATH];
    DWORD len = GetModuleFileNameW(hModule, szModulePath, MAX_PATH);
    if (len == 0 || len == MAX_PATH)
        return HRESULT_FROM_WIN32(GetLastError());

    ITypeLib* ptl = NULL;
    HRESULT hr = LoadTypeLib(
        szModulePath,
        &ptl
    );
    if (SUCCEEDED(hr)) {
        hr = ptl->GetTypeInfoOfGuid(
            riid,
            pti
        );
        ptl->Release();
    }
    return hr;
}
