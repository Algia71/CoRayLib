// CoRayLib.cpp
//

#include "CoRayLib.h"
#include "tlhelper.h"
#include "comutil.h"
#include <time.h>


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
    out->y = elem;

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
    WrRayLib::InitWindow(
        (int)width,
        (int)height,
        _com_util::ConvertBSTRToString(title)
    );

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
    WrRayLib::SetWindowTitle(
        _com_util::ConvertBSTRToString(title)
    );

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
    WrRayLib::SetClipboardText(
        _com_util::ConvertBSTRToString(text)
    );

    return S_OK;
}
STDMETHODIMP CoRayLib::GetClipboardText(
    BSTR* pRetVal
)
{
    if (!pRetVal)
        return E_POINTER;

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

HRESULT CoRayLib::TakeScreenshot(
    BSTR fileName
)
{
    WrRayLib::TakeScreenshot(
        _com_util::ConvertBSTRToString(fileName)
    );

    return S_OK;
}
HRESULT CoRayLib::SetConfigFlags(
    long flags
)
{
    WrRayLib::SetConfigFlags(
        (unsigned int)flags
    );

    return S_OK;
}
HRESULT CoRayLib::OpenURL(
    BSTR url
)
{
    WrRayLib::OpenURL(
        _com_util::ConvertBSTRToString(url)
    );

    return S_OK;
}


// Logging system

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

    *pRetVal = WrRayLib::SetGamepadMappings(
        _com_util::ConvertBSTRToString(mappings)
    );

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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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

    return S_OK;
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
    if (!color)
        return E_POINTER;

    HRESULT hr = S_OK;
    WrRayLibColor clr = { 0 };

    hr = co2wr(color, &clr);
    if (FAILED(hr)) return hr;

    WrRayLib::DrawText(
        _com_util::ConvertBSTRToString(text),
        (int)posX,
        (int)posY,
        (int)fontSize,
        clr
    );

    return S_OK;
}


//////////////////////////////////////////////
// Module: RMODELS


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
