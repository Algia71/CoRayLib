// CoRayLibColor.cpp
//

#include "CoRayLibColor.h"
#include "tlhelper.h"


CoRayLibColor::CoRayLibColor(HMODULE hModule)
{
    m_cRef = 1;
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_alpha = 0;

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
STDMETHODIMP CoRayLibColor::get_Red(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_red;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_Red(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_red = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_Green(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_green;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_Green(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_green = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_Blue(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_blue;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_Blue(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_blue = val;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::get_Alpha(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_alpha;
    return S_OK;
}
STDMETHODIMP CoRayLibColor::put_Alpha(
    long val
)
{
    if ((val < 0) || (val > 255))
        return E_INVALIDARG;

    m_alpha = val;
    return S_OK;
}
