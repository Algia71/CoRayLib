// CoRayLibRenderTexture.cpp
//

#include "CoRayLibRenderTexture.h"
#include "tlhelper.h"


CoRayLibRenderTexture::CoRayLibRenderTexture(HMODULE hModule)
{
    m_cRef = 1;
    m_id = 0;
    m_texture = nullptr;
    m_depth = nullptr;

    LoadTypeInfo(
        hModule,
        IID_IRayLibRenderTexture,
        &m_pTypeInfo
    );
}
CoRayLibRenderTexture::~CoRayLibRenderTexture()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibRenderTexture::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibRenderTexture*>(this);
    }
    else if (riid == IID_IRayLibRenderTexture) {
        *ppvObject = static_cast<IRayLibRenderTexture*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibRenderTexture::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibRenderTexture::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibRenderTexture::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibRenderTexture::GetTypeInfo(
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
STDMETHODIMP CoRayLibRenderTexture::GetIDsOfNames(
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
STDMETHODIMP CoRayLibRenderTexture::Invoke(
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
        static_cast<IRayLibRenderTexture*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibRenderTexture::get_id(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_id;
    return S_OK;
}
STDMETHODIMP CoRayLibRenderTexture::put_id(
    long val
)
{
    m_id = val;
    return S_OK;
}
STDMETHODIMP CoRayLibRenderTexture::get_texture(
    IRayLibTexture** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_texture;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRenderTexture::putref_texture(
    IRayLibTexture* val
)
{
    if (m_texture)
        m_texture->Release();
    m_texture = val;
    if (m_texture)
        m_texture->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRenderTexture::get_depth(
    IRayLibTexture** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_depth;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRenderTexture::putref_depth(
    IRayLibTexture* val
)
{
    if (m_depth)
        m_depth->Release();
    m_depth = val;
    if (m_depth)
        m_depth->AddRef();

    return S_OK;
}
