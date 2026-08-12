// CoRayLibVector2.cpp
//

#include "CoRayLibVector2.h"
#include "tlhelper.h"


CoRayLibVector2::CoRayLibVector2(HMODULE hModule)
{
    m_cRef = 1;
    m_x = 0;
    m_y = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibVector2,
        &m_pTypeInfo
    );
}
CoRayLibVector2::~CoRayLibVector2()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibVector2::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibVector2*>(this);
    }
    else if (riid == IID_IRayLibVector2) {
        *ppvObject = static_cast<IRayLibVector2*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibVector2::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibVector2::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibVector2::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibVector2::GetTypeInfo(
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
STDMETHODIMP CoRayLibVector2::GetIDsOfNames(
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
STDMETHODIMP CoRayLibVector2::Invoke(
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
        static_cast<IRayLibVector2*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibVector2::get_x(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_x;
    return S_OK;
}
STDMETHODIMP CoRayLibVector2::put_x(
    float val
)
{
    m_x = val;
    return S_OK;
}
STDMETHODIMP CoRayLibVector2::get_y(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_y;
    return S_OK;
}
STDMETHODIMP CoRayLibVector2::put_y(
    float val
)
{
    m_y = val;
    return S_OK;
}
