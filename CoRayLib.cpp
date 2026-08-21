// CoRayLib.cpp
//

#include "CoRayLib.h"
#include "tlhelper.h"
#include "comutil.h"
#include <time.h>
#include "VarArgList.h"


inline HRESULT CoRayLib::co2wr(IRayLibColor* in, WrRayLibColor* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    long elem = 0;

    hr = in->get_r(&elem);
    if (FAILED(hr)) return hr;
    out->r = (unsigned char)elem;

    hr = in->get_g(&elem);
    if (FAILED(hr)) return hr;
    out->g = (unsigned char)elem;

    hr = in->get_b(&elem);
    if (FAILED(hr)) return hr;
    out->b = (unsigned char)elem;

    hr = in->get_a(&elem);
    if (FAILED(hr)) return hr;
    out->a = (unsigned char)elem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibVector2* in, WrRayLibVector2* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    float elem = 0;

    hr = in->get_x(&elem);
    if (FAILED(hr)) return hr;
    out->x = elem;

    hr = in->get_y(&elem);
    if (FAILED(hr)) return hr;
    out->y = elem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibVector3* in, WrRayLibVector3* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    float elem = 0;

    hr = in->get_x(&elem);
    if (FAILED(hr)) return hr;
    out->x = elem;

    hr = in->get_y(&elem);
    if (FAILED(hr)) return hr;
    out->y = elem;

    hr = in->get_z(&elem);
    if (FAILED(hr)) return hr;
    out->z = elem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibVector4* in, WrRayLibVector4* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    float elem = 0;

    hr = in->get_x(&elem);
    if (FAILED(hr)) return hr;
    out->x = elem;

    hr = in->get_y(&elem);
    if (FAILED(hr)) return hr;
    out->y = elem;

    hr = in->get_z(&elem);
    if (FAILED(hr)) return hr;
    out->y = elem;

    hr = in->get_w(&elem);
    if (FAILED(hr)) return hr;
    out->w = elem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibRectangle* in, WrRayLibRectangle* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    float elem = 0;

    hr = in->get_x(&elem);
    if (FAILED(hr)) return hr;
    out->x = elem;

    hr = in->get_y(&elem);
    if (FAILED(hr)) return hr;
    out->y = elem;

    hr = in->get_width(&elem);
    if (FAILED(hr)) return hr;
    out->width = elem;

    hr = in->get_height(&elem);
    if (FAILED(hr)) return hr;
    out->height = elem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibCamera2D* in, WrRayLibCamera2D* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    IRayLibVector2* velem = NULL;
    float felem = 0;
    long lelem = 0;

    hr = in->get_offset(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->offset);
    if (FAILED(hr)) return hr;

    hr = in->get_target(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->target);
    if (FAILED(hr)) return hr;

    hr = in->get_rotation(&felem);
    if (FAILED(hr)) return hr;
    out->rotation = felem;

    hr = in->get_zoom(&felem);
    if (FAILED(hr)) return hr;
    out->zoom = felem;

    return hr;
}
inline HRESULT CoRayLib::co2wr(IRayLibCamera3D* in, WrRayLibCamera3D* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    IRayLibVector3* velem = NULL;
    float felem = 0;
    long lelem = 0;

    hr = in->get_position(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->position);
    if (FAILED(hr)) return hr;

    hr = in->get_target(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->target);
    if (FAILED(hr)) return hr;

    hr = in->get_up(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->up);
    if (FAILED(hr)) return hr;

    hr = in->get_fovy(&felem);
    if (FAILED(hr)) return hr;
    out->fovy = felem;

    hr = in->get_projection(&lelem);
    if (FAILED(hr)) return hr;
    out->projection = lelem;

    return hr;
}

inline HRESULT CoRayLib::co2wr(IRayLibRay* in, WrRayLibRay* out)
{
    HRESULT hr = S_OK;
    *out = { 0 };
    IRayLibVector3* velem = NULL;

    hr = in->get_position(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->position);
    if (FAILED(hr)) return hr;

    hr = in->get_direction(&velem);
    if (FAILED(hr)) return hr;
    hr = co2wr(velem, &out->direction);
    if (FAILED(hr)) return hr;

    return hr;
}

inline HRESULT CoRayLib::wr2co(WrRayLibColor* in, IRayLibColor* out)
{
    HRESULT hr = S_OK;

    hr = out->put_r(in->r);
    if (FAILED(hr)) return hr;

    hr = out->put_g(in->g);
    if (FAILED(hr)) return hr;

    hr = out->put_b(in->b);
    if (FAILED(hr)) return hr;

    hr = out->put_a(in->a);
    if (FAILED(hr)) return hr;

    return hr;
}

inline HRESULT CoRayLib::wr2co(WrRayLibVector2* in, IRayLibVector2* out)
{
    HRESULT hr = S_OK;

    hr = out->put_x(in->x);
    if (FAILED(hr)) return hr;

    hr = out->put_y(in->y);
    if (FAILED(hr)) return hr;

    return hr;
}

inline HRESULT CoRayLib::wr2co(WrRayLibVector3* in, IRayLibVector3* out)
{
    HRESULT hr = S_OK;

    hr = out->put_x(in->x);
    if (FAILED(hr)) return hr;

    hr = out->put_y(in->y);
    if (FAILED(hr)) return hr;

    hr = out->put_z(in->z);
    if (FAILED(hr)) return hr;

    return hr;
}

inline HRESULT CoRayLib::wr2co(WrRayLibVector4* in, IRayLibVector4* out)
{
    HRESULT hr = S_OK;

    hr = out->put_x(in->x);
    if (FAILED(hr)) return hr;

    hr = out->put_y(in->y);
    if (FAILED(hr)) return hr;

    hr = out->put_z(in->z);
    if (FAILED(hr)) return hr;

    hr = out->put_w(in->w);
    if (FAILED(hr)) return hr;

    return hr;
}

inline HRESULT CoRayLib::wr2co(WrRayLibRectangle* in, IRayLibRectangle* out)
{
    HRESULT hr = S_OK;

    hr = out->put_x(in->x);
    if (FAILED(hr)) return hr;

    hr = out->put_y(in->y);
    if (FAILED(hr)) return hr;

    hr = out->put_width(in->width);
    if (FAILED(hr)) return hr;

    hr = out->put_height(in->height);
    if (FAILED(hr)) return hr;

    return hr;
}
inline HRESULT CoRayLib::wr2co(WrRayLibCamera2D* in, IRayLibCamera2D* out)
{
    HRESULT hr = S_OK;

    IRayLibVector2* v = NULL;

    hr = out->get_offset(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->offset, v);
    if (FAILED(hr)) return hr;

    hr = out->get_target(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->target, v);
    if (FAILED(hr)) return hr;

    hr = out->put_rotation(in->rotation);
    if (FAILED(hr)) return hr;

    hr = out->put_zoom(in->zoom);
    if (FAILED(hr)) return hr;

    return hr;
}
inline HRESULT CoRayLib::wr2co(WrRayLibCamera3D* in, IRayLibCamera3D* out)
{
    HRESULT hr = S_OK;

    IRayLibVector3* v = NULL;

    hr = out->get_position(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->position, v);
    if (FAILED(hr)) return hr;

    hr = out->get_target(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->target, v);
    if (FAILED(hr)) return hr;

    hr = out->get_up(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->up, v);
    if (FAILED(hr)) return hr;

    hr = out->put_fovy(in->fovy);
    if (FAILED(hr)) return hr;

    hr = out->put_projection(in->projection);
    if (FAILED(hr)) return hr;

    return hr;
}
inline HRESULT CoRayLib::wr2co(WrRayLibRay* in, IRayLibRay* out)
{
    HRESULT hr = S_OK;

    IRayLibVector3* v = NULL;

    hr = out->get_position(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->position, v);
    if (FAILED(hr)) return hr;

    hr = out->get_direction(&v);
    if (FAILED(hr)) return hr;

    hr = wr2co(&in->direction, v);
    if (FAILED(hr)) return hr;

    return hr;
}
inline HRESULT CoRayLib::wr2co(WrRayLibMatrix* in, IRayLibMatrix* out)
{
    HRESULT hr = S_OK;

    hr = out->put_m0(in->m0);
    if (FAILED(hr)) return hr;

    hr = out->put_m1(in->m1);
    if (FAILED(hr)) return hr;

    hr = out->put_m2(in->m2);
    if (FAILED(hr)) return hr;

    hr = out->put_m3(in->m3);
    if (FAILED(hr)) return hr;

    hr = out->put_m4(in->m4);
    if (FAILED(hr)) return hr;

    hr = out->put_m5(in->m5);
    if (FAILED(hr)) return hr;

    hr = out->put_m6(in->m6);
    if (FAILED(hr)) return hr;

    hr = out->put_m7(in->m7);
    if (FAILED(hr)) return hr;

    hr = out->put_m8(in->m8);
    if (FAILED(hr)) return hr;

    hr = out->put_m9(in->m9);
    if (FAILED(hr)) return hr;

    hr = out->put_m10(in->m10);
    if (FAILED(hr)) return hr;

    hr = out->put_m11(in->m11);
    if (FAILED(hr)) return hr;

    hr = out->put_m12(in->m12);
    if (FAILED(hr)) return hr;

    hr = out->put_m13(in->m13);
    if (FAILED(hr)) return hr;

    hr = out->put_m14(in->m14);
    if (FAILED(hr)) return hr;

    hr = out->put_m15(in->m15);
    if (FAILED(hr)) return hr;

    return hr;
}


CoRayLib::CoRayLib(HMODULE hModule)
{
    m_cRef = 1;

    LoadTypeInfo(
        hModule,
        IID_IRayLib,
        &m_pTypeInfo
    );
}
CoRayLib::~CoRayLib()
{
    if (m_pTypeInfo)
        m_pTypeInfo->Release();
}

// IUnknown
STDMETHODIMP CoRayLib::QueryInterface(
    REFIID riid,
    void** ppvObject
)
{
    if (!ppvObject)
        return E_POINTER;

    if (riid == IID_IUnknown) {
        *ppvObject = static_cast<IRayLib*>(this);
    }
    else if (riid == IID_IRayLib) {
        *ppvObject = static_cast<IRayLib*>(this);
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
STDMETHODIMP_(ULONG) CoRayLib::AddRef(
    void
)
{
    return InterlockedIncrement(&m_cRef);
}
STDMETHODIMP_(ULONG) CoRayLib::Release(
    void
)
{
    const ULONG cRef = InterlockedDecrement(&m_cRef);
    if (cRef == 0)
        delete this;
    return cRef;
}

// IDispatch
STDMETHODIMP CoRayLib::GetTypeInfoCount(
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
STDMETHODIMP CoRayLib::GetTypeInfo(
    UINT iTInfo,
    LCID lcid,
    ITypeInfo** ppTInfo
)
{
    if (!ppTInfo)
        return E_POINTER;

    if(!m_pTypeInfo)
        return E_ABORT;

    *ppTInfo = m_pTypeInfo;
    (*ppTInfo)->AddRef();
    return S_OK;
}
STDMETHODIMP CoRayLib::GetIDsOfNames(
    REFIID riid,
    LPOLESTR* rgszNames,
    UINT cNames,
    LCID lcid,
    DISPID* rgDispId
)
{
    if (riid != IID_NULL)
        return DISP_E_UNKNOWNINTERFACE;

    if(!m_pTypeInfo)
        return E_ABORT;

    return m_pTypeInfo->GetIDsOfNames(
        rgszNames,
        cNames,
        (MEMBERID*)rgDispId
    );
}
STDMETHODIMP CoRayLib::Invoke(
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
        static_cast<IRayLib*>(this),
        (MEMBERID)dispIdMember,
        wFlags,
        pDispParams,
        pVarResult,
        pExcepInfo,
        puArgErr
    );
}

/////////////////////////////////////////////
// IRayLib

// Window-related functions

STDMETHODIMP CoRayLib::InitWindow(
    long width,
    long height,
    BSTR title
)
{
    char* lpsz = nullptr;

    WrRayLib::InitWindow(
        (int)width,
        (int)height,
        lpsz = _com_util::ConvertBSTRToString(title)
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::CloseWindow(
    void
)
{
    WrRayLib::CloseWindow();

    return S_OK;
}
STDMETHODIMP CoRayLib::WindowShouldClose(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if(WrRayLib::WindowShouldClose())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowReady(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowReady())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowFullscreen(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowFullscreen())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowHidden(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowHidden())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowMinimized(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowMinimized())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowMaximized(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowMaximized())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowFocused(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowFocused())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowResized(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowResized())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsWindowState(
    long flag,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsWindowState(flag))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowState(
    long flags
)
{
    WrRayLib::SetWindowState(
        (unsigned int)flags
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::ClearWindowState(
    long flags
)
{
    WrRayLib::ClearWindowState(
        (unsigned int)flags
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::ToggleFullscreen(
    void
)
{
    WrRayLib::ToggleFullscreen();

    return S_OK;
}
STDMETHODIMP CoRayLib::ToggleBorderlessWindowed(
    void
)
{
    WrRayLib::ToggleBorderlessWindowed();

    return S_OK;
}
STDMETHODIMP CoRayLib::MaximizeWindow(
    void
)
{
    WrRayLib::MaximizeWindow();

    return S_OK;
}
STDMETHODIMP CoRayLib::MinimizeWindow(
    void
)
{
    WrRayLib::MinimizeWindow();

    return S_OK;
}
STDMETHODIMP CoRayLib::RestoreWindow(
    void
)
{
    WrRayLib::RestoreWindow();

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowTitle(
    BSTR title
)
{
    char* lpsz = nullptr;

    WrRayLib::SetWindowTitle(
        lpsz = _com_util::ConvertBSTRToString(title)
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowPosition(
    long x,
    long y
)
{
    WrRayLib::SetWindowPosition(
        (int)x,
        (int)y
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowMonitor(
    long monitor
)
{
    WrRayLib::SetWindowMonitor(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowMinSize(
    long width,
    long height
)
{
    WrRayLib::SetWindowMinSize(
        (int)width,
        (int)height
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowMaxSize(
    long width,
    long height
)
{
    WrRayLib::SetWindowMaxSize(
        (int)width,
        (int)height
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowSize(
    long width,
    long height
)
{
    WrRayLib::SetWindowSize(
        (int)width,
        (int)height
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowOpacity(
    float opacity
)
{
    WrRayLib::SetWindowOpacity(
        opacity
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetWindowFocused(
    void
)
{
    WrRayLib::SetWindowFocused();

    return S_OK;
}

STDMETHODIMP CoRayLib::GetScreenWidth(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetScreenWidth();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetScreenHeight(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetScreenHeight();
    
    return S_OK;
}
STDMETHODIMP CoRayLib::GetRenderWidth(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetRenderWidth();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetRenderHeight(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetRenderHeight();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorCount(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorCount();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetCurrentMonitor(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetCurrentMonitor();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorPosition(
    long monitor,
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetMonitorPosition(
            (int)monitor
        );

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorWidth(
    long monitor,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorWidth(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorHeight(
    long monitor,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorHeight(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorPhysicalWidth(
    long monitor,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorPhysicalWidth(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorPhysicalHeight(
    long monitor,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorPhysicalHeight(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorRefreshRate(
    long monitor,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMonitorRefreshRate(
        (int)monitor
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetWindowPosition(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetWindowPosition();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetWindowScaleDPI(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetWindowScaleDPI();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMonitorName(
    long monitor,
    BSTR* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::GetMonitorName(
            (int)monitor
        )
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetClipboardText(
    BSTR text
)
{
    char* lpsz = nullptr;

    WrRayLib::SetClipboardText(
        lpsz = _com_util::ConvertBSTRToString(text)
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetClipboardText(
    BSTR* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::GetClipboardText()
    );

    return S_OK;
}

STDMETHODIMP CoRayLib::EnableEventWaiting(
    void
)
{
    WrRayLib::EnableEventWaiting();

    return S_OK;
}
STDMETHODIMP CoRayLib::DisableEventWaiting(
    void
)
{
    WrRayLib::DisableEventWaiting();

    return S_OK;
}


// Cursor-related functions

STDMETHODIMP CoRayLib::ShowCursor(
    void
)
{
    WrRayLib::ShowCursor();

    return S_OK;
}
STDMETHODIMP CoRayLib::HideCursor(
    void
)
{
    WrRayLib::HideCursor();

    return S_OK;
}
STDMETHODIMP CoRayLib::IsCursorHidden(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsCursorHidden())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::EnableCursor(
    void
)
{
    WrRayLib::EnableCursor();

    return S_OK;
}
STDMETHODIMP CoRayLib::DisableCursor(
    void
)
{
    WrRayLib::DisableCursor();

    return S_OK;
}
STDMETHODIMP CoRayLib::IsCursorOnScreen(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsCursorOnScreen())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}


// Drawing-related functions

STDMETHODIMP CoRayLib::ClearBackground(
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::ClearBackground(
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::BeginDrawing(
    void
)
{
    WrRayLib::BeginDrawing();

    return S_OK;
}
STDMETHODIMP CoRayLib::EndDrawing(
    void
)
{
    WrRayLib::EndDrawing();

    return S_OK;
}
STDMETHODIMP CoRayLib::BeginMode2D(
    IRayLibCamera2D* camera
)
{
    if (!camera)
        return E_POINTER;

    WrRayLibCamera2D wr_camera = { 0 };

    HRESULT hr = co2wr(
        camera,
        &wr_camera
    );
    if (FAILED(hr))
        return hr;

    WrRayLib::BeginMode2D(
        wr_camera
    );

    return hr;
}
STDMETHODIMP CoRayLib::EndMode2D(
    void
)
{
    WrRayLib::EndMode2D();

    return S_OK;
}
STDMETHODIMP CoRayLib::BeginMode3D(
    IRayLibCamera3D* camera
)
{
    if (!camera)
        return E_POINTER;

    WrRayLibCamera3D wr_camera = { 0 };

    HRESULT hr = co2wr(
        camera,
        &wr_camera
    );
    if (FAILED(hr))
        return hr;

    WrRayLib::BeginMode3D(
        wr_camera
    );

    return hr;
}
STDMETHODIMP CoRayLib::EndMode3D(
    void
)
{
    WrRayLib::EndMode3D();

    return S_OK;
}
STDMETHODIMP CoRayLib::BeginBlendMode(
    long mode
)
{
    WrRayLib::BeginBlendMode(
        (int)mode
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::EndBlendMode(
    void
)
{
    WrRayLib::EndBlendMode();

    return S_OK;
}
STDMETHODIMP CoRayLib::BeginScissorMode(
    long x,
    long y,
    long width,
    long height
)
{
    WrRayLib::BeginScissorMode(
        (int)x,
        (int)y,
        (int)width,
        (int)height
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::EndScissorMode(
    void
)
{
    WrRayLib::EndScissorMode();

    return S_OK;
}


// VR stereo config functions for VR simulator

// Shader management functions

// Screen-space-related functions
STDMETHODIMP CoRayLib::GetScreenToWorldRay(
    IRayLibVector2* position,
    IRayLibCamera3D* camera,
    IRayLibRay** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_position = { 0 };
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibRay retVal = WrRayLib::GetScreenToWorldRay(
        wr_position,
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibRay,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRay,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetScreenToWorldRayEx(
    IRayLibVector2* position,
    IRayLibCamera3D* camera,
    long width,
    long height,
    IRayLibRay** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_position = { 0 };
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibRay retVal = WrRayLib::GetScreenToWorldRayEx(
        wr_position,
        wr_camera,
        (int)width,
        (int)height
    );

    hr = CoCreateInstance(
        CLSID_RayLibRay,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRay,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetWorldToScreen(
    IRayLibVector3* position,
    IRayLibCamera3D* camera,
    IRayLibVector2** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_position = { 0 };
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibVector2 retVal = WrRayLib::GetWorldToScreen(
        wr_position,
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetWorldToScreenEx(
    IRayLibVector3* position,
    IRayLibCamera3D* camera,
    long width,
    long height,
    IRayLibVector2** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_position = { 0 };
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibVector2 retVal = WrRayLib::GetWorldToScreenEx(
        wr_position,
        wr_camera,
        (int)width,
        (int)height
    );

    hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetWorldToScreen2D(
    IRayLibVector2* position,
    IRayLibCamera2D* camera,
    IRayLibVector2** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_position = { 0 };
    WrRayLibCamera2D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibVector2 retVal = WrRayLib::GetWorldToScreen2D(
        wr_position,
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetScreenToWorld2D(
    IRayLibVector2* position,
    IRayLibCamera2D* camera,
    IRayLibVector2** pRetVal
)
{
    if (!position)
        return E_POINTER;
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_position = { 0 };
    WrRayLibCamera2D wr_camera = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibVector2 retVal = WrRayLib::GetScreenToWorld2D(
        wr_position,
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetCameraMatrix(
    IRayLibCamera3D* camera,
    IRayLibMatrix** pRetVal
)
{
    if (!camera)
        return E_POINTER;
    if(!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibMatrix retVal = WrRayLib::GetCameraMatrix(
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibMatrix,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibMatrix,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}
STDMETHODIMP CoRayLib::GetCameraMatrix2D(
    IRayLibCamera2D* camera,
    IRayLibMatrix** pRetVal
)
{
    if (!camera)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibCamera2D wr_camera = { 0 };

    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLibMatrix retVal = WrRayLib::GetCameraMatrix2D(
        wr_camera
    );

    hr = CoCreateInstance(
        CLSID_RayLibMatrix,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibMatrix,
        (LPVOID*)pRetVal
    );

    hr = wr2co(
        &retVal,
        *pRetVal
    );

    return hr;
}


// Timing-related functions

STDMETHODIMP CoRayLib::SetTargetFPS(
    long fps
)
{
    WrRayLib::SetTargetFPS(
        (int)fps
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetFrameTime(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetFrameTime();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTime(
    double* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetTime();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetFPS(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetFPS();

    return S_OK;
}


// Custom frame control functions

STDMETHODIMP CoRayLib::SwapScreenBuffer(
    void
)
{
    WrRayLib::SwapScreenBuffer();

    return S_OK;
}
STDMETHODIMP CoRayLib::PollInputEvents(
    void
)
{
    WrRayLib::PollInputEvents();

    return S_OK;
}
STDMETHODIMP CoRayLib::WaitTime(
    double seconds
)
{
    WrRayLib::WaitTime(
        seconds
    );

    return S_OK;
}


// Random values generation functions

STDMETHODIMP CoRayLib::SetRandomSeed(
    long seed
)
{
    WrRayLib::SetRandomSeed(
        (unsigned int)seed
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetRandomValue(
    long min,
    long max,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetRandomValue(
        (int)min,
        (int)max
    );

    return S_OK;
}


// Misc. functions

STDMETHODIMP CoRayLib::TakeScreenshot(
    BSTR fileName
)
{
    char* lpsz = nullptr;

    WrRayLib::TakeScreenshot(
        lpsz = _com_util::ConvertBSTRToString(fileName)
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::SetConfigFlags(
    long flags
)
{
    WrRayLib::SetConfigFlags(
        (unsigned int)flags
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::OpenURL(
    BSTR url
)
{
    char* lpsz = nullptr;

    WrRayLib::OpenURL(
        lpsz = _com_util::ConvertBSTRToString(url)
    );

    delete[] lpsz;

    return S_OK;
}


// Logging system
STDMETHODIMP CoRayLib::SetTraceLogLevel(
    long logLevel
)
{
    WrRayLib::SetTraceLogLevel(
        (int)logLevel
    );

    return S_OK;
}


// Memory management, using internal allocators

// File system management functions

// File access custom callbacks

// Compression/Encoding functionality

// Automation events functionality

// Input-related functions: keyboard
STDMETHODIMP CoRayLib::IsKeyPressed(
    long key,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsKeyPressed((int)key))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsKeyPressedRepeat(
    long key,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsKeyPressedRepeat((int)key))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsKeyDown(
    long key,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsKeyDown((int)key))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsKeyReleased(
    long key,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsKeyReleased((int)key))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsKeyUp(
    long key,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsKeyUp((int)key))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetKeyPressed(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetKeyPressed();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetCharPressed(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetCharPressed();

    return S_OK;
}
STDMETHODIMP CoRayLib::SetExitKey(
    long key
)
{
    WrRayLib::SetExitKey(
        (int)key
    );

    return S_OK;
}


// Input-related functions: gamepads
STDMETHODIMP CoRayLib::IsGamepadAvailable(
    long gamepad,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGamepadAvailable((int)gamepad))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGamepadName(
    long gamepad,
    BSTR* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::GetGamepadName(
            (int)gamepad
        )
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::IsGamepadButtonPressed(
    long gamepad,
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGamepadButtonPressed((int)gamepad, (int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsGamepadButtonDown(
    long gamepad,
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGamepadButtonDown((int)gamepad, (int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsGamepadButtonReleased(
    long gamepad,
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGamepadButtonReleased((int)gamepad, (int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsGamepadButtonUp(
    long gamepad,
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGamepadButtonUp((int)gamepad, (int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGamepadButtonPressed(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGamepadButtonPressed();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGamepadAxisCount(
    long gamepad,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGamepadAxisCount(
        (int)gamepad
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGamepadAxisMovement(
    long gamepad,
    long axis,
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGamepadAxisMovement(
        (int)gamepad,
        (int)axis
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetGamepadMappings(
    BSTR mappings,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = WrRayLib::SetGamepadMappings(
        lpsz = _com_util::ConvertBSTRToString(mappings)
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::SetGamepadVibration(
    long gamepad,
    float leftMotor,
    float rightMotor,
    float duration
)
{
    WrRayLib::SetGamepadVibration(
        (int)gamepad,
        leftMotor,
        rightMotor,
        duration
    );

    return S_OK;
}


// Input-related functions: mouse
STDMETHODIMP CoRayLib::IsMouseButtonPressed(
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsMouseButtonPressed((int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsMouseButtonDown(
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsMouseButtonDown((int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsMouseButtonReleased(
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsMouseButtonReleased((int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::IsMouseButtonUp(
    long button,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsMouseButtonUp((int)button))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMouseX(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMouseX();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMouseY(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMouseY();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMousePosition(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if(SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetMousePosition();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return hr;
}
STDMETHODIMP CoRayLib::GetMouseDelta(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetMouseDelta();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return hr;
}
STDMETHODIMP CoRayLib::SetMousePosition(
    long x,
    long y
)
{
    WrRayLib::SetMousePosition(
        (int)x,
        (int)y
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetMouseOffset(
    long offsetX,
    long offsetY
)
{
    WrRayLib::SetMouseOffset(
        (int)offsetX,
        (int)offsetY
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::SetMouseScale(
    float scaleX,
    float scaleY
)
{
    WrRayLib::SetMouseScale(
        scaleX,
        scaleY
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMouseWheelMove(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMouseWheelMove();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMouseWheelMoveV(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if(SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetMouseWheelMoveV();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return hr;
}
STDMETHODIMP CoRayLib::SetMouseCursor(
    long cursor
)
{
    WrRayLib::SetMouseCursor((int)cursor);

    return S_OK;
}


// Input-related functions: touch
STDMETHODIMP CoRayLib::GetTouchX(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetTouchX();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTouchY(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetTouchY();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTouchPosition(
    long index,
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetTouchPosition(
            (int)index
        );

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTouchPointId(
    long index,
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetTouchPointId(
        (int)index
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTouchPointCount(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetTouchPointCount();

    return S_OK;
}


// Gestures and Touch Handling Functions (Module: rgestures)
STDMETHODIMP CoRayLib::SetGesturesEnabled(
    long flags
)
{
    WrRayLib::SetGesturesEnabled(
        (unsigned int)flags
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::IsGestureDetected(
    long gesture,
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsGestureDetected((unsigned int)gesture))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGestureDetected(
    long* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;
    
    *pRetVal = WrRayLib::GetGestureDetected();
    
    return S_OK;
}
STDMETHODIMP CoRayLib::GetGestureHoldDuration(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGestureHoldDuration();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGestureDragVector(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetGestureDragVector();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGestureDragAngle(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGestureDragAngle();

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGesturePinchVector(
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        const WrRayLibVector2 v = WrRayLib::GetGesturePinchVector();

        (*pRetVal)->put_x(v.x);
        (*pRetVal)->put_y(v.y);
    }

    return S_OK;
}
STDMETHODIMP CoRayLib::GetGesturePinchAngle(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetGesturePinchAngle();

    return S_OK;
}


// Camera System Functions (Module: rcamera)
STDMETHODIMP CoRayLib::UpdateCamera(
    IRayLibCamera3D* camera,
    long mode
)
{
    if (!camera)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibCamera3D wr_camera = { 0 };

    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    WrRayLib::UpdateCamera(
        &wr_camera,
        (int)mode
    );

    hr = wr2co(&wr_camera, camera);
    if (FAILED(hr)) return hr;

    return S_OK;
}
STDMETHODIMP CoRayLib::UpdateCameraPro(
    IRayLibCamera3D* camera,
    IRayLibVector3* movement,
    IRayLibVector3* rotation,
    float zoom
)
{
    if (!camera)
        return E_POINTER;
    if (!movement)
        return E_POINTER;
    if (!rotation)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibCamera3D wr_camera = { 0 };
    WrRayLibVector3 wr_movement = { 0 };
    WrRayLibVector3 wr_rotation = { 0 };

    hr = co2wr(camera, &wr_camera);
    if (FAILED(hr)) return hr;

    hr = co2wr(movement, &wr_movement);
    if (FAILED(hr)) return hr;

    hr = co2wr(rotation, &wr_rotation);
    if (FAILED(hr)) return hr;

    WrRayLib::UpdateCameraPro(
        &wr_camera,
        wr_movement,
        wr_rotation,
        zoom
    );

    hr = wr2co(&wr_camera, camera);
    if (FAILED(hr)) return hr;

    return S_OK;
}


//////////////////////////////////////////////
// Module: RSHAPES

STDMETHODIMP CoRayLib::GetShapesTextureRectangle(
    IRayLibRectangle** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    WrRayLibRectangle wr_rect = WrRayLib::GetShapesTextureRectangle();

    HRESULT hr = CoCreateInstance(
        CLSID_RayLibRectangle,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRectangle,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        hr = wr2co(
            &wr_rect,
            *pRetVal
        );
    }

    return hr;
}


// Basic shapes drawing functions
STDMETHODIMP CoRayLib::DrawPixel(
    long posX,
    long posY,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPixel(
        (int)posX,
        (int)posY,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawPixelV(
    IRayLibVector2* position,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(position, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPixelV(
        pos,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawLine(
    long startPosX,
    long startPosY,
    long endPosX,
    long endPosY,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLine(
        (int)startPosX,
        (int)startPosY,
        (int)endPosX,
        (int)endPosY,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawLineV(
    IRayLibVector2* startPos,
    IRayLibVector2* endPos,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 posStart = { 0 };
    WrRayLibVector2 posEnd = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(startPos, &posStart);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &posEnd);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLineV(
        posStart,
        posEnd,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawLineEx(
    IRayLibVector2* startPos,
    IRayLibVector2* endPos,
    float thick,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 posStart = { 0 };
    WrRayLibVector2 posEnd = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(startPos, &posStart);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &posEnd);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLineEx(
        posStart,
        posEnd,
        thick,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawLineBezier(
    IRayLibVector2* startPos,
    IRayLibVector2* endPos,
    float thick,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_startPos = { 0 };
    WrRayLibVector2 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLineBezier(
        wr_startPos,
        wr_endPos,
        thick,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawLineDashed(
    IRayLibVector2* startPos,
    IRayLibVector2* endPos,
    long dashSize,
    long spaceSize,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_startPos = { 0 };
    WrRayLibVector2 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLineDashed(
        wr_startPos,
        wr_endPos,
        (int)dashSize,
        (int)spaceSize,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircle(
    long centerX,
    long centerY,
    float radius,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircle(
        (int)centerX,
        (int)centerY,
        radius,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleV(
    IRayLibVector2* center,
    float radius,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleV(
        pos,
        radius,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleGradient(
    IRayLibVector2* center,
    float radius,
    IRayLibColor* inner,
    IRayLibColor* outer
)
{
    if (!center)
        return E_POINTER;
    if (!inner)
        return E_POINTER;
    if (!outer)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_inner = { 0 };
    WrRayLibColor wr_outer = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(inner, &wr_inner);
    if (FAILED(hr)) return hr;
    hr = co2wr(outer, &wr_outer);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleGradient(
        wr_center,
        radius,
        wr_inner,
        wr_outer
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleSector(
    IRayLibVector2* center,
    float radius,
    float startAngle,
    float endAngle,
    long segments,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleSector(
        wr_center,
        radius,
        startAngle,
        endAngle,
        (int)segments,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleSectorLines(
    IRayLibVector2* center,
    float radius,
    float startAngle,
    float endAngle,
    long segments,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleSectorLines(
        wr_center,
        radius,
        startAngle,
        endAngle,
        (int)segments,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleLines(
    long centerX,
    long centerY,
    float radius,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleLines(
        (int)centerX,
        (int)centerY,
        radius,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircleLinesV(
    IRayLibVector2* center,
    float radius,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircleLinesV(
        pos,
        radius,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawEllipse(
    long centerX,
    long centerY,
    float radiusH,
    float radiusV,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawEllipse(
        (int)centerX,
        (int)centerY,
        radiusH,
        radiusV,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawEllipseV(
    IRayLibVector2* center,
    float radiusH,
    float radiusV,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawEllipseV(
        pos,
        radiusH,
        radiusV,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawEllipseLines(
    long centerX,
    long centerY,
    float radiusH,
    float radiusV,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawEllipseLines(
        (int)centerX,
        (int)centerY,
        radiusH,
        radiusV,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawEllipseLinesV(
    IRayLibVector2* center,
    float radiusH,
    float radiusV,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawEllipseLinesV(
        pos,
        radiusH,
        radiusV,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRing(
    IRayLibVector2* center,
    float innerRadius,
    float outerRadius,
    float startAngle,
    float endAngle,
    long segments,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRing(
        wr_center,
        innerRadius,
        outerRadius,
        startAngle,
        endAngle,
        (int)segments,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRingLines(
    IRayLibVector2* center,
    float innerRadius,
    float outerRadius,
    float startAngle,
    float endAngle,
    long segments,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRingLines(
        wr_center,
        innerRadius,
        outerRadius,
        startAngle,
        endAngle,
        (int)segments,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangle(
    long posX,
    long posY,
    long width,
    long height,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangle(
        (int)posX,
        (int)posY,
        width,
        height,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleV(
    IRayLibVector2* position,
    IRayLibVector2* size,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!size)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibVector2 siz = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(position, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(size, &siz);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleV(
        pos,
        siz,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleRec(
    IRayLibRectangle* rec,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle rect = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(rec, &rect);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleRec(
        rect,
        clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectanglePro(
    IRayLibRectangle* rec,
    IRayLibVector2* origin,
    float rotation,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!origin)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibVector2 wr_vec = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(origin, &wr_vec);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectanglePro(
        wr_rec,
        wr_vec,
        rotation,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleGradientV(
    long posX,
    long posY,
    long width,
    long height,
    IRayLibColor* top,
    IRayLibColor* bottom
)
{
    if (!top)
        return E_POINTER;
    if (!bottom)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor wr_top = { 0 };
    WrRayLibColor wr_bottom = { 0 };

    hr = co2wr(top, &wr_top);
    if (FAILED(hr)) return hr;
    hr = co2wr(bottom, &wr_bottom);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleGradientH(
        (int)posX,
        (int)posY,
        (int)width,
        (int)height,
        wr_top,
        wr_bottom
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleGradientH(
    long posX,
    long posY,
    long width,
    long height,
    IRayLibColor* left,
    IRayLibColor* right
)
{
    if (!left)
        return E_POINTER;
    if (!right)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor wr_left = { 0 };
    WrRayLibColor wr_right = { 0 };

    hr = co2wr(left, &wr_left);
    if (FAILED(hr)) return hr;
    hr = co2wr(right, &wr_right);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleGradientH(
        (int)posX,
        (int)posY,
        (int)width,
        (int)height,
        wr_left,
        wr_right
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleGradientEx(
    IRayLibRectangle* rec,
    IRayLibColor* topLeft,
    IRayLibColor* bottomLeft,
    IRayLibColor* bottomRight,
    IRayLibColor* topRight
)
{
    if (!rec)
        return E_POINTER;
    if (!topLeft)
        return E_POINTER;
    if (!bottomLeft)
        return E_POINTER;
    if (!bottomRight)
        return E_POINTER;
    if (!topRight)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibColor wr_topLeft = { 0 };
    WrRayLibColor wr_bottomLeft = { 0 };
    WrRayLibColor wr_bottomRight = { 0 };
    WrRayLibColor wr_topRight = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(topLeft, &wr_topLeft);
    if (FAILED(hr)) return hr;
    hr = co2wr(bottomLeft, &wr_bottomLeft);
    if (FAILED(hr)) return hr;
    hr = co2wr(bottomRight, &wr_bottomRight);
    if (FAILED(hr)) return hr;
    hr = co2wr(topRight, &wr_topRight);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleGradientEx(
        wr_rec,
        wr_topLeft,
        wr_bottomLeft,
        wr_bottomRight,
        wr_topRight
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleLines(
    long posX,
    long posY,
    long width,
    long height,
    IRayLibColor* color
)
{
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleLines(
        (int)posX,
        (int)posY,
        (int)width,
        (int)height,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleLinesEx(
    IRayLibRectangle* rec,
    float lineThick,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleLinesEx(
        wr_rec,
        lineThick,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleRounded(
    IRayLibRectangle* rec,
    float roundness,
    long segments,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleRounded(
        wr_rec,
        roundness,
        (int)segments,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleRoundedLines(
    IRayLibRectangle* rec,
    float roundness,
    long segments,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleRoundedLines(
        wr_rec,
        roundness,
        (int)segments,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRectangleRoundedLinesEx(
    IRayLibRectangle* rec,
    float roundness,
    long segments,
    float lineThick,
    IRayLibColor* color
)
{
    if (!rec)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle wr_rec = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(rec, &wr_rec);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRectangleRoundedLinesEx(
        wr_rec,
        roundness,
        (int)segments,
        lineThick,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawTriangle(
    IRayLibVector2* v1,
    IRayLibVector2* v2,
    IRayLibVector2* v3,
    IRayLibColor* color
)
{
    if (!v1)
        return E_POINTER;
    if (!v2)
        return E_POINTER;
    if (!v3)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 vv1 = { 0 };
    WrRayLibVector2 vv2 = { 0 };
    WrRayLibVector2 vv3 = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(v1, &vv1);
    if (FAILED(hr)) return hr;
    hr = co2wr(v2, &vv2);
    if (FAILED(hr)) return hr;
    hr = co2wr(v3, &vv3);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawTriangle(
        vv1,
        vv2,
        vv3,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawTriangleLines(
    IRayLibVector2* v1,
    IRayLibVector2* v2,
    IRayLibVector2* v3,
    IRayLibColor* color
)
{
    if (!v1)
        return E_POINTER;
    if (!v2)
        return E_POINTER;
    if (!v3)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 vv1 = { 0 };
    WrRayLibVector2 vv2 = { 0 };
    WrRayLibVector2 vv3 = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(v1, &vv1);
    if (FAILED(hr)) return hr;
    hr = co2wr(v2, &vv2);
    if (FAILED(hr)) return hr;
    hr = co2wr(v3, &vv3);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawTriangleLines(
        vv1,
        vv2,
        vv3,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawPoly(
    IRayLibVector2* center,
    long sides,
    float radius,
    float rotation,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPoly(
        pos,
        (int)sides,
        radius,
        rotation,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawPolyLines(
    IRayLibVector2* center,
    long sides,
    float radius,
    float rotation,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibColor clr = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPolyLines(
        pos,
        (int)sides,
        radius,
        rotation,
        clr
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::DrawPolyLinesEx(
    IRayLibVector2* center,
    long sides,
    float radius,
    float rotation,
    float lineThick,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 wr_center = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPolyLinesEx(
        wr_center,
        sides,
        radius,
        rotation,
        lineThick,
        wr_color
    );

    return hr;
}

// Basic shapes collision detection functions
STDMETHODIMP CoRayLib::CheckCollisionRecs(
    IRayLibRectangle* rec1,
    IRayLibRectangle* rec2,
    VARIANT_BOOL* pRetVal
)
{
    if (!rec1)
        return E_POINTER;
    if (!rec2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle rect1 = { 0 };
    WrRayLibRectangle rect2 = { 0 };

    hr = co2wr(rec1, &rect1);
    if (FAILED(hr)) return hr;
    hr = co2wr(rec2, &rect2);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionRecs(rect1, rect2))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionCircles(
    IRayLibVector2* center1,
    float radius1,
    IRayLibVector2* center2,
    float radius2,
    VARIANT_BOOL* pRetVal
)
{
    if (!center1)
        return E_POINTER;
    if (!center2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos1 = { 0 };
    WrRayLibVector2 pos2 = { 0 };

    hr = co2wr(center1, &pos1);
    if (FAILED(hr)) return hr;
    hr = co2wr(center2, &pos2);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionCircles(pos1, radius1, pos2, radius2))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionCircleRec(
    IRayLibVector2* center,
    float radius,
    IRayLibRectangle* rec,
    VARIANT_BOOL* pRetVal
)
{
    if (!center)
        return E_POINTER;
    if (!rec)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibRectangle rect = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(rec, &rect);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionCircleRec(pos, radius, rect))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionCircleLine(
    IRayLibVector2* center,
    float radius,
    IRayLibVector2* p1,
    IRayLibVector2* p2,
    VARIANT_BOOL* pRetVal
)
{
    if (!center)
        return E_POINTER;
    if (!p1)
        return E_POINTER;
    if (!p2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibVector2 pp1 = { 0 };
    WrRayLibVector2 pp2 = { 0 };

    hr = co2wr(center, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(p1, &pp1);
    if (FAILED(hr)) return hr;
    hr = co2wr(p2, &pp2);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionCircleLine(pos, radius, pp1, pp2))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionPointRec(
    IRayLibVector2* point,
    IRayLibRectangle* rec,
    VARIANT_BOOL* pRetVal
)
{
    if (!point)
        return E_POINTER;
    if (!rec)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibRectangle rect = { 0 };

    hr = co2wr(point, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(rec, &rect);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionPointRec(pos, rect))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionPointCircle(
    IRayLibVector2* point,
    IRayLibVector2* center,
    float radius,
    VARIANT_BOOL* pRetVal
)
{
    if (!point)
        return E_POINTER;
    if (!center)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibVector2 cnt = { 0 };

    hr = co2wr(point, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(center, &cnt);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionPointCircle(pos, cnt, radius))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionPointTriangle(
    IRayLibVector2* point,
    IRayLibVector2* p1,
    IRayLibVector2* p2,
    IRayLibVector2* p3,
    VARIANT_BOOL* pRetVal
)
{
    if (!point)
        return E_POINTER;
    if (!p1)
        return E_POINTER;
    if (!p2)
        return E_POINTER;
    if (!p3)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibVector2 pp1 = { 0 };
    WrRayLibVector2 pp2 = { 0 };
    WrRayLibVector2 pp3 = { 0 };

    hr = co2wr(point, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(p1, &pp1);
    if (FAILED(hr)) return hr;
    hr = co2wr(p2, &pp2);
    if (FAILED(hr)) return hr;
    hr = co2wr(p3, &pp3);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionPointTriangle(pos, pp1, pp2, pp3))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;
}
STDMETHODIMP CoRayLib::CheckCollisionPointLine(
    IRayLibVector2* point,
    IRayLibVector2* p1,
    IRayLibVector2* p2,
    long threshold,
    VARIANT_BOOL* pRetVal
)
{
    if (!point)
        return E_POINTER;
    if (!p1)
        return E_POINTER;
    if (!p2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector2 pos = { 0 };
    WrRayLibVector2 pp1 = { 0 };
    WrRayLibVector2 pp2 = { 0 };

    hr = co2wr(point, &pos);
    if (FAILED(hr)) return hr;
    hr = co2wr(p1, &pp1);
    if (FAILED(hr)) return hr;
    hr = co2wr(p2, &pp2);
    if (FAILED(hr)) return hr;

    if (WrRayLib::CheckCollisionPointLine(pos, pp1, pp2, (int)threshold))
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetCollisionRec(
    IRayLibRectangle* rec1,
    IRayLibRectangle* rec2,
    IRayLibRectangle** pRetVal
)
{
    if (!rec1)
        return E_POINTER;
    if (!rec2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRectangle rect1 = { 0 };
    WrRayLibRectangle rect2 = { 0 };

    hr = co2wr(rec1, &rect1);
    if (FAILED(hr)) return hr;
    hr = co2wr(rec2, &rect1);
    if (FAILED(hr)) return hr;

    WrRayLibRectangle rectR = WrRayLib::GetCollisionRec(
        rect1,
        rect2
    );

    hr = CoCreateInstance(
        CLSID_RayLibRectangle,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRectangle,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        hr = wr2co(
            &rectR,
            *pRetVal
        );
    }

    return hr;
}

// Color/pixel related functions

STDMETHODIMP CoRayLib::ColorIsEqual(
    IRayLibColor* col1,
    IRayLibColor* col2,
    VARIANT_BOOL* pRetVal
)
{
    if (!col1)
        return E_POINTER;
    if (!col2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor wr_color1 = { 0 };
    WrRayLibColor wr_color2 = { 0 };

    hr = co2wr(col1, &wr_color1);
    if (FAILED(hr)) return hr;
    hr = co2wr(col2, &wr_color2);
    if (FAILED(hr)) return hr;

    const bool retVal = WrRayLib::ColorIsEqual(
        wr_color1,
        wr_color2
    );

    if (retVal)
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return hr;

}
STDMETHODIMP CoRayLib::Fade(
    IRayLibColor* color,
    float alpha,
    IRayLibColor** pRetVal
)
{
    if (!color)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLibColor retVal = WrRayLib::Fade(
        wr_color,
        alpha
    );

    hr = CoCreateInstance(
        CLSID_RayLibColor,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibColor,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_r(retVal.r);
        (*pRetVal)->put_g(retVal.g);
        (*pRetVal)->put_b(retVal.b);
        (*pRetVal)->put_a(retVal.a);
    }

    return hr;
}


//////////////////////////////////////////////
// Module: RTEXT

// Font loading/unloading functions


// Text drawing functions

STDMETHODIMP CoRayLib::DrawFPS(
    long posX,
    long posY
)
{
    WrRayLib::DrawFPS(
        (int)posX,
        (int)posY
    );

    return S_OK;
}
#undef DrawText
STDMETHODIMP CoRayLib::DrawText(
    BSTR text,
    long posX,
    long posY,
    long fontSize,
    IRayLibColor* color
)
{
    if (!text)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    char* lpsz = nullptr;

    WrRayLib::DrawText(
        lpsz = _com_util::ConvertBSTRToString(text),
        (int)posX,
        (int)posY,
        (int)fontSize,
        clr
    );

    delete[] lpsz;

    return hr;
}


// Text font info functions

STDMETHODIMP CoRayLib::SetTextLineSpacing(
    long spacing
)
{
    WrRayLib::SetTextLineSpacing(
        spacing
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::MeasureText(
    BSTR text,
    long fontSize,
    long* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = WrRayLib::MeasureText(
        lpsz = _com_util::ConvertBSTRToString(text),
        (int)fontSize
    );

    delete[] lpsz;

    return S_OK;
}


// Text strings management functions (no UTF-8 strings, only byte chars)

STDMETHODIMP CoRayLib::TextIsEqual(
    BSTR text1,
    BSTR text2,
    VARIANT_BOOL* pRetVal
)
{
    if (!text1)
        return E_POINTER;
    if (!text2)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;

    const bool result = WrRayLib::TextIsEqual(
        lpsz1 = _com_util::ConvertBSTRToString(
            text1
        ),
        lpsz2 = _com_util::ConvertBSTRToString(
            text2
        )
    );

    delete[] lpsz1;
    delete[] lpsz2;

    if (result)
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextLength(
    BSTR text,
    long* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = (long)WrRayLib::TextLength(
        lpsz = _com_util::ConvertBSTRToString(
            text
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextFormat(
    BSTR text,
    SAFEARRAY* args,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!args)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    VarArgList c_args;

    HRESULT hr = S_OK;
    long lbound = 0, ubound = -1;
    hr = SafeArrayGetLBound(args, 1, &lbound);
    if (FAILED(hr)) return hr;
    hr = SafeArrayGetUBound(args, 1, &ubound);
    if (FAILED(hr)) return hr;

    VARIANT* pVars = nullptr;
    hr = SafeArrayAccessData(args, (void**)&pVars);
    if (FAILED(hr)) return hr;
    for (long i = 0; (i <= ubound - lbound) && SUCCEEDED(hr); ++i)
    {
        VARIANT v;
        VariantInit(&v);
        if ((pVars[i].vt & VT_TYPEMASK) == VT_BSTR) {
            hr = VariantChangeType(&v, &pVars[i], 0, VT_BSTR);
            if (SUCCEEDED(hr)) {
                char* lpsz = nullptr;
                c_args.append(lpsz = _com_util::ConvertBSTRToString(v.bstrVal));
                delete[] lpsz;
            }
        }
        else if ((pVars[i].vt & VT_TYPEMASK) == VT_I2) {
            hr = VariantChangeType(&v, &pVars[i], 0, VT_I2);
            if (SUCCEEDED(hr))
                c_args.append(v.iVal);
        }
        else if ((pVars[i].vt & VT_TYPEMASK) == VT_I4) {
            hr = VariantChangeType(&v, &pVars[i], 0, VT_I4);
            if (SUCCEEDED(hr))
                c_args.append(v.intVal);
        }
        else if ((pVars[i].vt & VT_TYPEMASK) == VT_R4) {
            hr = VariantChangeType(&v, &pVars[i], 0, VT_R4);
            if (SUCCEEDED(hr))
                c_args.append(v.fltVal);
        }
        else if ((pVars[i].vt & VT_TYPEMASK) == VT_R8) {
            hr = VariantChangeType(&v, &pVars[i], 0, VT_R8);
            if (SUCCEEDED(hr))
                c_args.append(v.dblVal);
        }
        else if ((pVars[i].vt & VT_TYPEMASK) == VT_VARIANT) {
            if ((pVars[i].pvarVal->vt & VT_TYPEMASK) == VT_BSTR) {
                hr = VariantChangeType(&v, pVars[i].pvarVal, 0, VT_BSTR);
                if (SUCCEEDED(hr)) {
                    char* lpsz = nullptr;
                    c_args.append(lpsz = _com_util::ConvertBSTRToString(v.bstrVal));
                    delete[] lpsz;
                }
            }
            else if ((pVars[i].pvarVal->vt & VT_TYPEMASK) == VT_I2) {
                hr = VariantChangeType(&v, pVars[i].pvarVal, 0, VT_I2);
                if (SUCCEEDED(hr))
                    c_args.append(v.iVal);
            }
            else if ((pVars[i].pvarVal->vt & VT_TYPEMASK) == VT_I4) {
                hr = VariantChangeType(&v, pVars[i].pvarVal, 0, VT_I4);
                if (SUCCEEDED(hr))
                    c_args.append(v.intVal);
            }
            else if ((pVars[i].pvarVal->vt & VT_TYPEMASK) == VT_R4) {
                hr = VariantChangeType(&v, pVars[i].pvarVal, 0, VT_R4);
                if (SUCCEEDED(hr))
                    c_args.append(v.fltVal);
            }
            else if((pVars[i].pvarVal->vt & VT_TYPEMASK) == VT_R8) {
                hr = VariantChangeType(&v, pVars[i].pvarVal, 0, VT_R8);
                if (SUCCEEDED(hr))
                    c_args.append(v.dblVal);
            }
        }

        VariantClear(&v);
    }
    SafeArrayUnaccessData(args);

    char c_buffer[1000];
    char* lpsz = nullptr;

    vsprintf_s(
        c_buffer,
        1000,
        lpsz = _com_util::ConvertBSTRToString(text),
        c_args.get_args()
    );

    delete[] lpsz;

    *pRetVal = _com_util::ConvertStringToBSTR(c_buffer);

    return hr;
}
STDMETHODIMP CoRayLib::TextSubtext(
    BSTR text,
    long position,
    long length,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;
    
    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextSubtext(
            lpsz = _com_util::ConvertBSTRToString(text),
            (int)position,
            (int)length
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextRemoveSpaces(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextRemoveSpaces(
            lpsz = _com_util::ConvertBSTRToString(text)
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::GetTextBetween(
    BSTR text,
    BSTR begin,
    BSTR end,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!begin)
        return E_POINTER;
    if (!end)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;
    char* lpsz3 = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::GetTextBetween(
            lpsz1 = _com_util::ConvertBSTRToString(text),
            lpsz2 = _com_util::ConvertBSTRToString(begin),
            lpsz3 = _com_util::ConvertBSTRToString(end)
        )
    );

    delete[] lpsz1;
    delete[] lpsz2;
    delete[] lpsz3;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextReplace(
    BSTR text,
    BSTR search,
    BSTR replacement,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!search)
        return E_POINTER;
    if (!replacement)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;
    char* lpsz3 = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextReplace(
            lpsz1 = _com_util::ConvertBSTRToString(text),
            lpsz2 = _com_util::ConvertBSTRToString(search),
            lpsz3 = _com_util::ConvertBSTRToString(replacement)
        )
    );

    delete[] lpsz1;
    delete[] lpsz2;
    delete[] lpsz3;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextReplaceAlloc(
    BSTR text,
    BSTR search,
    BSTR replacement,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!search)
        return E_POINTER;
    if (!replacement)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;
    char* lpsz3 = nullptr;
    char* ptr = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        ptr = WrRayLib::TextReplaceAlloc(
            lpsz1 = _com_util::ConvertBSTRToString(text),
            lpsz2 = _com_util::ConvertBSTRToString(search),
            lpsz3 = _com_util::ConvertBSTRToString(replacement)
        )
    );

    WrRayLib::MemFree(
        (void*)ptr
    );

    delete[] lpsz1;
    delete[] lpsz2;
    delete[] lpsz3;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextReplaceBetween(
    BSTR text,
    BSTR begin,
    BSTR end,
    BSTR replacement,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!begin)
        return E_POINTER;
    if (!end)
        return E_POINTER;
    if (!replacement)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;
    char* lpsz3 = nullptr;
    char* lpsz4 = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextReplaceBetween(
            lpsz1 = _com_util::ConvertBSTRToString(text),
            lpsz2 = _com_util::ConvertBSTRToString(begin),
            lpsz3 = _com_util::ConvertBSTRToString(end),
            lpsz4 = _com_util::ConvertBSTRToString(replacement)
        )
    );

    delete[] lpsz1;
    delete[] lpsz2;
    delete[] lpsz3;
    delete[] lpsz4;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextReplaceBetweenAlloc(
    BSTR text,
    BSTR begin,
    BSTR end,
    BSTR replacement,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!begin)
        return E_POINTER;
    if (!end)
        return E_POINTER;
    if (!replacement)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;
    char* lpsz3 = nullptr;
    char* lpsz4 = nullptr;
    char* ptr = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        ptr = WrRayLib::TextReplaceBetweenAlloc(
            lpsz1 = _com_util::ConvertBSTRToString(text),
            lpsz2 = _com_util::ConvertBSTRToString(begin),
            lpsz3 = _com_util::ConvertBSTRToString(end),
            lpsz4 = _com_util::ConvertBSTRToString(replacement)
        )
    );

    WrRayLib::MemFree(
        (void*)ptr
    );

    delete[] lpsz1;
    delete[] lpsz2;
    delete[] lpsz3;
    delete[] lpsz4;

    return S_OK;
}

STDMETHODIMP CoRayLib::TextFindIndex(
    BSTR text,
    BSTR search,
    long* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!search)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz1 = nullptr;
    char* lpsz2 = nullptr;

    *pRetVal = (long)WrRayLib::TextFindIndex(
        lpsz1 = _com_util::ConvertBSTRToString(
            text
        ),
        lpsz2 = _com_util::ConvertBSTRToString(
            search
        )
    );

    delete[] lpsz1;
    delete[] lpsz2;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToUpper(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextToUpper(
            lpsz = _com_util::ConvertBSTRToString(
                text
            )
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToLower(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;
    
    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextToLower(
            lpsz = _com_util::ConvertBSTRToString(
                text
            )
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToPascal(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextToPascal(
            lpsz = _com_util::ConvertBSTRToString(
                text
            )
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToSnake(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextToSnake(
            lpsz = _com_util::ConvertBSTRToString(
                text
            )
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToCamel(
    BSTR text,
    BSTR* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = _com_util::ConvertStringToBSTR(
        WrRayLib::TextToCamel(
            lpsz = _com_util::ConvertBSTRToString(
                text
            )
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToInteger(
    BSTR text,
    long* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = (long)WrRayLib::TextToInteger(
        lpsz = _com_util::ConvertBSTRToString(
            text
        )
    );

    delete[] lpsz;

    return S_OK;
}
STDMETHODIMP CoRayLib::TextToFloat(
    BSTR text,
    float* pRetVal
)
{
    if (!text)
        return E_POINTER;
    if (!pRetVal)
        return E_POINTER;

    char* lpsz = nullptr;

    *pRetVal = WrRayLib::TextToFloat(
        lpsz = _com_util::ConvertBSTRToString(
            text
        )
    );

    delete[] lpsz;

    return S_OK;
}


//////////////////////////////////////////////
// Module: RMODELS

// Basic geometric 3D shapes drawing functions
STDMETHODIMP CoRayLib::DrawLine3D(
    IRayLibVector3* startPos,
    IRayLibVector3* endPos,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_startPos = { 0 };
    WrRayLibVector3 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawLine3D(
        wr_startPos,
        wr_endPos,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawPoint3D(
    IRayLibVector3* position,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_position = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPoint3D(
        wr_position,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCircle3D(
    IRayLibVector3* center,
    float radius,
    IRayLibVector3* rotationAxis,
    float rotationAngle,
    IRayLibColor* color
)
{
    if (!center)
        return E_POINTER;
    if (!rotationAxis)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_center = { 0 };
    WrRayLibVector3 wr_rotationAxis = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(center, &wr_center);
    if (FAILED(hr)) return hr;

    hr = co2wr(rotationAxis, &wr_rotationAxis);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCircle3D(
        wr_center,
        radius,
        wr_rotationAxis,
        rotationAngle,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawTriangle3D(
    IRayLibVector3* v1,
    IRayLibVector3* v2,
    IRayLibVector3* v3,
    IRayLibColor* color
)
{
    if (!v1)
        return E_POINTER;
    if (!v2)
        return E_POINTER;
    if (!v3)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_v1 = { 0 };
    WrRayLibVector3 wr_v2 = { 0 };
    WrRayLibVector3 wr_v3 = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(v1, &wr_v1);
    if (FAILED(hr)) return hr;

    hr = co2wr(v2, &wr_v2);
    if (FAILED(hr)) return hr;

    hr = co2wr(v3, &wr_v3);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawTriangle3D(
        wr_v1,
        wr_v2,
        wr_v3,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCube(
    IRayLibVector3* position,
    float width,
    float height,
    float length,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_pos = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(position, &wr_pos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCube(
        wr_pos,
        width,
        height,
        length,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCubeV(
    IRayLibVector3* position,
    IRayLibVector3* size,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!size)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_pos = { 0 };
    WrRayLibVector3 wr_siz = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(position, &wr_pos);
    if (FAILED(hr)) return hr;

    hr = co2wr(size, &wr_siz);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCubeV(
        wr_pos,
        wr_siz,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCubeWires(
    IRayLibVector3* position,
    float width,
    float height,
    float length,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_pos = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(position, &wr_pos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCubeWires(
        wr_pos,
        width,
        height,
        length,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCubeWiresV(
    IRayLibVector3* position,
    IRayLibVector3* size,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!size)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_pos = { 0 };
    WrRayLibVector3 wr_siz = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(position, &wr_pos);
    if (FAILED(hr)) return hr;

    hr = co2wr(size, &wr_siz);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCubeWiresV(
        wr_pos,
        wr_siz,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawSphere(
    IRayLibVector3* centerPos,
    float radius,
    IRayLibColor* color
)
{
    if (!centerPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_centerPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(centerPos, &wr_centerPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawSphere(
        wr_centerPos,
        radius,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawSphereEx(
    IRayLibVector3* centerPos,
    float radius,
    long rings,
    long slices,
    IRayLibColor* color
)
{
    if (!centerPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_centerPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(centerPos, &wr_centerPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawSphereEx(
        wr_centerPos,
        radius,
        (int)rings,
        (int)slices,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawSphereWires(
    IRayLibVector3* centerPos,
    float radius,
    long rings,
    long slices,
    IRayLibColor* color
)
{
    if (!centerPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_centerPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(centerPos, &wr_centerPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawSphereWires(
        wr_centerPos,
        radius,
        (int)rings,
        (int)slices,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCylinder(
    IRayLibVector3* position,
    float radiusTop,
    float radiusBottom,
    float height,
    long slices,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_position = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCylinder(
        wr_position,
        radiusTop,
        radiusBottom,
        height,
        (int)slices,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCylinderEx(
    IRayLibVector3* startPos,
    IRayLibVector3* endPos,
    float startRadius,
    float endRadius,
    long sides,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_startPos = { 0 };
    WrRayLibVector3 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCylinderEx(
        wr_startPos,
        wr_endPos,
        startRadius,
        endRadius,
        (int)sides,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCylinderWires(
    IRayLibVector3* position,
    float radiusTop,
    float radiusBottom,
    float height,
    long slices,
    IRayLibColor* color
)
{
    if (!position)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_position = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(position, &wr_position);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCylinderWires(
        wr_position,
        radiusTop,
        radiusBottom,
        height,
        (int)slices,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCylinderWiresEx(
    IRayLibVector3* startPos,
    IRayLibVector3* endPos,
    float startRadius,
    float endRadius,
    long sides,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_startPos = { 0 };
    WrRayLibVector3 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCylinderWiresEx(
        wr_startPos,
        wr_endPos,
        startRadius,
        endRadius,
        (int)sides,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCapsule(
    IRayLibVector3* startPos,
    IRayLibVector3* endPos,
    float radius,
    long slices,
    long rings,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_startPos = { 0 };
    WrRayLibVector3 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCapsule(
        wr_startPos,
        wr_endPos,
        radius,
        (int)slices,
        (int)rings,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawCapsuleWires(
    IRayLibVector3* startPos,
    IRayLibVector3* endPos,
    float radius,
    long slices,
    long rings,
    IRayLibColor* color
)
{
    if (!startPos)
        return E_POINTER;
    if (!endPos)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_startPos = { 0 };
    WrRayLibVector3 wr_endPos = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(startPos, &wr_startPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(endPos, &wr_endPos);
    if (FAILED(hr)) return hr;
    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawCapsuleWires(
        wr_startPos,
        wr_endPos,
        radius,
        (int)slices,
        (int)rings,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawPlane(
    IRayLibVector3* centerPos,
    IRayLibVector2* size,
    IRayLibColor* color
)
{
    if (!centerPos)
        return E_POINTER;
    if (!size)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibVector3 wr_centerPos = { 0 };
    WrRayLibVector2 wr_size = { 0 };
    WrRayLibColor wr_color = { 0 };

    hr = co2wr(centerPos, &wr_centerPos);
    if (FAILED(hr)) return hr;

    hr = co2wr(size, &wr_size);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_color);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawPlane(
        wr_centerPos,
        wr_size,
        wr_color
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawRay(
    IRayLibRay* ray,
    IRayLibColor* color
)
{
    if (!ray)
        return E_POINTER;
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibRay wr_ray = { 0 };
    WrRayLibColor wr_clr = { 0 };

    hr = co2wr(ray, &wr_ray);
    if (FAILED(hr)) return hr;

    hr = co2wr(color, &wr_clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawRay(
        wr_ray,
        wr_clr
    );

    return hr;
}
STDMETHODIMP CoRayLib::DrawGrid(
    long slices,
    float spacing
)
{
    WrRayLib::DrawGrid(
        (int)slices,
        spacing
    );

    return S_OK;
}


//////////////////////////////////////////////
// Module: RAUDIO

// Audio device management functions
STDMETHODIMP CoRayLib::InitAudioDevice(
    void
)
{
    WrRayLib::InitAudioDevice();

    return S_OK;
}
STDMETHODIMP CoRayLib::CloseAudioDevice(
    void
)
{
    WrRayLib::CloseAudioDevice();

    return S_OK;
}
STDMETHODIMP CoRayLib::IsAudioDeviceReady(
    VARIANT_BOOL* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    if (WrRayLib::IsAudioDeviceReady())
        *pRetVal = VARIANT_TRUE;
    else
        *pRetVal = VARIANT_FALSE;

    return S_OK;
}
STDMETHODIMP CoRayLib::SetMasterVolume(
    float volume
)
{
    WrRayLib::SetMasterVolume(
        volume
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetMasterVolume(
    float* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = WrRayLib::GetMasterVolume();

    return S_OK;
}


//////////////////////////////////////////////
// CoRayLib helpers
STDMETHODIMP CoRayLib::CreateColor(
    long r,
    long g,
    long b,
    long a,
    IRayLibColor** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibColor,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibColor,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_r(r);
        (*pRetVal)->put_g(g);
        (*pRetVal)->put_b(b);
        (*pRetVal)->put_a(a);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateVector2(
    float x,
    float y,
    IRayLibVector2** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector2,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector2,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_x(x);
        (*pRetVal)->put_y(y);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateVector3(
    float x,
    float y,
    float z,
    IRayLibVector3** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector3,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector3,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_x(x);
        (*pRetVal)->put_y(y);
        (*pRetVal)->put_z(z);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateVector4(
    float x,
    float y,
    float z,
    float w,
    IRayLibVector4** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibVector4,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector4,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_x(x);
        (*pRetVal)->put_y(y);
        (*pRetVal)->put_z(z);
        (*pRetVal)->put_w(w);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateQuaternion(
    float x,
    float y,
    float z,
    float w,
    IRayLibVector4** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibQuaternion,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibVector4,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_x(x);
        (*pRetVal)->put_y(y);
        (*pRetVal)->put_z(z);
        (*pRetVal)->put_w(w);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateRectangle(
    float x,
    float y,
    float width,
    float height,
    IRayLibRectangle** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    const HRESULT hr = CoCreateInstance(
        CLSID_RayLibRectangle,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRectangle,
        (LPVOID*)pRetVal
    );

    if (SUCCEEDED(hr)) {
        (*pRetVal)->put_x(x);
        (*pRetVal)->put_y(y);
        (*pRetVal)->put_width(width);
        (*pRetVal)->put_height(height);
    }

    return hr;
}
STDMETHODIMP CoRayLib::CreateMatrix(
    IRayLibMatrix** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    return CoCreateInstance(
        CLSID_RayLibMatrix,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibMatrix,
        (LPVOID*)pRetVal
    );
}
STDMETHODIMP CoRayLib::CreateCamera2D(
    IRayLibCamera2D** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    return CoCreateInstance(
        CLSID_RayLibCamera2D,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibCamera2D,
        (LPVOID*)pRetVal
    );
}
STDMETHODIMP CoRayLib::CreateCamera3D(
    IRayLibCamera3D** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    return CoCreateInstance(
        CLSID_RayLibCamera3D,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibCamera3D,
        (LPVOID*)pRetVal
    );
}
STDMETHODIMP CoRayLib::CreateTexture(
    IRayLibTexture** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    return CoCreateInstance(
        CLSID_RayLibTexture,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibTexture,
        (LPVOID*)pRetVal
    );
}
STDMETHODIMP CoRayLib::CreateRenderTexture(
    IRayLibRenderTexture** pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

    *pRetVal = NULL;

    return CoCreateInstance(
        CLSID_RayLibRenderTexture,
        NULL,
        CLSCTX_INPROC_SERVER,
        IID_IRayLibRenderTexture,
        (LPVOID*)pRetVal
    );
}