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

class WrRayLib
{
public:
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

	// Timing-related functions
	static void SetTargetFPS(int fps);
	static float GetFrameTime(void);
	static double GetTime(void);
	static int GetFPS(void);

	// Random values generation functions
	static void SetRandomSeed(unsigned int seed);
	static int GetRandomValue(int min, int max);

	// Input-related functions: keyboard
	static bool IsKeyPressed(int key);
	static bool IsKeyPressedRepeat(int key);
	static bool IsKeyDown(int key);
	static bool IsKeyReleased(int key);
	static bool IsKeyUp(int key);
	static int GetKeyPressed(void);
	static int GetCharPressed(void);
	static void SetExitKey(int key);

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

	// Basic shapes drawing functions
	static void DrawPixel(int posX, int posY, WrRayLibColor color);
	static void DrawPixelV(WrRayLibVector2 position, WrRayLibColor color);
	static void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, WrRayLibColor color);
	static void DrawLineV(WrRayLibVector2 startPos, WrRayLibVector2 endPos, WrRayLibColor color);
	static void DrawLineEx(WrRayLibVector2 startPos, WrRayLibVector2 endPos, float thick, WrRayLibColor color);

	static void DrawCircle(int centerX, int centerY, float radius, WrRayLibColor color);
	static void DrawCircleV(WrRayLibVector2 center, float radius, WrRayLibColor color);

	static void DrawCircleLines(int centerX, int centerY, float radius, WrRayLibColor color);
	static void DrawCircleLinesV(WrRayLibVector2 center, float radius, WrRayLibColor color);

	static void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseV(WrRayLibVector2 center, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, WrRayLibColor color);
	static void DrawEllipseLinesV(WrRayLibVector2 center, float radiusH, float radiusV, WrRayLibColor color);

	static void DrawRectangle(int posX, int posY, int width, int height, WrRayLibColor color);
	static void DrawRectangleV(WrRayLibVector2 position, WrRayLibVector2 size, WrRayLibColor color);
	static void DrawRectangleRec(WrRayLibRectangle rec, WrRayLibColor color);

	static void DrawTriangle(WrRayLibVector2 v1, WrRayLibVector2 v2, WrRayLibVector2 v3, WrRayLibColor color);
	static void DrawTriangleLines(WrRayLibVector2 v1, WrRayLibVector2 v2, WrRayLibVector2 v3, WrRayLibColor color);

	static void DrawPoly(WrRayLibVector2 center, int sides, float radius, float rotation, WrRayLibColor color);
	static void DrawPolyLines(WrRayLibVector2 center, int sides, float radius, float rotation, WrRayLibColor color);

	// Basic shapes collision detection functions
	static bool CheckCollisionRecs(WrRayLibRectangle rec1, WrRayLibRectangle rec2);
	static bool CheckCollisionCircles(WrRayLibVector2 center1, float radius1, WrRayLibVector2 center2, float radius2);
	static bool CheckCollisionCircleRec(WrRayLibVector2 center, float radius, WrRayLibRectangle rec);
	static bool CheckCollisionCircleLine(WrRayLibVector2 center, float radius, WrRayLibVector2 p1, WrRayLibVector2 p2);
	static bool CheckCollisionPointRec(WrRayLibVector2 point, WrRayLibRectangle rec);
	static bool CheckCollisionPointCircle(WrRayLibVector2 point, WrRayLibVector2 center, float radius);
	static bool CheckCollisionPointTriangle(WrRayLibVector2 point, WrRayLibVector2 p1, WrRayLibVector2 p2, WrRayLibVector2 p3);
	static bool CheckCollisionPointLine(WrRayLibVector2 point, WrRayLibVector2 p1, WrRayLibVector2 p2, int threshold);

	// Text drawing functions
	static void DrawFPS(int posX, int posY);
	static void DrawText(const char* text, int posX, int posY, int fontsize, WrRayLibColor color);
};

#endif // _WRRAYLIB_H
