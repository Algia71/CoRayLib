// CoRayLibColor.cpp
//

#include "CoRayLibColor.h"
#include "tlhelper.h"


CoRayLibColor::CoRayLibColor(HMODULE hModule)
{
    m_cRef = 1;
    m_r = 0;
    m_g = 0;
    m_b = 0;
    m_a = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibColor,
        &m_pTypeInfo
    );
}
CoRayLibColor::~CoRayLibColor()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibColor::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibColor*>(this);
    }
    else if (riid == IID_IRayLibColor) {
        *ppvObject = static_cast<IRayLibColor*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibColor::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibColor::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibColor::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibColor::GetTypeInfo(
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
STDMETHODIMP CoRayLibColor::GetIDsOfNames(
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
STDMETHODIMP CoRayLibColor::Invoke(
    DISPID dispIdMember,
    REFIID riid,
    LCID lcid, WORD wFlags,
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
        static_cast<IRayLibColor*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibColor::get_r(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_r;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_r(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_r = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_g(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_g;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_g(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_g = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_b(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_b;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_b(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_b = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_a(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_a;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_a(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_a = val;
    return S_OK;
}
