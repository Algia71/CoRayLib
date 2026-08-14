// CoRayLibCamera2D.h
//

#ifndef _CORAYLIBCAMERA2D_H
#define _CORAYLIBCAMERA2D_H

#include "CoRayLib_h.h"


class CoRayLibCamera2D : IRayLibCamera2D
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    IRayLibVector2* m_offset;
    IRayLibVector2* m_target;
    float m_rotation;
    float m_zoom;

public:
    CoRayLibCamera2D(HMODULE hModule);
    ~CoRayLibCamera2D();

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
    STDMETHODIMP get_offset(
        IRayLibVector2** pval
    ) override;
    STDMETHODIMP putref_offset(
        IRayLibVector2* val
    ) override;
    STDMETHODIMP get_target(
        IRayLibVector2** pval
    ) override;
    STDMETHODIMP putref_target(
        IRayLibVector2* val
    ) override;
    STDMETHODIMP get_rotation(
        float* pval
    ) override;
    STDMETHODIMP put_rotation(
        float val
    ) override;
    STDMETHODIMP get_zoom(
        float* pval
    ) override;
    STDMETHODIMP put_zoom(
        float val
    ) override;
};

#endif // _CORAYLIBCAMERA2D_H
