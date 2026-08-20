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
    inline HRESULT co2wr(IRayLibRay* in, WrRayLibRay* out);

    inline HRESULT wr2co(WrRayLibColor* in, IRayLibColor* out);
    inline HRESULT wr2co(WrRayLibVector2* in, IRayLibVector2* out);
    inline HRESULT wr2co(WrRayLibVector3* in, IRayLibVector3* out);
    inline HRESULT wr2co(WrRayLibVector4* in, IRayLibVector4* out);
    inline HRESULT wr2co(WrRayLibRectangle* in, IRayLibRectangle* out);
    inline HRESULT wr2co(WrRayLibCamera2D* in, IRayLibCamera2D* out);
    inline HRESULT wr2co(WrRayLibCamera3D* in, IRayLibCamera3D* out);
    inline HRESULT wr2co(WrRayLibRay* in, IRayLibRay* out);
    inline HRESULT wr2co(WrRayLibMatrix* in, IRayLibMatrix* out);

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
    STDMETHODIMP GetScreenToWorldRay(
        IRayLibVector2* position,
        IRayLibCamera3D* camera,
        IRayLibRay** pRetVal
    ) override;
    STDMETHODIMP GetScreenToWorldRayEx(
        IRayLibVector2* position,
        IRayLibCamera3D* camera,
        long width,
        long height,
        IRayLibRay** pRetVal
    ) override;
    STDMETHODIMP GetWorldToScreen(
        IRayLibVector3* position,
        IRayLibCamera3D* camera,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetWorldToScreenEx(
        IRayLibVector3* position,
        IRayLibCamera3D* camera,
        long width,
        long height,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetWorldToScreen2D(
        IRayLibVector2* position,
        IRayLibCamera2D* camera,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetScreenToWorld2D(
        IRayLibVector2* position,
        IRayLibCamera2D* camera,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP GetCameraMatrix(
        IRayLibCamera3D* camera,
        IRayLibMatrix** pRetVal
    ) override;
    STDMETHODIMP GetCameraMatrix2D(
        IRayLibCamera2D* camera,
        IRayLibMatrix** pRetVal
    ) override;

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
    STDMETHODIMP TakeScreenshot(
        BSTR fileName
    ) override;
    STDMETHODIMP SetConfigFlags(
        long flags
    ) override;
    STDMETHODIMP OpenURL(
        BSTR url
    ) override;

    // Logging system
    STDMETHODIMP SetTraceLogLevel(
        long logLevel
    ) override;

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
    ) override;
    STDMETHODIMP DrawPixelV(
        IRayLibVector2* position,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawLine(
        long startPosX,
        long startPosY,
        long endPosX,
        long endPosY,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawLineV(
        IRayLibVector2* startPos,
        IRayLibVector2* endPos,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawLineEx(
        IRayLibVector2* startPos,
        IRayLibVector2* endPos,
        float thick,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCircle(
        long centerX,
        long centerY,
        float radius,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCircleV(
        IRayLibVector2* center,
        float radius,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCircleLines(
        long centerX,
        long centerY,
        float radius,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCircleLinesV(
        IRayLibVector2* center,
        float radius,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawEllipse(
        long centerX,
        long centerY,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawEllipseV(
        IRayLibVector2* center,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawEllipseLines(
        long centerX,
        long centerY,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawEllipseLinesV(
        IRayLibVector2* center,
        float radiusH,
        float radiusV,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangle(
        long posX,
        long posY,
        long width,
        long height,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleV(
        IRayLibVector2* position,
        IRayLibVector2* size,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleRec(
        IRayLibRectangle* rec,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectanglePro(
        IRayLibRectangle* rec,
        IRayLibVector2* origin,
        float rotation,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleGradientV(
        long posX,
        long posY,
        long width,
        long height,
        IRayLibColor* top,
        IRayLibColor* bottom
    ) override;
    STDMETHODIMP DrawRectangleGradientH(
        long posX,
        long posY,
        long width,
        long height,
        IRayLibColor* left,
        IRayLibColor* right
    ) override;
    STDMETHODIMP DrawRectangleGradientEx(
        IRayLibRectangle* rec,
        IRayLibColor* topLeft,
        IRayLibColor* bottomLeft,
        IRayLibColor* bottomRight,
        IRayLibColor* topRight
    ) override;
    STDMETHODIMP DrawRectangleLines(
        long posX,
        long posY,
        long width,
        long height,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleLinesEx(
        IRayLibRectangle* rec,
        float lineThick,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleRounded(
        IRayLibRectangle* rec,
        float roundness,
        long segments,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleRoundedLines(
        IRayLibRectangle* rec,
        float roundness,
        long segments,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRectangleRoundedLinesEx(
        IRayLibRectangle* rec,
        float roundness,
        long segments,
        float lineThick,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawTriangle(
        IRayLibVector2* v1,
        IRayLibVector2* v2,
        IRayLibVector2* v3,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawTriangleLines(
        IRayLibVector2* v1,
        IRayLibVector2* v2,
        IRayLibVector2* v3,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawPoly(
        IRayLibVector2* center,
        long sides,
        float radius,
        float rotation,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawPolyLines(
        IRayLibVector2* center,
        long sides,
        float radius,
        float rotation,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawPolyLinesEx(
        IRayLibVector2* center,
        long sides,
        float radius,
        float rotation,
        float lineThick,
        IRayLibColor* color
    ) override;

    // Basic shapes collision detection functions
    STDMETHODIMP CheckCollisionRecs(
        IRayLibRectangle* rec1,
        IRayLibRectangle* rec2,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionCircles(
        IRayLibVector2* center1,
        float radius1,
        IRayLibVector2* center2,
        float radius2,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionCircleRec(
        IRayLibVector2* center,
        float radius,
        IRayLibRectangle* rec,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionCircleLine(
        IRayLibVector2* center,
        float radius,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionPointRec(
        IRayLibVector2* point,
        IRayLibRectangle* rec,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionPointCircle(
        IRayLibVector2* point,
        IRayLibVector2* center,
        float radius,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionPointTriangle(
        IRayLibVector2* point,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        IRayLibVector2* p3,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP CheckCollisionPointLine(
        IRayLibVector2* point,
        IRayLibVector2* p1,
        IRayLibVector2* p2,
        long threshold,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP GetCollisionRec(
        IRayLibRectangle* rec1,
        IRayLibRectangle* rec2,
        IRayLibRectangle** pRetVal
    ) override;

    // Color/pixel related functions
    STDMETHODIMP ColorIsEqual(
        IRayLibColor* col1,
        IRayLibColor* col2,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP Fade(
        IRayLibColor* color,
        float alpha,
        IRayLibColor** pRetVal
    ) override;


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

    // Text font info functions
    STDMETHODIMP SetTextLineSpacing(
        long spacing
    ) override;
    STDMETHODIMP MeasureText(
        BSTR text,
        long fontSize,
        long* pRetVal
    ) override;

    // Text strings management functions (no UTF-8 strings, only byte chars)
    STDMETHODIMP TextIsEqual(
        BSTR text1,
        BSTR text2,
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP TextLength(
        BSTR text,
        long* pRetVal
    ) override;
    STDMETHODIMP TextFormat(
        BSTR text,
        SAFEARRAY* args,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextSubtext(
        BSTR text,
        long position,
        long length,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextRemoveSpaces(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP GetTextBetween(
        BSTR text,
        BSTR begin,
        BSTR end,
        BSTR* pRetVal
    ) override;

    STDMETHODIMP TextFindIndex(
        BSTR text,
        BSTR search,
        long* pRetVal
    ) override;
    STDMETHODIMP TextToUpper(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextToLower(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextToPascal(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextToSnake(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextToCamel(
        BSTR text,
        BSTR* pRetVal
    ) override;
    STDMETHODIMP TextToInteger(
        BSTR text,
        long* pRetVal
    ) override;
    STDMETHODIMP TextToFloat(
        BSTR text,
        float* pRetVal
    ) override;


    //////////////////////////////////////////////
    // Module: RMODELS

    // Basic geometric 3D shapes drawing functions
    STDMETHODIMP DrawLine3D(
        IRayLibVector3* startPos,
        IRayLibVector3* endPos,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawPoint3D(
        IRayLibVector3* position,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCircle3D(
        IRayLibVector3* center,
        float radius,
        IRayLibVector3* rotationAxis,
        float rotationAngle,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawTriangle3D(
        IRayLibVector3* v1,
        IRayLibVector3* v2,
        IRayLibVector3* v3,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCube(
        IRayLibVector3* position,
        float width,
        float height,
        float length,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCubeV(
        IRayLibVector3* position,
        IRayLibVector3* size,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCubeWires(
        IRayLibVector3* position, 
        float width,
        float height,
        float length,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCubeWiresV(
        IRayLibVector3* position,
        IRayLibVector3* size,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawSphere(
        IRayLibVector3* centerPos,
        float radius,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawSphereEx(
        IRayLibVector3* centerPos,
        float radius,
        long rings,
        long slices,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawSphereWires(
        IRayLibVector3* centerPos,
        float radius,
        long rings,
        long slices,
        IRayLibColor* color
    ) override;

    STDMETHODIMP DrawCapsule(
        IRayLibVector3* startPos,
        IRayLibVector3* endPos,
        float radius,
        long slices,
        long rings,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawCapsuleWires(
        IRayLibVector3* startPos,
        IRayLibVector3* endPos,
        float radius,
        long slices,
        long rings,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawPlane(
        IRayLibVector3* centerPos,
        IRayLibVector2* size,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawRay(
        IRayLibRay* ray,
        IRayLibColor* color
    ) override;
    STDMETHODIMP DrawGrid(
        long slices,
        float spacing
    ) override;


    //////////////////////////////////////////////
    // Module: RAUDIO

    // Audio device management functions
    STDMETHODIMP InitAudioDevice(
        void
    ) override;
    STDMETHODIMP CloseAudioDevice(
        void
    ) override;
    STDMETHODIMP IsAudioDeviceReady(
        VARIANT_BOOL* pRetVal
    ) override;
    STDMETHODIMP SetMasterVolume(
        float volume
    ) override;
    STDMETHODIMP GetMasterVolume(
        float* pRetVal
    ) override;


    //////////////////////////////////////////////
    // CoRayLib helpers
    STDMETHODIMP CreateColor(
        long r,
        long g,
        long b,
        long a,
        IRayLibColor** pRetVal
    ) override;
    STDMETHODIMP CreateVector2(
        float x,
        float y,
        IRayLibVector2** pRetVal
    ) override;
    STDMETHODIMP CreateVector3(
        float x,
        float y,
        float z,
        IRayLibVector3** pRetVal
    ) override;
    STDMETHODIMP CreateVector4(
        float x,
        float y,
        float z,
        float w,
        IRayLibVector4** pRetVal
    ) override;
    STDMETHODIMP CreateQuaternion(
        float x,
        float y,
        float z,
        float w,
        IRayLibVector4** pRetVal
    ) override;
    STDMETHODIMP CreateRectangle(
        float x,
        float y,
        float width,
        float height,
        IRayLibRectangle** pRetVal
    ) override;
    STDMETHODIMP CreateMatrix(
        IRayLibMatrix** pRetVal
    ) override;
    STDMETHODIMP CreateCamera2D(
        IRayLibCamera2D** pRetVal
    ) override;
    STDMETHODIMP CreateCamera3D(
        IRayLibCamera3D** pRetVal
    ) override;
    STDMETHODIMP CreateTexture(
        IRayLibTexture** pRetVal
    ) override;
    STDMETHODIMP CreateRenderTexture(
        IRayLibRenderTexture** pRetVal
    ) override;
};

#endif // _CORAYLIB_H
