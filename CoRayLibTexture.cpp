// CoRayLibTexture.cpp
//

#include "CoRayLibTexture.h"
#include "tlhelper.h"


CoRayLibTexture::CoRayLibTexture(HMODULE hModule)
{
    m_cRef = 1;
    m_id = 0;
    m_width = 0;
    m_height = 0;
    m_mipmaps = 0;
    m_format = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibTexture,
        &m_pTypeInfo
    );
}
CoRayLibTexture::~CoRayLibTexture()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibTexture::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibTexture*>(this);
    }
    else if (riid == IID_IRayLibRectangle) {
        *ppvObject = static_cast<IRayLibTexture*>(this);
    }
    else if (riid == IID_IDispatch) {
        *ppvObject = static_cast<IDispatch*>(this);
    }
    else {
        *ppvObject = nullptr;
        return E_NOINTERFACE;
    }

    AddRef();
    return S_OK;
}
STDMETHODIMP_(ULONG) CoRayLibTexture::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibTexture::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibTexture::GetTypeInfoCount(
    UINT* pctinfo
)
{
    if (!pctinfo)
        return E_POINTER;

    if (!m_pTypeInfo)
        return E_ABORT;

    *pctinfo = 1;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::GetTypeInfo(
    UINT iTInfo,
    LCID lcid,
    ITypeInfo** ppTInfo
)
{
    if (!ppTInfo)
        return E_POINTER;

    if (!m_pTypeInfo)
        return E_ABORT;

    *ppTInfo = m_pTypeInfo;
    (*ppTInfo)->AddRef();
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::GetIDsOfNames(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgDispId
)
{
    if (riid != IID_NULL)
        return DISP_E_UNKNOWNINTERFACE;

    if (!m_pTypeInfo)
        return E_ABORT;

    return m_pTypeInfo->GetIDsOfNames(
        rgszNames,
        cNames,
        (MEMBERID*)rgDispId
    );
}
STDMETHODIMP CoRayLibTexture::Invoke(
    DISPID dispIdMember,
    REFIID riid,
    LCID lcid,
    WORD wFlags,
    DISPPARAMS* pDispParams,
    VARIANT* pVarResult,
    EXCEPINFO* pExcepInfo,
    UINT* puArgErr
)
{
    if (riid != IID_NULL)
        return DISP_E_UNKNOWNINTERFACE;

    if (!m_pTypeInfo)
        return E_ABORT;

    return m_pTypeInfo->Invoke(
        static_cast<IRayLibTexture*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibTexture::get_id(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_id;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::put_id(
    long val
)
{
    m_id = val;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::get_width(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_width;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::put_width(
    long val
)
{
    m_width = val;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::get_height(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_height;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::put_height(
    long val
)
{
    m_height = val;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::get_mipmaps(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_mipmaps;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::put_mipmaps(
    long val
)
{
    m_mipmaps = val;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::get_format(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_format;
    return S_OK;
}
STDMETHODIMP CoRayLibTexture::put_format(
    long val
)
{
    m_format = val;
    return S_OK;
}
