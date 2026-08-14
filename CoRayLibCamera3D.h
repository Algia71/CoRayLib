// CoRayLibCamera3D.h
//

#ifndef _CORAYLIBCAMERA3D_H
#define _CORAYLIBCAMERA3D_H

#include "CoRayLib_h.h"


class CoRayLibCamera3D : IRayLibCamera3D
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    IRayLibVector3* m_position;
    IRayLibVector3* m_target;
    IRayLibVector3* m_up;
    float m_fovy;
    int m_projection;

public:
    CoRayLibCamera3D(HMODULE hModule);
    ~CoRayLibCamera3D();

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
    STDMETHODIMP put_position(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_target(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP put_target(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_up(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP put_up(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_fovy(
        float* pval
    ) override;
    STDMETHODIMP put_fovy(
        float val
    ) override;
    STDMETHODIMP get_projection(
        long* pval
    ) override;
    STDMETHODIMP put_projection(
        long val
    ) override;
};

#endif // _CORAYLIBCAMERA3D_H
