// CoRayLibColor.h
//

#ifndef _CORAYLIBCOLOR_H
#define _CORAYLIBCOLOR_H

#include "CoRayLib_h.h"


class CoRayLibColor : IRayLibColor
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    long m_red;
    long m_green;
    long m_blue;
    long m_alpha;

public:
	CoRayLibColor(HMODULE hModule);
	~CoRayLibColor();

    // IUnknown
    STDMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObject
    ) override;
    STDMETHODIMP_(ULONG) AddRef(
        void
    ) override;
    STDMETHODIMP_(ULONG) Release(
        void
    ) override;

    // IDispatch
    STDMETHODIMP GetTypeInfoCount(
        UINT* pctinfo
    ) override;
    STDMETHODIMP GetTypeInfo(
        UINT iTInfo,
        LCID lcid,
        ITypeInfo** ppTInfo
    ) override;
    STDMETHODIMP GetIDsOfNames(
        REFIID riid,
        LPOLESTR* rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID* rgDispId
    ) override;
    STDMETHODIMP Invoke(
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid,WORD wFlags,
        DISPPARAMS* pDispParams,
        VARIANT* pVarResult,
        EXCEPINFO* pExcepInfo,
        UINT* puArgErr
    ) override;

    // IRayLibColor
    STDMETHODIMP get_Red(
        long* pval
    ) override;
    STDMETHODIMP put_Red(
        long val
    ) override;
    STDMETHODIMP get_Green(
        long* pval
    ) override;
    STDMETHODIMP put_Green(
        long val
    ) override;
    STDMETHODIMP get_Blue(
        long* pval
    ) override;
    STDMETHODIMP put_Blue(
        long val
    ) override;
    STDMETHODIMP get_Alpha(
        long* pval
    ) override;
    STDMETHODIMP put_Alpha(
        long val
    ) override;
};

#endif // _CORAYLIBCOLOR_H
