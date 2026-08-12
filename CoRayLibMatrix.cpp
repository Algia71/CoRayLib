// CoRayLibMatrix.cpp
//

#include "CoRayLibMatrix.h"
#include "tlhelper.h"


CoRayLibMatrix::CoRayLibMatrix(HMODULE hModule)
{
    m_cRef = 1;
    m_m0 = 0;
    m_m1 = 0;
    m_m2 = 0;
    m_m3 = 0;
    m_m4 = 0;
    m_m5 = 0;
    m_m6 = 0;
    m_m7 = 0;
    m_m8 = 0;
    m_m9 = 0;
    m_m10 = 0;
    m_m11 = 0;
    m_m12 = 0;
    m_m13 = 0;
    m_m14 = 0;
    m_m15 = 0;

    LoadTypeInfo(
        hModule,
        IID_IRayLibVector2,
        &m_pTypeInfo
    );
}
CoRayLibMatrix::~CoRayLibMatrix()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLibMatrix::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLibMatrix*>(this);
    }
    else if (riid == IID_IRayLibVector2) {
        *ppvObject = static_cast<IRayLibMatrix*>(this);
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
STDMETHODIMP_(ULONG) CoRayLibMatrix::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLibMatrix::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLibMatrix::GetTypeInfoCount(
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
STDMETHODIMP CoRayLibMatrix::GetTypeInfo(
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
STDMETHODIMP CoRayLibMatrix::GetIDsOfNames(
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
STDMETHODIMP CoRayLibMatrix::Invoke(
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
        static_cast<IRayLibMatrix*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

// IRayLibMatrix
STDMETHODIMP CoRayLibMatrix::get_m0(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m0;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m0(
    float val
)
{
    m_m0 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m1(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m1;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m1(
    float val
)
{
    m_m1 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m2(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m2;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m2(
    float val
)
{
    m_m2 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m3(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m3;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m3(
    float val
)
{
    m_m3 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m4(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m4;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m4(
    float val
)
{
    m_m4 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m5(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m5;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m5(
    float val
)
{
    m_m5 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m6(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m6;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m6(
    float val
)
{
    m_m6 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m7(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m7;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m7(
    float val
)
{
    m_m7 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m8(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m8;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m8(
    float val
)
{
    m_m8 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m9(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m9;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m9(
    float val
)
{
    m_m9 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m10(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m10;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m10(
    float val
)
{
    m_m10 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m11(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m11;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m11(
    float val
)
{
    m_m11 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m12(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m12;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m12(
    float val
)
{
    m_m12 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m13(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m13;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m13(
    float val
)
{
    m_m13 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m14(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m14;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m14(
    float val
)
{
    m_m14 = val;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::get_m15(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = m_m15;
    return S_OK;
}
STDMETHODIMP CoRayLibMatrix::put_m15(
    float val
)
{
    m_m15 = val;
    return S_OK;
}
