// CoRayLibRectangle.h
//

#ifndef _CORAYLIBRECTANGLE_H
#define _CORAYLIBRECTANGLE_H

#include "CoRayLib_h.h"


class CoRayLibRectangle : IRayLibRectangle
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    float m_x;
    float m_y;
    float m_width;
    float m_height;

public:
    CoRayLibRectangle(HMODULE hModule);
    ~CoRayLibRectangle();

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
    STDMETHODIMP get_Width(
        float* pval
    ) override;
    STDMETHODIMP put_Width(
        float val
    ) override;
    STDMETHODIMP get_Height(
        float* pval
    ) override;
    STDMETHODIMP put_Height(
        float val
    ) override;
};

#endif // _CORAYLIBVECTOR4_H
