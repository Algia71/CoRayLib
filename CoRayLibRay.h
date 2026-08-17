// CoRayLibRay.h
//

#ifndef _CORAYLIBRAY_H
#define _CORAYLIBRAY_H

#include "CoRayLib_h.h"


class CoRayLibRay : IRayLibRay
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    IRayLibVector3* m_position;
    IRayLibVector3* m_direction;

public:
    CoRayLibRay(HMODULE hModule);
    ~CoRayLibRay();

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
        LCID lcid, WORD wFlags,
        DISPPARAMS* pDispParams,
        VARIANT* pVarResult,
        EXCEPINFO* pExcepInfo,
        UINT* puArgErr
    ) override;

    // IRayLibColor
    STDMETHODIMP get_position(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_position(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_direction(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_direction(
        IRayLibVector3* val
    ) override;
};

#endif // _CORAYLIBRAY_H
