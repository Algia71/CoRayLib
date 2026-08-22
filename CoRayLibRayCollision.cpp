// CoRayLibRayCollision.cpp
//

#include "CoRayLibRayCollision.h"
#include "tlhelper.h"


CoRayLibRayCollision::CoRayLibRayCollision(HMODULE hModule)
{
    m_cRef = 1;
    m_hit = false;
    m_distance = .0f;
    m_point = nullptr;
    m_normal = nullptr;

    LoadTypeInfo(
        hModule,
        IID_IRayLibRayCollision,
        &m_pTypeInfo
    );
}
CoRayLibRayCollision::~CoRayLibRayCollision()
{
    if (m_point)
        m_point->Release();
    if (m_normal)
        m_normal->Release();
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibRayCollision::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibRayCollision*>(this);
    }
    else if (riid == IID_IRayLibRayCollision) {
        *ppvObject = static_cast<IRayLibRayCollision*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibRayCollision::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibRayCollision::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibRayCollision::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibRayCollision::GetTypeInfo(
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
STDMETHODIMP CoRayLibRayCollision::GetIDsOfNames(
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
STDMETHODIMP CoRayLibRayCollision::Invoke(
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
        static_cast<IRayLibRayCollision*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibColor
STDMETHODIMP CoRayLibRayCollision::get_hit(
    VARIANT_BOOL* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_hit ? VARIANT_TRUE : VARIANT_FALSE;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::put_hit(
    VARIANT_BOOL val
)
{
    m_hit = val == VARIANT_TRUE;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::get_distance(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_distance;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::put_distance(
    float val
)
{
    m_distance = val;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::get_point(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_point;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::putref_point(
    IRayLibVector3* val
)
{
    if (m_point)
        m_point->Release();
    m_point = val;
    if (m_point)
        m_point->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::get_normal(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_normal;
    return S_OK;
}
STDMETHODIMP CoRayLibRayCollision::putref_normal(
    IRayLibVector3* val
)
{
    if (m_normal)
        m_normal->Release();
    m_normal = val;
    if (m_normal)
        m_normal->AddRef();

    return S_OK;
}
