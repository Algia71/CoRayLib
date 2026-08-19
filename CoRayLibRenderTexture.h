// CoRayLibRenderTexture.h
//

#ifndef _CORAYLIBRENDERTEXTURE_H
#define _CORAYLIBRENDERTEXTURE_H

#include "CoRayLib_h.h"


class CoRayLibRenderTexture : IRayLibRenderTexture
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    long m_id;
    IRayLibTexture* m_texture;
    IRayLibTexture* m_depth;

public:
    CoRayLibRenderTexture(HMODULE hModule);
    ~CoRayLibRenderTexture();

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
    STDMETHODIMP get_id(
        long* pval
    ) override;
    STDMETHODIMP put_id(
        long val
    ) override;
    STDMETHODIMP get_texture(
        IRayLibTexture** pval
    ) override;
    STDMETHODIMP putref_texture(
        IRayLibTexture* val
    ) override;
    STDMETHODIMP get_depth(
        IRayLibTexture** pval
    ) override;
    STDMETHODIMP putref_depth(
        IRayLibTexture* val
    ) override;
};

#endif // _CORAYLIBRENDERTEXTURE_H
