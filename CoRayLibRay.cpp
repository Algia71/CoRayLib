// CoRayLibRay.cpp
//

#include "CoRayLibRay.h"
#include "tlhelper.h"


CoRayLibRay::CoRayLibRay(HMODULE hModule)
{
    m_cRef = 1;
    m_position = NULL;
    m_direction = NULL;

    LoadTypeInfo(
        hModule,
        IID_IRayLibRay,
        &m_pTypeInfo
    );
}
CoRayLibRay::~CoRayLibRay()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
    if (m_position)
        m_position->Release();
    if (m_direction)
        m_direction->Release();
}

// IUnknown
STDMETHODIMP CoRayLibRay::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibRay*>(this);
    }
    else if (riid == IID_IRayLibCamera2D) {
        *ppvObject = static_cast<IRayLibRay*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibRay::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibRay::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibRay::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibRay::GetTypeInfo(
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
STDMETHODIMP CoRayLibRay::GetIDsOfNames(
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
STDMETHODIMP CoRayLibRay::Invoke(
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
        static_cast<IRayLibRay*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibCamera2D
STDMETHODIMP CoRayLibRay::get_position(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_position;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRay::putref_position(
    IRayLibVector3* val
)
{
    if (m_position)
        m_position->Release();
    m_position = val;
    if (m_position)
        m_position->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRay::get_direction(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_direction;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibRay::putref_direction(
    IRayLibVector3* val
)
{
    if (m_direction)
        m_direction->Release();
    m_direction = val;
    if (m_direction)
        m_direction->AddRef();

    return S_OK;
}
