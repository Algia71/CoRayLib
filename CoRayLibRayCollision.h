// CoRayLibRayCollision.h
//

#ifndef _CORAYLIBRAYCOLLISION_H
#define _CORAYLIBRAYCOLLISION_H

#include "CoRayLib_h.h"


class CoRayLibRayCollision : IRayLibRayCollision
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    bool m_hit;
    float m_distance;
    IRayLibVector3* m_point;
    IRayLibVector3* m_normal;

public:
    CoRayLibRayCollision(HMODULE hModule);
    ~CoRayLibRayCollision();

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
    STDMETHODIMP get_hit(
        VARIANT_BOOL* pval
    ) override;
    STDMETHODIMP put_hit(
        VARIANT_BOOL val
    ) override;
    STDMETHODIMP get_distance(
        float* pval
    ) override;
    STDMETHODIMP put_distance(
        float val
    ) override;
    STDMETHODIMP get_point(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_point(
        IRayLibVector3* val
    ) override;
    STDMETHODIMP get_normal(
        IRayLibVector3** pval
    ) override;
    STDMETHODIMP putref_normal(
        IRayLibVector3* val
    ) override;
};

#endif // _CORAYLIBRAYCOLLISION_H
