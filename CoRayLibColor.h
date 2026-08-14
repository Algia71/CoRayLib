// CoRayLibColor.h
//

#ifndef _CORAYLIBCOLOR_H
#define _CORAYLIBCOLOR_H

#include "CoRayLib_h.h"


class CoRayLibColor : IRayLibColor
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    long m_r;
    long m_g;
    long m_b;
    long m_a;

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
    STDMETHODIMP get_r(
        long* pval
    ) override;
    STDMETHODIMP put_r(
        long val
    ) override;
    STDMETHODIMP get_g(
        long* pval
    ) override;
    STDMETHODIMP put_g(
        long val
    ) override;
    STDMETHODIMP get_b(
        long* pval
    ) override;
    STDMETHODIMP put_b(
        long val
    ) override;
    STDMETHODIMP get_a(
        long* pval
    ) override;
    STDMETHODIMP put_a(
        long val
    ) override;
};

#endif // _CORAYLIBCOLOR_H
