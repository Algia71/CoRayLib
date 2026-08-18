// CoRayLibTexture.h
//

#ifndef _CORAYLIBTEXTURE_H
#define _CORAYLIBTEXTURE_H

#include "CoRayLib_h.h"


class CoRayLibTexture : IRayLibTexture
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    long m_id;
    long m_width;
    long m_height;
    long m_mipmaps;
    long m_format;

public:
    CoRayLibTexture(HMODULE hModule);
    ~CoRayLibTexture();

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
    STDMETHODIMP get_width(
        long* pval
    ) override;
    STDMETHODIMP put_width(
        long val
    ) override;
    STDMETHODIMP get_height(
        long* pval
    ) override;
    STDMETHODIMP put_height(
        long val
    ) override;
    STDMETHODIMP get_mipmaps(
        long* pval
    ) override;
    STDMETHODIMP put_mipmaps(
        long val
    ) override;
    STDMETHODIMP get_format(
        long* pval
    ) override;
    STDMETHODIMP put_format(
        long val
    ) override;
};

#endif // _CORAYLIBTEXTURE_H
