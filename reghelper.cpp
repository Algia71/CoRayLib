// reghelper.cpp
//

#include <objbase.h>
#include <stdio.h>
#include "reghelper.h"


static LSTATUS SetDefaultValue(
    const wchar_t* pszKey,
    const wchar_t* pszValue
)
{
    HKEY hKey = nullptr;
    LSTATUS ls = RegCreateKeyExW(HKEY_CLASSES_ROOT, pszKey, 0, nullptr,
        REG_OPTION_NON_VOLATILE, KEY_WRITE, nullptr,
        &hKey, nullptr);
    if (ls != ERROR_SUCCESS)
        return ls;

    ls = RegSetValueExW(hKey, nullptr, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(pszValue),
        static_cast<DWORD>((wcslen(pszValue) + 1) * sizeof(wchar_t)));
    RegCloseKey(hKey);
    return ls;
}

static LSTATUS SetNamedValue(
    const wchar_t* pszKey,
    const wchar_t* pszValueName,
    const wchar_t* pszValue
)
{
    HKEY hKey = nullptr;
    LSTATUS ls = RegCreateKeyExW(HKEY_CLASSES_ROOT, pszKey, 0, nullptr,
        REG_OPTION_NON_VOLATILE, KEY_WRITE, nullptr,
        &hKey, nullptr);
    if (ls != ERROR_SUCCESS)
        return ls;

    ls = RegSetValueExW(hKey, pszValueName, 0, REG_SZ,
        reinterpret_cast<const BYTE*>(pszValue),
        static_cast<DWORD>((wcslen(pszValue) + 1) * sizeof(wchar_t)));
    RegCloseKey(hKey);
    return ls;
}

static bool GuidToString(
    REFGUID guid,
    wchar_t(&buffer)[64]
)
{
    return StringFromGUID2(guid, buffer, 64) > 0;
}

HRESULT DllRegisterClass(
    HMODULE hModule,
    const CLSID& clsid,
    LPCWSTR progId,
    LPCWSTR friendlyName,
    LPCWSTR threadingModel
)
{
    wchar_t szModulePath[MAX_PATH];
    DWORD len = GetModuleFileNameW(hModule, szModulePath, MAX_PATH);
    if (len == 0 || len == MAX_PATH)
        return HRESULT_FROM_WIN32(GetLastError());

    wchar_t szClsid[64];
    if (!GuidToString(clsid, szClsid))
        return E_UNEXPECTED;

    wchar_t szClsidKey[128];
    swprintf_s(szClsidKey, L"CLSID\\%s", szClsid);

    wchar_t szInprocKey[160];
    swprintf_s(szInprocKey, L"CLSID\\%s\\InprocServer32", szClsid);

    wchar_t szProgIdKey[160];
    swprintf_s(szProgIdKey, L"CLSID\\%s\\ProgID", szClsid);

    wchar_t szProgIdClsidKey[128];
    swprintf_s(szProgIdClsidKey, L"%s\\CLSID", progId);

    LSTATUS ls;

    ls = SetDefaultValue(szClsidKey, friendlyName);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    ls = SetDefaultValue(szInprocKey, szModulePath);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    ls = SetNamedValue(szInprocKey, L"ThreadingModel", threadingModel);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    ls = SetDefaultValue(szProgIdKey, progId);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    ls = SetDefaultValue(progId, friendlyName);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    ls = SetDefaultValue(szProgIdClsidKey, szClsid);
    if (ls != ERROR_SUCCESS) return HRESULT_FROM_WIN32(ls);

    return S_OK;
}

HRESULT DllUnregisterClass(
    const CLSID& clsid,
    LPCWSTR progId
)
{
    wchar_t szClsid[64];
    if (!GuidToString(clsid, szClsid))
        return E_UNEXPECTED;

    wchar_t szClsidKey[128];
    swprintf_s(szClsidKey, L"CLSID\\%s", szClsid);

    RegDeleteTreeW(HKEY_CLASSES_ROOT, szClsidKey);
    RegDeleteTreeW(HKEY_CLASSES_ROOT, progId);

    return S_OK;
}
