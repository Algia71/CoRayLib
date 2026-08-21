// CoRayLibBoundingBox.h
//

#ifndef _CORAYLIBBOUNDINGBOX_H
#define _CORAYLIBBOUNDINGBOX_H

#include "CoRayLib_h.h"


class CoRayLibBoundingBox : IRayLibBoundingBox
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    IRayLibVector3* m_min;
    IRayLibVector3* m_max;

public:
    CoRayLibBoundingBox(HMODULE hModule);
    ~CoRayLibBoundingBox();

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
    STDMETHODIMP get_min(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_min(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_max(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_max(
        IRayLibVector3* val
    ) override;
};

#endif // _CORAYLIBBOUNDINGBOX_H
