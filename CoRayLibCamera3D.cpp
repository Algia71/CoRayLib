// CoRayLibCamera3D.cpp
//

#include "CoRayLibCamera3D.h"
#include "tlhelper.h"


CoRayLibCamera3D::CoRayLibCamera3D(HMODULE hModule)
{
    m_cRef = 1;
    m_position = NULL;
    m_target = NULL;
    m_up = NULL;
    m_fovy = 0;
    m_projection = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibCamera3D,
        &m_pTypeInfo
    );
}
CoRayLibCamera3D::~CoRayLibCamera3D()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
    if (m_position)
        m_position->Release();
    if (m_target)
        m_target->Release();
    if (m_up)
        m_up->Release();
}

// IUnknown
STDMETHODIMP CoRayLibCamera3D::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibCamera3D*>(this);
    }
    else if (riid == IID_IRayLibColor) {
        *ppvObject = static_cast<IRayLibCamera3D*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibCamera3D::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibCamera3D::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibCamera3D::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibCamera3D::GetTypeInfo(
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
STDMETHODIMP CoRayLibCamera3D::GetIDsOfNames(
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
STDMETHODIMP CoRayLibCamera3D::Invoke(
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
        static_cast<IRayLibCamera3D*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibCamera2D
STDMETHODIMP CoRayLibCamera3D::get_position(
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
STDMETHODIMP CoRayLibCamera3D::putref_position(
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
STDMETHODIMP CoRayLibCamera3D::get_target(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_target;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::putref_target(
    IRayLibVector3* val
)
{
    if (m_target)
        m_target->Release();
    m_target = val;
    if (m_target)
        m_target->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::get_up(
    IRayLibVector3** pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_up;
    if (*pval)
        (*pval)->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::putref_up(
    IRayLibVector3* val
)
{
    if (m_up)
        m_up->Release();
    m_up = val;
    if (m_up)
        m_up->AddRef();

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::get_fovy(
    float* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_fovy;

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::put_fovy(
    float val
)
{
    m_fovy = val;

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::get_projection(
    long* pval
)
{
    if (!pval)
        return E_POINTER;

    *pval = m_projection;

    return S_OK;
}
STDMETHODIMP CoRayLibCamera3D::put_projection(
    long val
)
{
    m_projection = val;

    return S_OK;
}
