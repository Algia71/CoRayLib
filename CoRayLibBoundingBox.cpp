// CoRayLibBoundingBox.cpp
//

#include "CoRayLibBoundingBox.h"
#include "tlhelper.h"


CoRayLibBoundingBox::CoRayLibBoundingBox(HMODULE hModule)
{
    m_cRef = 1;
    m_min = nullptr;
    m_max = nullptr;

    LoadTypeInfo(
        hModule,
        IID_IRayLibBoundingBox,
        &m_pTypeInfo
    );
}
CoRayLibBoundingBox::~CoRayLibBoundingBox()
{
    if (m_min)
        m_min->Release();
    if (m_max)
        m_max->Release();
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibBoundingBox::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibBoundingBox*>(this);
    }
    else if (riid == IID_IRayLibBoundingBox) {
        *ppvObject = static_cast<IRayLibBoundingBox*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibBoundingBox::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibBoundingBox::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibBoundingBox::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibBoundingBox::GetTypeInfo(
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
STDMETHODIMP CoRayLibBoundingBox::GetIDsOfNames(
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
STDMETHODIMP CoRayLibBoundingBox::Invoke(
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
        static_cast<IRayLibBoundingBox*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibBoundingBox::get_min(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_min;
    return S_OK;
}
STDMETHODIMP CoRayLibBoundingBox::putref_min(
    IRayLibVector3* val
)
{
    if (m_min)
        m_min->Release();
    m_min = val;
    if (m_min)
        m_min->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibBoundingBox::get_max(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_max;
    return S_OK;
}
STDMETHODIMP CoRayLibBoundingBox::putref_max(
    IRayLibVector3* val
)
{
    if (m_max)
        m_max->Release();
    m_max = val;
    if (m_max)
        m_max->AddRef();

    return S_OK;
}
