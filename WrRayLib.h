// WrRayLib.h
//

#ifndef _WRRAYLIB_H
#define _WRRAYLIB_H


typedef struct tagWrRayLibColor
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} WrRayLibColor;

typedef struct tagWrRayLibVector2
{
	float x;
	float y;
} WrRayLibVector2;

typedef struct tagWrRayLibVector3
{
	float x;
	float y;
	float z;
} WrRayLibVector3;

typedef struct tagWrRayLibVector4
{
	float x;
	float y;
	float z;
	float w;
} WrRayLibVector4;

typedef struct tagWrRayLibMatrix {
	float m0, m4, m8, m12;
	float m1, m5, m9, m13;
	float m2, m6, m10, m14;
	float m3, m7, m11, m15;
} WrRayLibMatrix;

typedef struct tagWrRayLibRectangle
{
	float x;
	float y;
	float width;
	float height;
} WrRayLibRectangle;

typedef struct tagWrRayLibCamera2D
{
	WrRayLibVector2 offset;
	WrRayLibVector2 target;
	float rotation;
	float zoom;
} WrRayLibCamera2D;

typedef struct tagWrRayLibCamera3D
{
	WrRayLibVector3 position;
	WrRayLibVector3 target;
	WrRayLibVector3 up;
	float fovy;
	int projection;
} WrRayLibCamera3D;

typedef struct tagWrRayLibRay
{
	WrRayLibVector3 position;
	WrRayLibVector3 direction;
} WrRayLibRay;

class WrRayLib
{
public:

	/* MODULE: RCORE */

	// Window-related functions
	static void InitWindow(int width, int height, const char* title);
	static void CloseWindow(void);
	static bool WindowShouldClose(void);
	static bool IsWindowReady(void);
	static bool IsWindowFullscreen(void);
	static bool IsWindowHidden(void);
	static bool IsWindowMinimized(void);
	static bool IsWindowMaximized(void);
	static bool IsWindowFocused(void);
	static bool IsWindowResized(void);
	static bool IsWindowState(unsigned int flag);
	static void SetWindowState(unsigned int flags);
	static void ClearWindowState(unsigned int flags);
	static void ToggleFullscreen(void);
	static void ToggleBorderlessWindowed(void);
	static void MaximizeWindow(void);
	static void MinimizeWindow(void);
	static void RestoreWindow(void);
//	static void SetWindowIcon(Image image);
//	static void SetWindowIcons(Image* images, int count);
	static void SetWindowTitle(const char* title);
	static void SetWindowPosition(int x, int y);
	static void SetWindowMonitor(int monitor);
	static void SetWindowMinSize(int width, int height);
	static void SetWindowMaxSize(int width, int height);
	static void SetWindowSize(int width, int height);
	static void SetWindowOpacity(float opacity);
	static void SetWindowFocused(void);
	static void* GetWindowHandle(void);
	static int GetScreenWidth(void);
	static int GetScreenHeight(void);
	static int GetRenderWidth(void);
	static int GetRenderHeight(void);
	static int GetMonitorCount(void);
	static int GetCurrentMonitor(void);
	static WrRayLibVector2 GetMonitorPosition(int monitor);
	static int GetMonitorWidth(int monitor);
	static int GetMonitorHeight(int monitor);
	static int GetMonitorPhysicalWidth(int monitor);
	static int GetMonitorPhysicalHeight(int monitor);
	static int GetMonitorRefreshRate(int monitor);
	static WrRayLibVector2 GetWindowPosition(void);
	static WrRayLibVector2 GetWindowScaleDPI(void);
	static const char* GetMonitorName(int monitor);
	static void SetClipboardText(const char* text);
	static const char* GetClipboardText(void);
//	static Image GetClipboardImage(void);
	static void EnableEventWaiting(void);
	static void DisableEventWaiting(void);

	// Cursor-related functions
	static void ShowCursor(void);
	static void HideCursor(void);
	static bool IsCursorHidden(void);
	static void EnableCursor(void);
	static void DisableCursor(void);
	static bool IsCursorOnScreen(void);

	// Drawing-related functions
	static void ClearBackground(WrRayLibColor color);
	static void BeginDrawing(void);
	static void EndDrawing(void);
	static void BeginMode2D(WrRayLibCamera2D camera);
	static void EndMode2D(void);
	static void BeginMode3D(WrRayLibCamera3D camera);
	static void EndMode3D(void);
//	static void BeginTextureMode(RenderTexture2D target);
//	static void EndTextureMode(void);
//	static void BeginShaderMode(Shader shader);
//	static void EndShaderMode(void);
	static void BeginBlendMode(int mode);
	static void EndBlendMode(void);
	static void BeginScissorMode(int x, int y, int width, int height);
	static void EndScissorMode(void);
//	static void BeginVrStereoMode(VrStereoConfig config);
//	static void EndVrStereoMode(void);

	// VR stereo config functions for VR simulator
//	static VrStereoConfig LoadVrStereoConfig(VrDeviceInfo device);
//	static void UnloadVrStereoConfig(VrStereoConfig config);

	// Shader management functions
//	static Shader LoadShader(const char* vsFileName, const char* fsFileName);
//	static Shader LoadShaderFromMemory(const char* vsCode, const char* fsCode);
//	static bool IsShaderValid(Shader shader);
//	static int GetShaderLocation(Shader shader, const char* uniformName);
//	static int GetShaderLocationAttrib(Shader shader, const char* attribName);
//	static void SetShaderValue(Shader shader, int locIndex, const void* value, int uniformType);
//	static void SetShaderValueV(Shader shader, int locIndex, const void* value, int uniformType, int count);
//	static void SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat);
//	static void SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture);
//	static void UnloadShader(Shader shader);

	// Screen-space-related functions
	static WrRayLibRay GetScreenToWorldRay(WrRayLibVector2 position, WrRayLibCamera3D camera);
	static WrRayLibRay GetScreenToWorldRayEx(WrRayLibVector2 position, WrRayLibCamera3D camera, int width, int height);
	static WrRayLibVector2 GetWorldToScreen(WrRayLibVector3 position, WrRayLibCamera3D camera);
	static WrRayLibVector2 GetWorldToScreenEx(WrRayLibVector3 position, WrRayLibCamera3D camera, int width, int height);
	static WrRayLibVector2 GetWorldToScreen2D(WrRayLibVector2 position, WrRayLibCamera2D camera);
	static WrRayLibVector2 GetScreenToWorld2D(WrRayLibVector2 position, WrRayLibCamera2D camera);
//	static Matrix GetCameraMatrix(Camera camera);
//	static Matrix GetCameraMatrix2D(Camera2D camera);

	// Timing-related functions
	static void SetTargetFPS(int fps);
	static float GetFrameTime(void);
	static double GetTime(void);
	static int GetFPS(void);

	// Custom frame control functions
	static void SwapScreenBuffer(void);
	static void PollInputEvents(void);
	static void WaitTime(double seconds);

	// Random values generation functions
	static void SetRandomSeed(unsigned int seed);
	static int GetRandomValue(int min, int max);
//	static int* LoadRandomSequence(unsigned int count, int min, int max);
//	static void UnloadRandomSequence(int* sequence);

	// Misc. functions
	static void TakeScreenshot(const char* fileName);
	static void SetConfigFlags(unsigned int flags);
	static void OpenURL(const char* url);

	// Logging system
	static void SetTraceLogLevel(int logLevel);
//	static void TraceLog(int logLevel, const char* text, ...);
//	static void SetTraceLogCallback(TraceLogCallback callback);

	// Memory management, using internal allocators
//	static void* MemAlloc(unsigned int size);
//	static void* MemRealloc(void* ptr, unsigned int size);
//	static void MemFree(void* ptr);

	// File system management functions
//	static unsigned char* LoadFileData(const char* fileName, int* dataSize);
//	static void UnloadFileData(unsigned char* data);
//	static bool SaveFileData(const char* fileName, void* data, int dataSize);
//	static bool ExportDataAsCode(const unsigned char* data, int dataSize, const char* fileName);
//	static char* LoadFileText(const char* fileName);
//	static void UnloadFileText(char* text);
//	static bool SaveFileText(const char* fileName, const char* text);

	// File access custom callbacks

	// Compression/Encoding functionality

	// Automation events functionality

	// Input-related functions: keyboard
	static bool IsKeyPressed(int key);
	static bool IsKeyPressedRepeat(int key);
	static bool IsKeyDown(int key);
	static bool IsKeyReleased(int key);
	static bool IsKeyUp(int key);
	static int GetKeyPressed(void);
	static int GetCharPressed(void);
	static void SetExitKey(int key);

	// Input-related functions: gamepads
	static bool IsGamepadAvailable(int gamepad);
	static const char* GetGamepadName(int gamepad);
	static bool IsGamepadButtonPressed(int gamepad, int button);
	static bool IsGamepadButtonDown(int gamepad, int button);
	static bool IsGamepadButtonReleased(int gamepad, int button);
	static bool IsGamepadButtonUp(int gamepad, int button);
	static int GetGamepadButtonPressed(void);
	static int GetGamepadAxisCount(int gamepad);
	static float GetGamepadAxisMovement(int gamepad, int axis);
	static int SetGamepadMappings(const char* mappings);
	static void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration);

	// Input-related functions: mouse
	static bool IsMouseButtonPressed(int button);
	static bool IsMouseButtonDown(int button);
	static bool IsMouseButtonReleased(int button);
	static bool IsMouseButtonUp(int button);
	static int GetMouseX(void);
	static int GetMouseY(void);
	static WrRayLibVector2 GetMousePosition(void);
	static WrRayLibVector2 GetMouseDelta(void);
	static void SetMousePosition(int x, int y);
	static void SetMouseOffset(int offsetX, int offsetY);
	static void SetMouseScale(float scaleX, float scaleY);
	static float GetMouseWheelMove(void);
	static WrRayLibVector2 GetMouseWheelMoveV(void);
	static void SetMouseCursor(int cursor);

	// Input-related functions: touch
	static int GetTouchX(void);
	static int GetTouchY(void);
	static WrRayLibVector2 GetTouchPosition(int index);
	static int GetTouchPointId(int index);
	static int GetTouchPointCount(void);

	// Gestures and Touch Handling Functions (Module: rgestures)
	static void SetGesturesEnabled(unsigned int flags);
	static bool IsGestureDetected(unsigned int gesture);
	static int GetGestureDetected(void);
	static float GetGestureHoldDuration(void);
	static WrRayLibVector2 GetGestureDragVector(void);
	static float GetGestureDragAngle(void);
	static WrRayLibVector2 GetGesturePinchVector(void);
	static float GetGesturePinchAngle(void);

	// Camera System Functions (Module: rcamera)
	static void UpdateCamera(WrRayLibCamera3D* camera, int mode);
	static void UpdateCameraPro(WrRayLibCamera3D* camera, WrRayLibVector3 movement, WrRayLibVector3 rotation, float zoom);


	/* MODULE: RSHAPES */

//	static void SetShapesTexture(Texture2D texture, Rectangle source);
//	static Texture2D GetShapesTexture(void);
//	static Rectangle GetShapesTextureRectangle(void);

	// Basic shapes drawing functions
	static void DrawPixel(int posX, int posY, WrRayLibColor color);
	static void DrawPixelV(WrRayLibVector2 position, WrRayLibColor color);
	static void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, WrRayLibColor color);
	static void DrawLineV(WrRayLibVector2 startPos, WrRayLibVector2 endPos, WrRayLibColor color);
	static void DrawLineEx(WrRayLibVector2 startPos, WrRayLibVector2 endPos, float thick, WrRayLibColor color);
//	static void DrawLineStrip(const Vector2* points, int pointCount, Color color);
//	static void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
//	static void DrawLineDashed(Vector2 startPos, Vector2 endPos, int dashSize, int spaceSize, Color color);
	static void DrawCircle(int centerX, int centerY, float radius, WrRayLibColor color);
	static void DrawCircleV(WrRayLibVector2 center, float radius, WrRayLibColor color);
//	static void DrawCircleGradient(Vector2 center, float radius, Color inner, Color outer);
//	static void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
//	static void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color);
	static void DrawCircleLines(int centerX, int centerY, float radius, WrRayLibColor color);
	static void DrawCircleLinesV(WrRayLibVector2 center, float radius, WrRayLibColor color);
	static void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseV(WrRayLibVector2 center, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseLinesV(WrRayLibVector2 center, float radiusH, float radiusV, WrRayLibColor color);
//	static void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
//	static void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color);
	static void DrawRectangle(int posX, int posY, int width, int height, WrRayLibColor color);
	static void DrawRectangleV(WrRayLibVector2 position, WrRayLibVector2 size, WrRayLibColor color);
	static void DrawRectangleRec(WrRayLibRectangle rec, WrRayLibColor color);
	static void DrawRectanglePro(WrRayLibRectangle rec, WrRayLibVector2 origin, float rotation, WrRayLibColor color);
	static void DrawRectangleGradientV(int posX, int posY, int width, int height, WrRayLibColor top, WrRayLibColor bottom);
	static void DrawRectangleGradientH(int posX, int posY, int width, int height, WrRayLibColor left, WrRayLibColor right);
	static void DrawRectangleGradientEx(WrRayLibRectangle rec, WrRayLibColor topLeft, WrRayLibColor bottomLeft, WrRayLibColor bottomRight, WrRayLibColor topRight);
	static void DrawRectangleLines(int posX, int posY, int width, int height, WrRayLibColor color);
	static void DrawRectangleLinesEx(WrRayLibRectangle rec, float lineThick, WrRayLibColor color);
	static void DrawRectangleRounded(WrRayLibRectangle rec, float roundness, int segments, WrRayLibColor color);
	static void DrawRectangleRoundedLines(WrRayLibRectangle rec, float roundness, int segments, WrRayLibColor color);
	static void DrawRectangleRoundedLinesEx(WrRayLibRectangle rec, float roundness, int segments, float lineThick, WrRayLibColor color);
	static void DrawTriangle(WrRayLibVector2 v1, WrRayLibVector2 v2, WrRayLibVector2 v3, WrRayLibColor color);
	static void DrawTriangleLines(WrRayLibVector2 v1, WrRayLibVector2 v2, WrRayLibVector2 v3, WrRayLibColor color);
//	static void DrawTriangleFan(const Vector2* points, int pointCount, Color color);
//	static void DrawTriangleStrip(const Vector2* points, int pointCount, Color color);
	static void DrawPoly(WrRayLibVector2 center, int sides, float radius, float rotation, WrRayLibColor color);
	static void DrawPolyLines(WrRayLibVector2 center, int sides, float radius, float rotation, WrRayLibColor color);
//	static void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color);

	// Splines drawing functions
//	static void DrawSplineLinear(const Vector2* points, int pointCount, float thick, Color color);
//	static void DrawSplineBasis(const Vector2* points, int pointCount, float thick, Color color);
//	static void DrawSplineCatmullRom(const Vector2* points, int pointCount, float thick, Color color);
//	static void DrawSplineBezierQuadratic(const Vector2* points, int pointCount, float thick, Color color);
//	static void DrawSplineBezierCubic(const Vector2* points, int pointCount, float thick, Color color);
//	static void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color);
//	static void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
//	static void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color);
//	static void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color);
//	static void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color);

	// Spline segment point evaluation functions, for a given t [0.0f .. 1.0f]
//	static Vector2 GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t);
//	static Vector2 GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
//	static Vector2 GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t);
//	static Vector2 GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t);
//	static Vector2 GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t);

	// Basic shapes collision detection functions
	static bool CheckCollisionRecs(WrRayLibRectangle rec1, WrRayLibRectangle rec2);
	static bool CheckCollisionCircles(WrRayLibVector2 center1, float radius1, WrRayLibVector2 center2, float radius2);
	static bool CheckCollisionCircleRec(WrRayLibVector2 center, float radius, WrRayLibRectangle rec);
	static bool CheckCollisionCircleLine(WrRayLibVector2 center, float radius, WrRayLibVector2 p1, WrRayLibVector2 p2);
	static bool CheckCollisionPointRec(WrRayLibVector2 point, WrRayLibRectangle rec);
	static bool CheckCollisionPointCircle(WrRayLibVector2 point, WrRayLibVector2 center, float radius);
	static bool CheckCollisionPointTriangle(WrRayLibVector2 point, WrRayLibVector2 p1, WrRayLibVector2 p2, WrRayLibVector2 p3);
	static bool CheckCollisionPointLine(WrRayLibVector2 point, WrRayLibVector2 p1, WrRayLibVector2 p2, int threshold);
//	static bool CheckCollisionPointPoly(WrRayLibVector2 point, const WrRayLibVector2* points, int pointCount);
//	static bool CheckCollisionLines(WrRayLibVector2 startPos1, WrRayLibVector2 endPos1, WrRayLibVector2 startPos2, WrRayLibVector2 endPos2, WrRayLibVector2* collisionPoint);
	static WrRayLibRectangle GetCollisionRec(WrRayLibRectangle rec1, WrRayLibRectangle rec2);


	/* MODULE: RTEXTURES */

	// Image loading functions

	// Image generation functions

	// Image manipulation functions

	// Image drawing functions

	// Texture loading functions

	// Texture configuration functions

	// Texture drawing functions

	// Color/pixel related functions
	static bool ColorIsEqual(WrRayLibColor col1, WrRayLibColor col2);
	static WrRayLibColor Fade(WrRayLibColor color, float alpha);
//	static int ColorToInt(Color color);
//	static Vector4 ColorNormalize(Color color);
//	static Color ColorFromNormalized(Vector4 normalized);
//	static Vector3 ColorToHSV(Color color);
//	static Color ColorFromHSV(float hue, float saturation, float value);
//	static Color ColorTint(Color color, Color tint);
//	static Color ColorBrightness(Color color, float factor);
//	static Color ColorContrast(Color color, float contrast);
//	static Color ColorAlpha(Color color, float alpha);
//	static Color ColorAlphaBlend(Color dst, Color src, Color tint);
//	static Color ColorLerp(Color color1, Color color2, float factor);
//	static Color GetColor(unsigned int hexValue);
//	static Color GetPixelColor(void* srcPtr, int format);
//	static void SetPixelColor(void* dstPtr, Color color, int format);
//	static int GetPixelDataSize(int width, int height, int format);


	/* MODULE: RTEXT */

	// Font loading/unloading functions
//	static Font GetFontDefault(void);
//	static Font LoadFont(const char* fileName);
//	static Font LoadFontEx(const char* fileName, int fontSize, const int* codepoints, int codepointCount);
//	static Font LoadFontFromImage(Image image, Color key, int firstChar);
//	static Font LoadFontFromMemory(const char* fileType, const unsigned char* fileData, int dataSize, int fontSize, const int* codepoints, int codepointCount);
//	static bool IsFontValid(Font font);
//	static GlyphInfo* LoadFontData(const unsigned char* fileData, int dataSize, int fontSize, const int* codepoints, int codepointCount, int type, int* glyphCount);
//	static Image GenImageFontAtlas(const GlyphInfo* glyphs, Rectangle** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod);
//	static void UnloadFontData(GlyphInfo* glyphs, int glyphCount);
//	static void UnloadFont(Font font);
//	static bool ExportFontAsCode(Font font, const char* fileName);

	// Text drawing functions
	static void DrawFPS(int posX, int posY);
	static void DrawText(const char* text, int posX, int posY, int fontsize, WrRayLibColor color);
//	static void DrawTextEx(Font font, const char* text, Vector2 position, float fontSize, float spacing, Color tint);
//	static void DrawTextPro(Font font, const char* text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint);
//	static void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint);
//	static void DrawTextCodepoints(Font font, const int* codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint);

	// Text font info functions
	static void SetTextLineSpacing(int spacing);
	static int MeasureText(const char* text, int fontSize);
//	static Vector2 MeasureTextEx(Font font, const char* text, float fontSize, float spacing);
//	static Vector2 MeasureTextCodepoints(Font font, const int* codepoints, int length, float fontSize, float spacing);
//	static int GetGlyphIndex(Font font, int codepoint);
//	static GlyphInfo GetGlyphInfo(Font font, int codepoint);
//	static Rectangle GetGlyphAtlasRec(Font font, int codepoint);

	// Text codepoints management functions (unicode characters)
//	static char* LoadUTF8(const int* codepoints, int length);
//	static void UnloadUTF8(char* text);
//	static int* LoadCodepoints(const char* text, int* count);
//	static void UnloadCodepoints(int* codepoints);
//	static int GetCodepointCount(const char* text);
//	static int GetCodepoint(const char* text, int* codepointSize);
//	static int GetCodepointNext(const char* text, int* codepointSize);
//	static int GetCodepointPrevious(const char* text, int* codepointSize);
//	static const char* CodepointToUTF8(int codepoint, int* utf8Size);

	// Text strings management functions (no UTF-8 strings, only byte chars)
//	static char** LoadTextLines(const char* text, int* count);
//	static void UnloadTextLines(char** text, int lineCount);
//	static int TextCopy(char* dst, const char* src);
	static bool TextIsEqual(const char* text1, const char* text2);
	static unsigned int TextLength(const char* text);
//*	static const char* TextFormat(const char* text, ...); ==> actually reimplemented from scratch
	static const char* TextSubtext(const char* text, int position, int length);
	static const char* TextRemoveSpaces(const char* text);
	static char* GetTextBetween(const char* text, const char* begin, const char* end);
//	static char* TextReplace(const char* text, const char* search, const char* replacement);
//	static char* TextReplaceAlloc(const char* text, const char* search, const char* replacement);
//	static char* TextReplaceBetween(const char* text, const char* begin, const char* end, const char* replacement);
//	static char* TextReplaceBetweenAlloc(const char* text, const char* begin, const char* end, const char* replacement);
//	static char* TextInsert(const char* text, const char* insert, int position);
//	static char* TextInsertAlloc(const char* text, const char* insert, int position);
//	static char* TextJoin(char** textList, int count, const char* delimiter);
//	static char** TextSplit(const char* text, char delimiter, int* count);
//	static void TextAppend(char* text, const char* append, int* position);
	static int TextFindIndex(const char* text, const char* search);
	static char* TextToUpper(const char* text);
	static char* TextToLower(const char* text);
	static char* TextToPascal(const char* text);
	static char* TextToSnake(const char* text);
	static char* TextToCamel(const char* text);
	static int TextToInteger(const char* text);
	static float TextToFloat(const char* text);


	/* MODULE: RMODELS */

	// Basic geometric 3D shapes drawing functions
	static void DrawLine3D(WrRayLibVector3 startPos, WrRayLibVector3 endPos, WrRayLibColor color);
	static void DrawPoint3D(WrRayLibVector3 position, WrRayLibColor color);
	static void DrawCircle3D(WrRayLibVector3 center, float radius, WrRayLibVector3 rotationAxis, float rotationAngle, WrRayLibColor color);
	static void DrawTriangle3D(WrRayLibVector3 v1, WrRayLibVector3 v2, WrRayLibVector3 v3, WrRayLibColor color);
//	static void DrawTriangleStrip3D(const Vector3* points, int pointCount, Color color);
	static void DrawCube(WrRayLibVector3 position, float width, float height, float length, WrRayLibColor color);
	static void DrawCubeV(WrRayLibVector3 position, WrRayLibVector3 size, WrRayLibColor color);
	static void DrawCubeWires(WrRayLibVector3 position, float width, float height, float length, WrRayLibColor color);
	static void DrawCubeWiresV(WrRayLibVector3 position, WrRayLibVector3 size, WrRayLibColor color);
//	static void DrawSphere(Vector3 centerPos, float radius, Color color);
//	static void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color);
//	static void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color);
//	static void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
//	static void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
//	static void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color);
//	static void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color);
//	static void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
//	static void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color);
	static void DrawPlane(WrRayLibVector3 centerPos, WrRayLibVector2 size, WrRayLibColor color);
	static void DrawRay(WrRayLibRay ray, WrRayLibColor color);
	static void DrawGrid(int slices, float spacing);

	// Model management functions
//	static Model LoadModel(const char* fileName);
//	static Model LoadModelFromMesh(Mesh mesh);
//	static bool IsModelValid(Model model);
//	static void UnloadModel(Model model);
//	static BoundingBox GetModelBoundingBox(Model model);

	// Model drawing functions
//	static void DrawModel(Model model, Vector3 position, float scale, Color tint);
//	static void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
//	static void DrawModelWires(Model model, Vector3 position, float scale, Color tint);
//	static void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint);
//	static void DrawBoundingBox(BoundingBox box, Color color);
//	static void DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint);
//	static void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint);
//	static void DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint);

	// Mesh management functions
//	static void UploadMesh(Mesh* mesh, bool dynamic);
//	static void UpdateMeshBuffer(Mesh mesh, int index, const void* data, int dataSize, int offset);
//	static void UnloadMesh(Mesh mesh);
//	static void DrawMesh(Mesh mesh, Material material, Matrix transform);
//	static void DrawMeshInstanced(Mesh mesh, Material material, const Matrix* transforms, int instances);
//	static BoundingBox GetMeshBoundingBox(Mesh mesh);
//	static void GenMeshTangents(Mesh* mesh);
//	static bool ExportMesh(Mesh mesh, const char* fileName);
//	static bool ExportMeshAsCode(Mesh mesh, const char* fileName);

	// Mesh generation functions
//	static Mesh GenMeshPoly(int sides, float radius);
//	static Mesh GenMeshPlane(float width, float length, int resX, int resZ);
//	static Mesh GenMeshCube(float width, float height, float length);
//	static Mesh GenMeshSphere(float radius, int rings, int slices);
//	static Mesh GenMeshHemiSphere(float radius, int rings, int slices);
//	static Mesh GenMeshCylinder(float radius, float height, int slices);
//	static Mesh GenMeshCone(float radius, float height, int slices);
//	static Mesh GenMeshTorus(float radius, float size, int radSeg, int sides);
//	static Mesh GenMeshKnot(float radius, float size, int radSeg, int sides);
//	static Mesh GenMeshHeightmap(Image heightmap, Vector3 size);
//	static Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize);

	// Material loading/unloading functions
//	static Material* LoadMaterials(const char* fileName, int* materialCount);
//	static Material LoadMaterialDefault(void);
//	static bool IsMaterialValid(Material material);
//	static void UnloadMaterial(Material material);
//	static void SetMaterialTexture(Material* material, int mapType, Texture2D texture);
//	static void SetModelMeshMaterial(Model* model, int meshId, int materialId);

	// Model animations loading/unloading functions
//	static ModelAnimation* LoadModelAnimations(const char* fileName, int* animCount);
//	static void UpdateModelAnimation(Model model, ModelAnimation anim, float frame);
//	static void UpdateModelAnimationEx(Model model, ModelAnimation animA, float frameA, ModelAnimation animB, float frameB, float blend);
//	static void UnloadModelAnimations(ModelAnimation* animations, int animCount);
//	static bool IsModelAnimationValid(Model model, ModelAnimation anim);

	// Collision detection functions
//	static bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2);
//	static bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2);
//	static bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);
//	static RayCollision GetRayCollisionSphere(Ray ray, Vector3 center, float radius);
//	static RayCollision GetRayCollisionBox(Ray ray, BoundingBox box);
//	static RayCollision GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform);
//	static RayCollision GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3);
//	static RayCollision GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4);


	/* MODULE: RAUDIO */

	// Audio device management functions
	static void InitAudioDevice(void);
	static void CloseAudioDevice(void);
	static bool IsAudioDeviceReady(void);
	static void SetMasterVolume(float volume);
	static float GetMasterVolume(void);

	// Wave/Sound loading/unloading functions

	// Wave/Sound management functions

	// Music management functions

	// AudioStream management functions
};

#endif // _WRRAYLIB_H
