// CoRayLib.h
//

#ifndef _CORAYLIB_H
#define _CORAYLIB_H

#include "CoRayLib_h.h"
#include "WrRayLib.h"


class CoRayLib : IRayLib
{
    LONG m_cRef;
    ITypeInfo* m_pTypeInfo;

    inline HRESULT co2wr(IRayLibColor* in, WrRayLibColor* out);
    inline HRESULT co2wr(IRayLibVector2* in, WrRayLibVector2* out);
    inline HRESULT co2wr(IRayLibVector3* in, WrRayLibVector3* out);
    inline HRESULT co2wr(IRayLibVector4* in, WrRayLibVector4* out);
    inline HRESULT co2wr(IRayLibRectangle* in, WrRayLibRectangle* out);
    inline HRESULT co2wr(IRayLibCamera2D* in, WrRayLibCamera2D* out);
    inline HRESULT co2wr(IRayLibCamera3D* in, WrRayLibCamera3D* out);

    inline HRESULT wr2co(WrRayLibColor* in, IRayLibColor* out);
    inline HRESULT wr2co(WrRayLibVector2* in, IRayLibVector2* out);
    inline HRESULT wr2co(WrRayLibVector3* in, IRayLibVector3* out);
    inline HRESULT wr2co(WrRayLibVector4* in, IRayLibVector4* out);
    inline HRESULT wr2co(WrRayLibRectangle* in, IRayLibRectangle* out);
    inline HRESULT wr2co(WrRayLibCamera2D* in, IRayLibCamera2D* out);
    inline HRESULT wr2co(WrRayLibCamera3D* in, IRayLibCamera3D* out);

public:
    CoRayLib(HMODULE hModule);
    ~CoRayLib();

    // IUnknown
    STDMETHODIMP QueryInterface(
        REFIID riid,
        void** ppvObject
    ) override;
    STDMETHODIMP_(ULONG) AddRef(
        void
    ) override;
    STDMETHODIMP_(ULONG) Release(
        void
    ) override;

    // IDispatch
    STDMETHODIMP GetTypeInfoCount(
        UINT* pctinfo
    ) override;
    STDMETHODIMP GetTypeInfo(
        UINT iTInfo,
        LCID lcid,
        ITypeInfo** ppTInfo
    ) override;
    STDMETHODIMP GetIDsOfNames(
        REFIID riid,
        LPOLESTR* rgszNames,
        UINT cNames,
        LCID lcid,
        DISPID* rgDispId
    ) override;
    STDMETHODIMP Invoke(
        DISPID dispIdMember,
        REFIID riid,
        LCID lcid, WORD wFlags,
        DISPPARAMS* pDispParams,
        VARIANT* pVarResult,
        EXCEPINFO* pExcepInfo,
        UINT* puArgErr
    ) override;

    /////////////////////////////////////////////
    // IRayLib

    //////////////////////////////////////////////
    // Module: RCORE

    // Window-related functions
    STDMETHODIMP InitWindow(
        long width,
        long height,
        BSTR title
    ) override;
    STDMETHODIMP CloseWindow(
        void
    ) override;
    STDMETHODIMP WindowShouldClose(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowReady(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowFullscreen(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowHidden(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowMinimized(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowMaximized(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowFocused(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowResized(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsWindowState(
        long flag,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP SetWindowState(
        long flags
    ) override;
    STDMETHODIMP ClearWindowState(
        long flags
    ) override;
    STDMETHODIMP ToggleFullscreen(
        void
    ) override;
    STDMETHODIMP ToggleBorderlessWindowed(
        void
    ) override;
    STDMETHODIMP MaximizeWindow(
        void
    ) override;
    STDMETHODIMP MinimizeWindow(
        void
    ) override;
    STDMETHODIMP RestoreWindow(
        void
    ) override;

    STDMETHODIMP SetWindowTitle(
        BSTR title
    ) override;
    STDMETHODIMP SetWindowPosition(
        long x,
        long y
    ) override;
    STDMETHODIMP SetWindowMonitor(
        long monitor
    ) override;
    STDMETHODIMP SetWindowMinSize(
        long width,
        long height
    ) override;
    STDMETHODIMP SetWindowMaxSize(
        long width,
        long height
    ) override;
    STDMETHODIMP SetWindowSize(
        long width,
        long height
    ) override;
    STDMETHODIMP SetWindowOpacity(
        float opacity
    ) override;
    STDMETHODIMP SetWindowFocused(
        void
    ) override;

    STDMETHODIMP GetScreenWidth(
        long* pRetVal
    ) override;
    STDMETHODIMP GetScreenHeight(
        long* pRetVal
    ) override;
    STDMETHODIMP GetRenderWidth(
        long* pRetVal
    ) override;
    STDMETHODIMP GetRenderHeight(
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorCount(
        long* pRetVal
    ) override;
    STDMETHODIMP GetCurrentMonitor(
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorPosition(
        long monitor,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetMonitorWidth(
        long monitor,
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorHeight(
        long monitor,
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorPhysicalWidth(
        long monitor,
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorPhysicalHeight(
        long monitor,
        long* pRetVal
    ) override;
    STDMETHODIMP GetMonitorRefreshRate(
        long monitor,
        long* pRetVal
    ) override;
    STDMETHODIMP GetWindowPosition(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetWindowScaleDPI(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetMonitorName(
        long monitor,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP SetClipboardText(
        BSTR text
    ) override;
    STDMETHODIMP GetClipboardText(
        BSTR* pRetVal
    ) override;

    STDMETHODIMP EnableEventWaiting(
        void
    ) override;
    STDMETHODIMP DisableEventWaiting(
        void
    ) override;


    // Cursor-related functions
    STDMETHODIMP ShowCursor(
        void
    ) override;
    STDMETHODIMP HideCursor(
        void
    ) override;
    STDMETHODIMP IsCursorHidden(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP EnableCursor(
        void
    ) override;
    STDMETHODIMP DisableCursor(
        void
    ) override;
    STDMETHODIMP IsCursorOnScreen(
        VARIANT_BOOL* pRetVal
    ) override;

    // Drawing-related functions
    STDMETHODIMP ClearBackground(
        IRayLibColor* color
    ) override;
    STDMETHODIMP BeginDrawing(
        void
    ) override;
    STDMETHODIMP EndDrawing(
        void
    ) override;
    STDMETHODIMP BeginMode2D(
        IRayLibCamera2D* camera
    ) override;
    STDMETHODIMP EndMode2D(
        void
    ) override;
    STDMETHODIMP BeginMode3D(
        IRayLibCamera3D* camera
    ) override;
    STDMETHODIMP EndMode3D(
        void
    ) override;
    STDMETHODIMP BeginBlendMode(
        long mode
    ) override;
    STDMETHODIMP EndBlendMode(
        void
    ) override;
    STDMETHODIMP BeginScissorMode(
        long x,
        long y,
        long width,
        long height
    ) override;
    STDMETHODIMP EndScissorMode(
        void
    ) override;

    // VR stereo config functions for VR simulator

    // Shader management functions

    // Screen-space-related functions

    // Timing-related functions
    STDMETHODIMP SetTargetFPS(
        long fps
    ) override;
    STDMETHODIMP GetFrameTime(
        float* pRetVal
    ) override;
    STDMETHODIMP GetTime(
        double* pRetVal
    ) override;
    STDMETHODIMP GetFPS(
        long* pRetVal
    ) override;

    // Custom frame control functions
    STDMETHODIMP SwapScreenBuffer(
        void
    ) override;
    STDMETHODIMP PollInputEvents(
        void
    ) override;
    STDMETHODIMP WaitTime(
        double seconds
    ) override;

    // Random values generation functions
    STDMETHODIMP SetRandomSeed(
        long seed
    ) override;
    STDMETHODIMP GetRandomValue(
        long min,
        long max,
        long* pRetVal
    ) override;

    // Misc. functions
    HRESULT TakeScreenshot(
        BSTR fileName
    ) override;
    HRESULT SetConfigFlags(
        long flags
    ) override;
    HRESULT OpenURL(
        BSTR url
    ) override;

    // Logging system

    // Memory management, using internal allocators

    // File system management functions

    // File access custom callbacks

    // Compression/Encoding functionality

    // Automation events functionality

    // Input-related functions: keyboard
    STDMETHODIMP IsKeyPressed(
        long key,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsKeyPressedRepeat(
        long key,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsKeyDown(
        long key,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsKeyReleased(
        long key,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsKeyUp(
        long key,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP GetKeyPressed(
        long* pRetVal
    ) override;
    STDMETHODIMP GetCharPressed(
        long* pRetVal
    ) override;
    STDMETHODIMP SetExitKey(
        long key
    ) override;

    // Input-related functions: gamepads
    STDMETHODIMP IsGamepadAvailable(
        long gamepad,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP GetGamepadName(
        long gamepad,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP IsGamepadButtonPressed(
        long gamepad,
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsGamepadButtonDown(
        long gamepad,
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsGamepadButtonReleased(
        long gamepad,
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsGamepadButtonUp(
        long gamepad,
        long button,
        VARIANT_BOOL* pRetVal) override;
    STDMETHODIMP GetGamepadButtonPressed(
        long* pRetVal
    ) override;
    STDMETHODIMP GetGamepadAxisCount(
        long gamepad,
        long* pRetVal
    ) override;
    STDMETHODIMP GetGamepadAxisMovement(
        long gamepad,
        long axis,
        float* pRetVal
    ) override;
    STDMETHODIMP SetGamepadMappings(
        BSTR mappings,
        long* pRetVal
    ) override;
    STDMETHODIMP SetGamepadVibration(
        long gamepad,
        float leftMotor,
        float rightMotor,
        float duration
    ) override;

    // Input-related functions: mouse
    STDMETHODIMP IsMouseButtonPressed(
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsMouseButtonDown(long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsMouseButtonReleased(
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP IsMouseButtonUp(
        long button,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP GetMouseX(
        long* pRetVal
    ) override;
    STDMETHODIMP GetMouseY(
        long* pRetVal
    ) override;
    STDMETHODIMP GetMousePosition(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetMouseDelta(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP SetMousePosition(
        long x,
        long y
    ) override;
    STDMETHODIMP SetMouseOffset(
        long offsetX,
        long offsetY
    ) override;
    STDMETHODIMP SetMouseScale(
        float scaleX,
        float scaleY
    ) override;
    STDMETHODIMP GetMouseWheelMove(
        float* pRetVal
    ) override;
    STDMETHODIMP GetMouseWheelMoveV(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP SetMouseCursor(
        long cursor
    ) override;

    // Input-related functions: touch
    STDMETHODIMP GetTouchX(
        long* pRetVal
    ) override;
    STDMETHODIMP GetTouchY(
        long* pRetVal
    ) override;
    STDMETHODIMP GetTouchPosition(
        long index,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetTouchPointId(
        long index,
        long* pRetVal
    ) override;
    STDMETHODIMP GetTouchPointCount(
        long* pRetVal
    ) override;

    // Gestures and Touch Handling Functions (Module: rgestures)
    STDMETHODIMP SetGesturesEnabled(
        long flags
    ) override;
    STDMETHODIMP IsGestureDetected(
        long gesture,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP GetGestureDetected(
        long* pRetVal
    ) override;
    STDMETHODIMP GetGestureHoldDuration(
        float* pRetVal
    ) override;
    STDMETHODIMP GetGestureDragVector(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetGestureDragAngle(
        float* pRetVal
    ) override;
    STDMETHODIMP GetGesturePinchVector(
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetGesturePinchAngle(
        float* pRetVal
    ) override;

    // Camera System Functions (Module: rcamera)
    STDMETHODIMP UpdateCamera(
        IRayLibCamera3D* camera,
        long mode
    ) override;
    STDMETHODIMP UpdateCameraPro(
        IRayLibCamera3D* camera,
        IRayLibVector3* movement,
        IRayLibVector3* rotation,
        float zoom
    ) override;

    //////////////////////////////////////////////
    // Module: RSHAPES

    // Basic shapes drawing functions
    STDMETHODIMP DrawPixel(
        long posX,
        long posY,
        IRayLibColor* color
    );
    STDMETHODIMP DrawPixelV(
        IRayLibVector2* position,
        IRayLibColor* color
    );
    STDMETHODIMP DrawLine(
        long startPosX,
        long startPosY,
        long endPosX,
        long endPosY,
        IRayLibColor* color
    );
    STDMETHODIMP DrawLineV(
        IRayLibVector2* startPos,
        IRayLibVector2* endPos,
        IRayLibColor* color
    );
    STDMETHODIMP DrawLineEx(
        IRayLibVector2* startPos,
        IRayLibVector2* endPos,
        float thick,
        IRayLibColor* color
    );
    STDMETHODIMP DrawCircle(
        long centerX,
        long centerY,
        float radius,
        IRayLibColor* color
    );
    STDMETHODIMP DrawCircleV(
        IRayLibVector2* center,
        float radius,
        IRayLibColor* color
    );
    STDMETHODIMP DrawCircleLines(
        long centerX,
        long centerY,
        float radius,
        IRayLibColor* color
    );
    STDMETHODIMP DrawCircleLinesV(
        IRayLibVector2* center,
        float radius,
        IRayLibColor* color
    );
    STDMETHODIMP DrawEllipse(
        long centerX,
        long centerY,
        float radiusH,
        float radiusV,
        IRayLibColor* color);
    STDMETHODIMP DrawEllipseV(
        IRayLibVector2* center,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    );
    STDMETHODIMP DrawEllipseLines(
        long centerX,
        long centerY,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    );
    STDMETHODIMP DrawEllipseLinesV(
        IRayLibVector2* center,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    );
    STDMETHODIMP DrawRectangle(
        long posX,
        long posY,
        long width,
        long height,
        IRayLibColor* color
    );
    STDMETHODIMP DrawRectangleV(
        IRayLibVector2* position,
        IRayLibVector2* size,
        IRayLibColor* color
    );
    STDMETHODIMP DrawRectangleRec(
        IRayLibRectangle* rec,
        IRayLibColor* color
    );
    STDMETHODIMP DrawTriangle(
        IRayLibVector2* v1,
        IRayLibVector2* v2,
        IRayLibVector2* v3,
        IRayLibColor* color
    );
    STDMETHODIMP DrawTriangleLines(
        IRayLibVector2* v1,
        IRayLibVector2* v2,
        IRayLibVector2* v3,
        IRayLibColor* color
    );
    STDMETHODIMP DrawPoly(
        IRayLibVector2* center,
        long sides,
        float radius,
        float rotation,
        IRayLibColor* color
    );
    STDMETHODIMP DrawPolyLines(
        IRayLibVector2* center,
        long sides,
        float radius,
        float rotation,
        IRayLibColor* color
    );
    
    // Basic shapes collision detection functions
    STDMETHODIMP CheckCollisionRecs(
        IRayLibRectangle* rec1,
        IRayLibRectangle* rec2,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionCircles(
        IRayLibVector2* center1,
        float radius1,
        IRayLibVector2* center2,
        float radius2,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionCircleRec(
        IRayLibVector2* center,
        float radius,
        IRayLibRectangle* rec,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionCircleLine(
        IRayLibVector2* center,
        float radius,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionPointRec(
        IRayLibVector2* point,
        IRayLibRectangle* rec,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionPointCircle(
        IRayLibVector2* point,
        IRayLibVector2* center,
        float radius,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionPointTriangle(
        IRayLibVector2* point,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        IRayLibVector2* p3,
        VARIANT_BOOL* pRetVal
    );
    STDMETHODIMP CheckCollisionPointLine(
        IRayLibVector2* point,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        long threshold,
        VARIANT_BOOL* pRetVal
    );


    //////////////////////////////////////////////
    // Module: RTEXT

    // Font loading/unloading functions

    // Text drawing functions
    STDMETHODIMP DrawFPS(
        long posX,
        long posY
    ) override;
    STDMETHODIMP DrawText(
        BSTR text,
        long posX,
        long posY,
        long fontSize,
        IRayLibColor* color
    ) override;


    //////////////////////////////////////////////
    // CoRayLib helpers
    STDMETHODIMP CreateColor(
        long r,
        long g,
        long b,
        long a,
        IRayLibColor** pRetVal
    );
    STDMETHODIMP CreateVector2(
        float x,
        float y,
        IRayLibVector2** pRetVal
    );
    STDMETHODIMP CreateVector3(
        float x,
        float y,
        float z,
        IRayLibVector3** pRetVal
    );
    STDMETHODIMP CreateVector4(
        float x,
        float y,
        float z,
        float w,
        IRayLibVector4** pRetVal
    );
    STDMETHODIMP CreateQuaternion(
        float x,
        float y,
        float z,
        float w,
        IRayLibVector4** pRetVal
    );
    STDMETHODIMP CreateRectangle(
        float x,
        float y,
        float width,
        float height,
        IRayLibRectangle** pRetVal
    );
};

#endif // _CORAYLIB_H
