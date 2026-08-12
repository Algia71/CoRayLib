// CoRayLibVector4.h
//

#ifndef _CORAYLIBVECTOR4_H
#define _CORAYLIBVECTOR4_H

#include "CoRayLib_h.h"


class CoRayLibVector4 : IRayLibVector4
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    float m_x;
    float m_y;
    float m_z;
    float m_w;

public:
    CoRayLibVector4(HMODULE hModule);
    ~CoRayLibVector4();

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
        LCID lcid,
        WORD wFlags,
        DISPPARAMS* pDispParams,
        VARIANT* pVarResult,
        EXCEPINFO* pExcepInfo,
        UINT* puArgErr
    ) override;

    // IRayLibColor
    STDMETHODIMP get_x(
        float* pval
    ) override;
    STDMETHODIMP put_x(
        float val
    ) override;
    STDMETHODIMP get_y(
        float* pval
    ) override;
    STDMETHODIMP put_y(
        float val
    ) override;
    STDMETHODIMP get_z(
        float* pval
    ) override;
    STDMETHODIMP put_z(
        float val
    ) override;
    STDMETHODIMP get_w(
        float* pval
    ) override;
    STDMETHODIMP put_w(
        float val
    ) override;
};

#endif // _CORAYLIBVECTOR4_H
