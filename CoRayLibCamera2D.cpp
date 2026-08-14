// CoRayLibCamera2D.cpp
//

#include "CoRayLibCamera2D.h"
#include "tlhelper.h"


CoRayLibCamera2D::CoRayLibCamera2D(HMODULE hModule)
{
    m_cRef = 1;
    m_offset = NULL;
    m_target = NULL;
    m_rotation = 0;
    m_zoom = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibCamera2D,
        &m_pTypeInfo
    );
}
CoRayLibCamera2D::~CoRayLibCamera2D()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
    if (m_offset)
        m_offset->Release();
    if (m_target)
        m_target->Release();
}

// IUnknown
STDMETHODIMP CoRayLibCamera2D::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibCamera2D*>(this);
    }
    else if (riid == IID_IRayLibColor) {
        *ppvObject = static_cast<IRayLibCamera2D*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibCamera2D::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibCamera2D::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibCamera2D::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibCamera2D::GetTypeInfo(
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
STDMETHODIMP CoRayLibCamera2D::GetIDsOfNames(
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
STDMETHODIMP CoRayLibCamera2D::Invoke(
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
        static_cast<IRayLibCamera2D*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibCamera2D
STDMETHODIMP CoRayLibCamera2D::get_offset(
    IRayLibVector2** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_offset;
    if(*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::putref_offset(
    IRayLibVector2* val
)
{
    if (m_offset)
        m_offset->Release();
    m_offset = val;
    if (m_offset)
        m_offset->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::get_target(
    IRayLibVector2** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_target;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::putref_target(
    IRayLibVector2* val
)
{
    if (m_target)
        m_target->Release();
    m_target = val;
    if (m_target)
        m_target->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::get_rotation(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_rotation;
    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::put_rotation(
    float val
)
{
    m_rotation = val;
    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::get_zoom(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_zoom;
    return S_OK;
}
STDMETHODIMP CoRayLibCamera2D::put_zoom(
    float val
)
{
    m_zoom = val;
    return S_OK;
}
