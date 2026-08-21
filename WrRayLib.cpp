// WrRayLib.cpp
//

#include "WrRayLib.h"
#include <raylib.h>


// non-RayLib transformation functions (helpers)

static Color inline wr2rl_color(
	WrRayLibColor color
)
{
	return { color.r, color.g, color.b, color.a };
}

static Vector2 inline wr2rl_vector2(
	WrRayLibVector2 vector
)
{
	return { vector.x, vector.y };
}

static Vector3 inline wr2rl_vector3(
	WrRayLibVector3 vector
)
{
	return { vector.x, vector.y, vector.z };
}

static Vector4 inline wr2rl_vector4(
	WrRayLibVector4 vector
)
{
	return { vector.x, vector.y, vector.z, vector.w };
}

static Rectangle inline wr2rl_rect(
	WrRayLibRectangle rect
)
{
	return { rect.x, rect.y, rect.width, rect.height };
}

static void inline wr2rl_camera2D(
	Camera2D* rl_camera,
	WrRayLibCamera2D* wr_camera
)
{
	rl_camera->offset = wr2rl_vector2(wr_camera->offset);
	rl_camera->target = wr2rl_vector2(wr_camera->target);
	rl_camera->rotation = wr_camera->rotation;
	rl_camera->zoom = wr_camera->zoom;
}

static inline Camera2D wr2rl_camera2D(
	WrRayLibCamera2D camera
)
{
	return {
		wr2rl_vector2(camera.offset),
		wr2rl_vector2(camera.target),
		camera.rotation,
		camera.zoom
	};
}

static void inline wr2rl_camera3D(
	Camera3D* rl_camera,
	WrRayLibCamera3D* wr_camera
)
{
	rl_camera->position = wr2rl_vector3(wr_camera->position);
	rl_camera->target = wr2rl_vector3(wr_camera->target);
	rl_camera->up = wr2rl_vector3(wr_camera->up);
	rl_camera->fovy = wr_camera->fovy;
	rl_camera->projection = wr_camera->projection;
}

static inline Camera3D wr2rl_camera3D(
	WrRayLibCamera3D camera
)
{
	return {
		wr2rl_vector3(camera.position),
		wr2rl_vector3(camera.target),
		wr2rl_vector3(camera.up),
		camera.fovy,
		camera.projection
	};
}

static inline Ray wr2rl_ray(
	WrRayLibRay ray
)
{
	return {
		wr2rl_vector3(ray.position),
		wr2rl_vector3(ray.direction),
	};
}

static inline Texture wr2rl_texture(
	WrRayLibTexture texture
)
{
	return {
		texture.id,
		texture.width,
		texture.height,
		texture.mipmaps,
		texture.format
	};
}

static inline RenderTexture wr2rl_render_texture(
	WrRayLibRenderTexture render_texture
)
{
	return {
		render_texture.id,
		wr2rl_texture(render_texture.texture),
		wr2rl_texture(render_texture.depth)
	};
}

static WrRayLibColor inline rl2wr_color(
	Color color
)
{
	return { color.r, color.g, color.b, color.a };
}

static WrRayLibVector2 inline rl2wr_vector2(
	Vector2 vector
)
{
	return { vector.x, vector.y };
}

static WrRayLibVector3 inline rl2wr_vector3(
	Vector3 vector
)
{
	return { vector.x, vector.y, vector.z };
}

static WrRayLibVector4 inline rl2wr_vector4(
	Vector4 vector
)
{
	return { vector.x, vector.y, vector.z, vector.w };
}

static WrRayLibRectangle inline rl2wr_rect(
	Rectangle rec
)
{
	return { rec.x, rec.y, rec.width, rec.height };
}

static void inline rl2wr_camera2D(
	WrRayLibCamera2D* wr_camera,
	Camera2D* rl_camera
)
{
	wr_camera->offset = rl2wr_vector2(rl_camera->offset);
	wr_camera->target = rl2wr_vector2(rl_camera->target);
	wr_camera->rotation = rl_camera->rotation;
	wr_camera->zoom = rl_camera->zoom;
}

static void inline rl2wr_camera3D(
	WrRayLibCamera3D* wr_camera,
	Camera3D* rl_camera
)
{
	wr_camera->position = rl2wr_vector3(rl_camera->position);
	wr_camera->target = rl2wr_vector3(rl_camera->target);
	wr_camera->up = rl2wr_vector3(rl_camera->up);
	wr_camera->fovy = rl_camera->fovy;
	wr_camera->projection = rl_camera->projection;
}

static WrRayLibMatrix rl2wr_matrix(
	Matrix matrix
)
{
	return {
		matrix.m0, matrix.m4, matrix.m8, matrix.m12,
		matrix.m1, matrix.m5, matrix.m9, matrix.m13,
		matrix.m2, matrix.m6, matrix.m10, matrix.m14,
		matrix.m3, matrix.m7, matrix.m11, matrix.m15,
	};
}

static WrRayLibRay inline rl2wr_ray(
	Ray ray
)
{
	return {
		rl2wr_vector3(ray.position),
		rl2wr_vector3(ray.direction)
	};
}

static WrRayLibTexture inline rl2wr_texture(
	Texture2D texture
)
{
	return {
		texture.id,
		texture.width,
		texture.height,
		texture.mipmaps,
		texture.format
	};
}


// Window-related functions

void WrRayLib::InitWindow(
	int width,
	int height,
	const char* title
)
{
	::InitWindow(width, height, title);
}
void WrRayLib::CloseWindow(
	void
)
{
	::CloseWindow();
}
bool WrRayLib::WindowShouldClose(
	void
)
{
	return ::WindowShouldClose();
}
bool WrRayLib::IsWindowReady(
	void
)
{
	return ::IsWindowReady();
}
bool WrRayLib::IsWindowFullscreen(
	void
)
{
	return ::IsWindowFullscreen();
}
bool WrRayLib::IsWindowHidden(
	void
)
{
	return ::IsWindowHidden();
}
bool WrRayLib::IsWindowMinimized(
	void
)
{
	return ::IsWindowMinimized();
}
bool WrRayLib::IsWindowMaximized(
	void
)
{
	return ::IsWindowMaximized();
}
bool WrRayLib::IsWindowFocused(
	void
)
{
	return ::IsWindowFocused();
}
bool WrRayLib::IsWindowResized(
	void
)
{
	return ::IsWindowResized();
}
bool WrRayLib::IsWindowState(
	unsigned int flag
)
{
	return ::IsWindowState(flag);
}
void WrRayLib::SetWindowState(
	unsigned int flags
)
{
	::SetWindowState(flags);
}
void WrRayLib::ClearWindowState(
	unsigned int flags
)
{
	::ClearWindowState(flags);
}
void WrRayLib::ToggleFullscreen(
	void
)
{
	::ToggleFullscreen();
}
void WrRayLib::ToggleBorderlessWindowed(
	void
)
{
	::ToggleBorderlessWindowed();
}
void WrRayLib::MaximizeWindow(
	void
)
{
	::MaximizeWindow();
}
void WrRayLib::MinimizeWindow(
	void
)
{
	::MinimizeWindow();
}
void WrRayLib::RestoreWindow(
	void
)
{
	::RestoreWindow();
}

void WrRayLib::SetWindowTitle(
	const char* title
)
{
	::SetWindowTitle(title);
}
void WrRayLib::SetWindowPosition(
	int x,
	int y
)
{
	::SetWindowPosition(x, y);
}
void WrRayLib::SetWindowMonitor(
	int monitor
)
{
	::SetWindowMonitor(monitor);
}
void WrRayLib::SetWindowMinSize(
	int width,
	int height
)
{
	::SetWindowMinSize(width, height);
}
void WrRayLib::SetWindowMaxSize(
	int width,
	int height
)
{
	::SetWindowMaxSize(width, height);
}
void WrRayLib::SetWindowSize(
	int width,
	int height
)
{
	::SetWindowSize(width, height);
}
void WrRayLib::SetWindowOpacity(
	float opacity
)
{
	::SetWindowOpacity(opacity);
}
void WrRayLib::SetWindowFocused(
	void
)
{
	::SetWindowFocused();
}
void *WrRayLib::GetWindowHandle(
	void
)
{
	return ::GetWindowHandle();
}
int WrRayLib::GetScreenWidth(
	void
)
{
	return ::GetScreenWidth();
}
int WrRayLib::GetScreenHeight(
	void
)
{
	return ::GetScreenHeight();
}
int WrRayLib::GetRenderWidth(
	void
)
{
	return ::GetRenderWidth();
}
int WrRayLib::GetRenderHeight(
	void
)
{
	return ::GetRenderHeight();
}
int WrRayLib::GetMonitorCount(
	void
)
{
	return ::GetMonitorCount();
}
int WrRayLib::GetCurrentMonitor(
	void
)
{
	return ::GetCurrentMonitor();
}
WrRayLibVector2 WrRayLib::GetMonitorPosition(
	int monitor
)
{
	return rl2wr_vector2(::GetMonitorPosition(monitor));
}
int WrRayLib::GetMonitorWidth(
	int monitor
)
{
	return ::GetMonitorWidth(monitor);
}
int WrRayLib::GetMonitorHeight(
	int monitor
)
{
	return ::GetMonitorHeight(monitor);
}
int WrRayLib::GetMonitorPhysicalWidth(
	int monitor
)
{
	return ::GetMonitorPhysicalWidth(monitor);
}
int WrRayLib::GetMonitorPhysicalHeight(
	int monitor
)
{
	return ::GetMonitorPhysicalHeight(monitor);
}
int WrRayLib::GetMonitorRefreshRate(
	int monitor
)
{
	return ::GetMonitorRefreshRate(monitor);
}
WrRayLibVector2 WrRayLib::GetWindowPosition(
	void
)
{
	return rl2wr_vector2(::GetWindowPosition());
}
WrRayLibVector2 WrRayLib::GetWindowScaleDPI(
	void
)
{
	return rl2wr_vector2(::GetWindowScaleDPI());
}
const char* WrRayLib::GetMonitorName(
	int monitor
)
{
	return ::GetMonitorName(monitor);
}
void WrRayLib::SetClipboardText(
	const char* text
)
{
	::SetClipboardText(
		text
	);
}
const char* WrRayLib::GetClipboardText(
	void
)
{
	return ::GetClipboardText();
}

void WrRayLib::EnableEventWaiting(
	void
)
{
	::EnableEventWaiting();
}
void WrRayLib::DisableEventWaiting(
	void
)
{
	::DisableEventWaiting();
}


// Cursor-related functions

void WrRayLib::ShowCursor(
	void
)
{
	::ShowCursor();
}
void WrRayLib::HideCursor(
	void
)
{
	::HideCursor();
}
bool WrRayLib::IsCursorHidden(
	void
)
{
	return ::IsCursorHidden();
}
void WrRayLib::EnableCursor(
	void
)
{
	::EnableCursor();
}
void WrRayLib::DisableCursor(
	void
)
{
	::DisableCursor();
}
bool WrRayLib::IsCursorOnScreen(
	void
)
{
	return ::IsCursorOnScreen();
}

// Drawing-related functions

void WrRayLib::ClearBackground(
	WrRayLibColor color
)
{
	::ClearBackground(
		wr2rl_color(color)
	);
}
void WrRayLib::BeginDrawing(
	void
)
{
	::BeginDrawing();
}
void WrRayLib::EndDrawing(
	void
)
{
	::EndDrawing();
}
void WrRayLib::BeginMode2D(
	WrRayLibCamera2D camera
)
{
	::BeginMode2D(
		wr2rl_camera2D(
			camera
		)
	);
}
void WrRayLib::EndMode2D(
	void
)
{
	::EndMode2D();
}
void WrRayLib::BeginMode3D(
	WrRayLibCamera3D camera
)
{
	::BeginMode3D(
		wr2rl_camera3D(
			camera
		)
	);
}
void WrRayLib::EndMode3D(
	void
)
{
	::EndMode3D();
}
void WrRayLib::BeginTextureMode(
	WrRayLibRenderTexture target
)
{
	::BeginTextureMode(
		wr2rl_render_texture(target)
	);
}
void WrRayLib::EndTextureMode(
	void
)
{
	::EndTextureMode();
}

void WrRayLib::BeginBlendMode(
	int mode
)
{
	::BeginBlendMode(
		mode
	);
}
void WrRayLib::EndBlendMode(
	void
)
{
	::EndBlendMode();
}
void WrRayLib::BeginScissorMode(
	int x,
	int y,
	int width,
	int height
)
{
	::BeginScissorMode(
		x,
		y,
		width,
		height
	);
}
void WrRayLib::EndScissorMode(
	void
)
{
	::EndScissorMode();
}


// Screen-space-related functions

WrRayLibRay WrRayLib::GetScreenToWorldRay(
	WrRayLibVector2 position,
	WrRayLibCamera3D camera
)
{
	return rl2wr_ray(
		::GetScreenToWorldRay(
			wr2rl_vector2(position),
			wr2rl_camera3D(camera)
		)
	);
}
WrRayLibRay WrRayLib::GetScreenToWorldRayEx(
	WrRayLibVector2 position,
	WrRayLibCamera3D camera,
	int width,
	int height
)
{
	return rl2wr_ray(
		::GetScreenToWorldRayEx(
			wr2rl_vector2(position),
			wr2rl_camera3D(camera),
			width,
			height
		)
	);
}
WrRayLibVector2 WrRayLib::GetWorldToScreen(
	WrRayLibVector3 position,
	WrRayLibCamera3D camera
)
{
	return rl2wr_vector2(
		::GetWorldToScreen(
			wr2rl_vector3(position),
			wr2rl_camera3D(camera)
		)
	);
}
WrRayLibVector2 WrRayLib::GetWorldToScreenEx(
	WrRayLibVector3 position,
	WrRayLibCamera3D camera,
	int width,
	int height
)
{
	return rl2wr_vector2(
		::GetWorldToScreenEx(
			wr2rl_vector3(position),
			wr2rl_camera3D(camera),
			width,
			height
		)
	);
}
WrRayLibVector2 WrRayLib::GetWorldToScreen2D(
	WrRayLibVector2 position,
	WrRayLibCamera2D camera
)
{
	return rl2wr_vector2(
		::GetWorldToScreen2D(
			wr2rl_vector2(position),
			wr2rl_camera2D(camera)
		)
	);
}
WrRayLibVector2 WrRayLib::GetScreenToWorld2D(
	WrRayLibVector2 position,
	WrRayLibCamera2D camera
)
{
	return rl2wr_vector2(
		::GetScreenToWorld2D(
			wr2rl_vector2(position),
			wr2rl_camera2D(camera)
		)
	);
}
WrRayLibMatrix WrRayLib::GetCameraMatrix(
	WrRayLibCamera3D camera
)
{
	return rl2wr_matrix(
		::GetCameraMatrix(
			wr2rl_camera3D(camera)
		)
	);
}
WrRayLibMatrix WrRayLib::GetCameraMatrix2D(
	WrRayLibCamera2D camera
)
{
	return rl2wr_matrix(
		::GetCameraMatrix2D(
			wr2rl_camera2D(camera)
		)
	);
}


// Timing-related functions

void WrRayLib::SetTargetFPS(
	int fps
)
{
	::SetTargetFPS(fps);
}
float WrRayLib::GetFrameTime(
	void
)
{
	return ::GetFrameTime();
}
double WrRayLib::GetTime(
	void
)
{
	return ::GetTime();
}
int WrRayLib::GetFPS(
	void
)
{
	return ::GetFPS();
}


// Custom frame control functions

void WrRayLib::SwapScreenBuffer(
	void
)
{
	::SwapScreenBuffer();
}
void WrRayLib::PollInputEvents(
	void
)
{
	::PollInputEvents();
}
void WrRayLib::WaitTime(
	double seconds
)
{
	::WaitTime(
		seconds
	);
}


// Random values generation functions

void WrRayLib::SetRandomSeed(
	unsigned int seed
)
{
	return ::SetRandomSeed(seed);
}
int WrRayLib::GetRandomValue(
	int min,
	int max
)
{
	return ::GetRandomValue(min, max);
}


// Misc. functions

void WrRayLib::TakeScreenshot(
	const char* fileName
)
{
	::TakeScreenshot(
		fileName
	);
}
void WrRayLib::SetConfigFlags(
	unsigned int flags
)
{
	::SetConfigFlags(
		flags
	);
}
void WrRayLib::OpenURL(
	const char* url
)
{
	::OpenURL(
		url
	);
}


// Logging system

void WrRayLib::SetTraceLogLevel(
	int logLevel
)
{
	::SetTraceLogLevel(
		logLevel
	);
}


// Memory management, using internal allocators

void WrRayLib::MemFree(
	void* ptr
)
{
	::MemFree(
		ptr
	);
}


// Input-related functions: keyboard

bool WrRayLib::IsKeyPressed(
	int key
)
{
	return ::IsKeyPressed(key);
}
bool WrRayLib::IsKeyPressedRepeat(
	int key
)
{
	return ::IsKeyPressedRepeat(key);
}
bool WrRayLib::IsKeyDown(
	int key
)
{
	return ::IsKeyDown(key);
}
bool WrRayLib::IsKeyReleased(
	int key
)
{
	return ::IsKeyReleased(key);
}
bool WrRayLib::IsKeyUp(
	int key
)
{
	return ::IsKeyUp(key);
}
int WrRayLib::GetKeyPressed(
	void
)
{
	return ::GetKeyPressed();
}
int WrRayLib::GetCharPressed(
	void
)
{
	return ::GetCharPressed();
}
void WrRayLib::SetExitKey(
	int key
)
{
	return ::SetExitKey(key);
}


// Input-related functions: gamepads

bool WrRayLib::IsGamepadAvailable(
	int gamepad
)
{
	return ::IsGamepadAvailable(
		gamepad
	);
}
const char* WrRayLib::GetGamepadName(
	int gamepad
)
{
	return ::GetGamepadName(
		gamepad
	);
}
bool WrRayLib::IsGamepadButtonPressed(
	int gamepad,
	int button
)
{
	return ::IsGamepadButtonPressed(
		gamepad,
		button
	);
}
bool WrRayLib::IsGamepadButtonDown(
	int gamepad,
	int button
)
{
	return ::IsGamepadButtonDown(
		gamepad,
		button
	);
}
bool WrRayLib::IsGamepadButtonReleased(
	int gamepad,
	int button
)
{
	return ::IsGamepadButtonReleased(
		gamepad,
		button
	);
}
bool WrRayLib::IsGamepadButtonUp(
	int gamepad,
	int button
)
{
	return ::IsGamepadButtonUp(
		gamepad,
		button
	);
}
int WrRayLib::GetGamepadButtonPressed(
	void
)
{
	return ::GetGamepadButtonPressed();
}
int WrRayLib::GetGamepadAxisCount(
	int gamepad
)
{
	return ::GetGamepadAxisCount(
		gamepad
	);
}
float WrRayLib::GetGamepadAxisMovement(
	int gamepad,
	int axis
)
{
	return ::GetGamepadAxisMovement(
		gamepad,
		axis
	);
}
int WrRayLib::SetGamepadMappings(
	const char* mappings
)
{
	return ::SetGamepadMappings(
		mappings
	);
}
void WrRayLib::SetGamepadVibration(
	int gamepad,
	float leftMotor,
	float rightMotor,
	float duration
)
{
	::SetGamepadVibration(
		gamepad,
		leftMotor,
		rightMotor,
		duration
	);
}


// Input-related functions: mouse

bool WrRayLib::IsMouseButtonPressed(
	int button
)
{
	return ::IsMouseButtonPressed(button);
}
bool WrRayLib::IsMouseButtonDown(
	int button
)
{
	return ::IsMouseButtonDown(button);
}
bool WrRayLib::IsMouseButtonReleased(
	int button
)
{
	return ::IsMouseButtonReleased(button);
}
bool WrRayLib::IsMouseButtonUp(
	int button
)
{
	return ::IsMouseButtonUp(button);
}
int WrRayLib::GetMouseX(
	void
)
{
	return ::GetMouseX();
}
int WrRayLib::GetMouseY(
	void
)
{
	return ::GetMouseY();
}
WrRayLibVector2 WrRayLib::GetMousePosition(
	void
)
{
	return rl2wr_vector2(::GetMousePosition());
}
WrRayLibVector2 WrRayLib::GetMouseDelta(
	void
)
{
	return rl2wr_vector2(::GetMouseDelta());
}
void WrRayLib::SetMousePosition(
	int x,
	int y
)
{
	return ::SetMousePosition(x, y);
}
void WrRayLib::SetMouseOffset(
	int offsetX,
	int offsetY
)
{
	return ::SetMouseOffset(offsetX, offsetY);
}
void WrRayLib::SetMouseScale(
	float scaleX,
	float scaleY
)
{
	return ::SetMouseScale(scaleX, scaleY);
}
float WrRayLib::GetMouseWheelMove(
	void
)
{
	return ::GetMouseWheelMove();
}
WrRayLibVector2 WrRayLib::GetMouseWheelMoveV(
	void
)
{
	return rl2wr_vector2(::GetMouseWheelMoveV());
}
void WrRayLib::SetMouseCursor(
	int cursor
)
{
	return ::SetMouseCursor(cursor);
}


// Input-related functions: touch
int WrRayLib::GetTouchX(
	void
)
{
	return ::GetTouchX();
}
int WrRayLib::GetTouchY(
	void
)
{
	return ::GetTouchY();
}
WrRayLibVector2 WrRayLib::GetTouchPosition(
	int index
)
{
	return rl2wr_vector2(::GetTouchPosition(index));
}
int WrRayLib::GetTouchPointId(
	int index
)
{
	return ::GetTouchPointId(index);
}
int WrRayLib::GetTouchPointCount(
	void
)
{
	return ::GetTouchPointCount();
}


// Gestures and Touch Handling Functions (Module: rgestures)

void WrRayLib::SetGesturesEnabled(
	unsigned int flags
)
{
	::SetGesturesEnabled(
		flags
	);
}
bool WrRayLib::IsGestureDetected(
	unsigned int gesture
)
{
	return ::IsGestureDetected(
		gesture
	);
}
int WrRayLib::GetGestureDetected(
	void
)
{
	return ::GetGestureDetected();
}
float WrRayLib::GetGestureHoldDuration(
	void
)
{
	return ::GetGestureHoldDuration();
}
WrRayLibVector2 WrRayLib::GetGestureDragVector(
	void
)
{
	return rl2wr_vector2(
		::GetGestureDragVector()
	);
}
float WrRayLib::GetGestureDragAngle(
	void
)
{
	return ::GetGestureDragAngle();
}
WrRayLibVector2 WrRayLib::GetGesturePinchVector(
	void
)
{
	return rl2wr_vector2(
		::GetGesturePinchVector()
	);
}
float WrRayLib::GetGesturePinchAngle(
	void
)
{
	return ::GetGesturePinchAngle();
}


// Camera System Functions (Module: rcamera)

void WrRayLib::UpdateCamera(
	WrRayLibCamera3D* camera,
	int mode
)
{
	Camera3D c = { 0 };

	wr2rl_camera3D(
		&c,
		camera
	);

	::UpdateCamera(
		&c,
		mode
	);

	rl2wr_camera3D(
		camera,
		&c
	);
}
void WrRayLib::UpdateCameraPro(
	WrRayLibCamera3D* camera,
	WrRayLibVector3 movement,
	WrRayLibVector3 rotation,
	float zoom
)
{
	Camera3D c = { 0 };

	wr2rl_camera3D(
		&c,
		camera
	);

	::UpdateCameraPro(
		&c,
		wr2rl_vector3(movement),
		wr2rl_vector3(rotation),
		zoom
	);

	rl2wr_camera3D(
		camera,
		&c
	);
}


/* MODULE: RSHAPES */

void WrRayLib::SetShapesTexture(
	WrRayLibTexture texture,
	WrRayLibRectangle source
)
{
	::SetShapesTexture(
		wr2rl_texture(texture),
		wr2rl_rect(source)
	);
}
WrRayLibTexture WrRayLib::GetShapesTexture(
	void
)
{
	return rl2wr_texture(
		::GetShapesTexture()
	);
}

WrRayLibRectangle WrRayLib::GetShapesTextureRectangle(
	void
)
{
	return rl2wr_rect(
		::GetShapesTextureRectangle()
	);
}


// Basic shapes drawing functions

void WrRayLib::DrawPixel(
	int posX,
	int posY,
	WrRayLibColor color
)
{
	::DrawPixel(
		posX,
		posY,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPixelV(
	WrRayLibVector2 position,
	WrRayLibColor color
)
{
	::DrawPixelV(
		wr2rl_vector2(position),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawLine(
	int startPosX,
	int startPosY,
	int endPosX,
	int endPosY,
	WrRayLibColor color
)
{
	::DrawLine(
		startPosX,
		startPosY,
		endPosX,
		endPosY,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawLineV(
	WrRayLibVector2 startPos,
	WrRayLibVector2 endPos,
	WrRayLibColor color
)
{
	::DrawLineV(
		wr2rl_vector2(startPos),
		wr2rl_vector2(endPos),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawLineEx(
	WrRayLibVector2 startPos,
	WrRayLibVector2 endPos,
	float thick,
	WrRayLibColor color
)
{
	::DrawLineEx(
		wr2rl_vector2(startPos),
		wr2rl_vector2(endPos),
		thick,
		wr2rl_color(color)
	);
}

void WrRayLib::DrawLineBezier(
	WrRayLibVector2 startPos,
	WrRayLibVector2 endPos,
	float thick,
	WrRayLibColor color
)
{
	::DrawLineBezier(
		wr2rl_vector2(startPos),
		wr2rl_vector2(endPos),
		thick,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawLineDashed(
	WrRayLibVector2 startPos,
	WrRayLibVector2 endPos,
	int dashSize,
	int spaceSize,
	WrRayLibColor color
)
{
	::DrawLineDashed(
		wr2rl_vector2(startPos),
		wr2rl_vector2(endPos),
		dashSize,
		spaceSize,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircle(
	int centerX,
	int centerY,
	float radius,
	WrRayLibColor color
)
{
	::DrawCircle(
		centerX,
		centerY,
		radius,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircleV(
	WrRayLibVector2 center,
	float radius,
	WrRayLibColor color
)
{
	::DrawCircleV(
		wr2rl_vector2(center),
		radius,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircleGradient(
	WrRayLibVector2 center,
	float radius,
	WrRayLibColor inner,
	WrRayLibColor outer
)
{
	::DrawCircleGradient(
		wr2rl_vector2(center),
		radius,
		wr2rl_color(inner),
		wr2rl_color(outer)
	);
}
void WrRayLib::DrawCircleSector(
	WrRayLibVector2 center,
	float radius,
	float startAngle,
	float endAngle,
	int segments,
	WrRayLibColor color
)
{
	::DrawCircleSector(
		wr2rl_vector2(center),
		radius,
		startAngle,
		endAngle,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircleSectorLines(
	WrRayLibVector2 center,
	float radius,
	float startAngle,
	float endAngle,
	int segments,
	WrRayLibColor color
)
{
	::DrawCircleSectorLines(
		wr2rl_vector2(center),
		radius,
		startAngle,
		endAngle,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircleLines(
	int centerX,
	int centerY,
	float radius,
	WrRayLibColor color
)
{
	::DrawCircleLines(
		centerX,
		centerY,
		radius,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircleLinesV(
	WrRayLibVector2 center,
	float radius,
	WrRayLibColor color
)
{
	::DrawCircleLinesV(
		wr2rl_vector2(center),
		radius,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawEllipse(
	int centerX,
	int centerY,
	float radiusH,
	float radiusV,
	WrRayLibColor color
)
{
	::DrawEllipse(
		centerX,
		centerY,
		radiusH,
		radiusV,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawEllipseV(
	WrRayLibVector2 center,
	float radiusH,
	float radiusV,
	WrRayLibColor color
)
{
	::DrawEllipseV(
		wr2rl_vector2(center),
		radiusH,
		radiusV,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawEllipseLines(
	int centerX,
	int centerY,
	float radiusH,
	float radiusV,
	WrRayLibColor color
)
{
	::DrawEllipseLines(
		centerX,
		centerY,
		radiusH,
		radiusV,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawEllipseLinesV(
	WrRayLibVector2 center,
	float radiusH,
	float radiusV,
	WrRayLibColor color
)
{
	::DrawEllipseLinesV(
		wr2rl_vector2(center),
		radiusH,
		radiusV,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRing(
	WrRayLibVector2 center,
	float innerRadius,
	float outerRadius,
	float startAngle,
	float endAngle,
	int segments,
	WrRayLibColor color
)
{
	::DrawRing(
		wr2rl_vector2(center),
		innerRadius,
		outerRadius,
		startAngle,
		endAngle,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRingLines(
	WrRayLibVector2 center,
	float innerRadius,
	float outerRadius,
	float startAngle,
	float endAngle,
	int segments,
	WrRayLibColor color
)
{
	::DrawRingLines(
		wr2rl_vector2(center),
		innerRadius,
		outerRadius,
		startAngle,
		endAngle,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangle(
	int posX,
	int posY,
	int width,
	int height,
	WrRayLibColor color
)
{
	::DrawRectangle(
		posX,
		posY,
		width,
		height,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleV(
	WrRayLibVector2 position,
	WrRayLibVector2 size,
	WrRayLibColor color
)
{
	::DrawRectangleV(
		wr2rl_vector2(position),
		wr2rl_vector2(size),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleRec(
	WrRayLibRectangle rec,
	WrRayLibColor color
)
{
	::DrawRectangleRec(
		wr2rl_rect(rec),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectanglePro(
	WrRayLibRectangle rec,
	WrRayLibVector2 origin,
	float rotation,
	WrRayLibColor color
)
{
	::DrawRectanglePro(
		wr2rl_rect(rec),
		wr2rl_vector2(origin),
		rotation,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleGradientV(
	int posX,
	int posY,
	int width,
	int height,
	WrRayLibColor top,
	WrRayLibColor bottom
)
{
	::DrawRectangleGradientV(
		posX,
		posY,
		width,
		height,
		wr2rl_color(top),
		wr2rl_color(bottom)
	);
}
void WrRayLib::DrawRectangleGradientH(
	int posX,
	int posY,
	int width,
	int height,
	WrRayLibColor left,
	WrRayLibColor right
)
{
	::DrawRectangleGradientH(
		posX,
		posY,
		width,
		height,
		wr2rl_color(left),
		wr2rl_color(right)
	);
}
void WrRayLib::DrawRectangleGradientEx(
	WrRayLibRectangle rec,
	WrRayLibColor topLeft,
	WrRayLibColor bottomLeft,
	WrRayLibColor bottomRight,
	WrRayLibColor topRight
)
{
	::DrawRectangleGradientEx(
		wr2rl_rect(rec),
		wr2rl_color(topLeft),
		wr2rl_color(bottomLeft),
		wr2rl_color(bottomRight),
		wr2rl_color(topRight)
	);
}
void WrRayLib::DrawRectangleLines(
	int posX,
	int posY,
	int width,
	int height,
	WrRayLibColor color
)
{
	::DrawRectangleLines(
		posX,
		posY,
		width,
		height,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleLinesEx(
	WrRayLibRectangle rec,
	float lineThick,
	WrRayLibColor color
)
{
	::DrawRectangleLinesEx(
		wr2rl_rect(rec),
		lineThick,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleRounded(
	WrRayLibRectangle rec,
	float roundness,
	int segments,
	WrRayLibColor color
)
{
	::DrawRectangleRounded(
		wr2rl_rect(rec),
		roundness,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleRoundedLines(
	WrRayLibRectangle rec,
	float roundness,
	int segments,
	WrRayLibColor color
)
{
	::DrawRectangleRoundedLines(
		wr2rl_rect(rec),
		roundness,
		segments,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawRectangleRoundedLinesEx(
	WrRayLibRectangle rec,
	float roundness,
	int segments,
	float lineThick,
	WrRayLibColor color
)
{
	::DrawRectangleRoundedLinesEx(
		wr2rl_rect(rec),
		roundness,
		segments,
		lineThick,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawTriangle(
	WrRayLibVector2 v1,
	WrRayLibVector2 v2,
	WrRayLibVector2 v3,
	WrRayLibColor color
)
{
	::DrawTriangle(
		wr2rl_vector2(v1),
		wr2rl_vector2(v2),
		wr2rl_vector2(v3),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawTriangleLines(
	WrRayLibVector2 v1,
	WrRayLibVector2 v2,
	WrRayLibVector2 v3,
	WrRayLibColor color
)
{
	::DrawTriangleLines(
		wr2rl_vector2(v1),
		wr2rl_vector2(v2),
		wr2rl_vector2(v3),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPoly(
	WrRayLibVector2 center,
	int sides,
	float radius,
	float rotation,
	WrRayLibColor color
)
{
	::DrawPoly(
		wr2rl_vector2(center),
		sides,
		radius,
		rotation,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPolyLines(
	WrRayLibVector2 center,
	int sides,
	float radius,
	float rotation,
	WrRayLibColor color
)
{
	::DrawPolyLines(
		wr2rl_vector2(center),
		sides,
		radius,
		rotation,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPolyLinesEx(
	WrRayLibVector2 center,
	int sides,
	float radius,
	float rotation,
	float lineThick,
	WrRayLibColor color
)
{
	::DrawPolyLinesEx(
		wr2rl_vector2(center),
		sides,
		radius,
		rotation,
		lineThick,
		wr2rl_color(color)
	);
}

// Spline segment point evaluation functions, for a given t [0.0f .. 1.0f]
WrRayLibVector2 WrRayLib::GetSplinePointLinear(
	WrRayLibVector2 startPos,
	WrRayLibVector2 endPos,
	float t
)
{
	return rl2wr_vector2(
		::GetSplinePointLinear(
			wr2rl_vector2(startPos),
			wr2rl_vector2(endPos),
			t
		)
	);
}
WrRayLibVector2 WrRayLib::GetSplinePointBasis(
	WrRayLibVector2 p1,
	WrRayLibVector2 p2,
	WrRayLibVector2 p3,
	WrRayLibVector2 p4,
	float t
)
{
	return rl2wr_vector2(
		::GetSplinePointBasis(
			wr2rl_vector2(p1),
			wr2rl_vector2(p2),
			wr2rl_vector2(p3),
			wr2rl_vector2(p4),
			t
		)
	);
}
WrRayLibVector2 WrRayLib::GetSplinePointCatmullRom(
	WrRayLibVector2 p1,
	WrRayLibVector2 p2,
	WrRayLibVector2 p3,
	WrRayLibVector2 p4,
	float t
)
{
	return rl2wr_vector2(
		::GetSplinePointCatmullRom(
			wr2rl_vector2(p1),
			wr2rl_vector2(p2),
			wr2rl_vector2(p3),
			wr2rl_vector2(p4),
			t
		)
	);
}
WrRayLibVector2 WrRayLib::GetSplinePointBezierQuadratic(
	WrRayLibVector2 p1,
	WrRayLibVector2 c2,
	WrRayLibVector2 p3,
	float t
)
{
	return rl2wr_vector2(
		::GetSplinePointBezierQuadratic(
			wr2rl_vector2(p1),
			wr2rl_vector2(c2),
			wr2rl_vector2(p3),
			t
		)
	);
}
WrRayLibVector2 WrRayLib::GetSplinePointBezierCubic(
	WrRayLibVector2 p1,
	WrRayLibVector2 c2,
	WrRayLibVector2 c3,
	WrRayLibVector2 p4,
	float t
)
{
	return rl2wr_vector2(
		::GetSplinePointBezierCubic(
			wr2rl_vector2(p1),
			wr2rl_vector2(c2),
			wr2rl_vector2(c3),
			wr2rl_vector2(p4),
			t
		)
	);
}

// Basic shapes collision detection functions
bool WrRayLib::CheckCollisionRecs(
	WrRayLibRectangle rec1,
	WrRayLibRectangle rec2
)
{
	return ::CheckCollisionRecs(
		wr2rl_rect(rec1),
		wr2rl_rect(rec2)
	);
}
bool WrRayLib::CheckCollisionCircles(
	WrRayLibVector2 center1,
	float radius1,
	WrRayLibVector2 center2,
	float radius2
)
{
	return ::CheckCollisionCircles(
		wr2rl_vector2(center1),
		radius1,
		wr2rl_vector2(center2),
		radius2
	);
}
bool WrRayLib::CheckCollisionCircleRec(
	WrRayLibVector2 center,
	float radius,
	WrRayLibRectangle rec
)
{
	return ::CheckCollisionCircleRec(
		wr2rl_vector2(center),
		radius,
		wr2rl_rect(rec)
	);
}
bool WrRayLib::CheckCollisionCircleLine(
	WrRayLibVector2 center,
	float radius,
	WrRayLibVector2 p1,
	WrRayLibVector2 p2
)
{
	return ::CheckCollisionCircleLine(
		wr2rl_vector2(center),
		radius,
		wr2rl_vector2(p1),
		wr2rl_vector2(p2)
	);
}
bool WrRayLib::CheckCollisionPointRec(
	WrRayLibVector2 point,
	WrRayLibRectangle rec
)
{
	return ::CheckCollisionPointRec(
		wr2rl_vector2(point),
		wr2rl_rect(rec)
	);
}
bool WrRayLib::CheckCollisionPointCircle(
	WrRayLibVector2 point,
	WrRayLibVector2 center,
	float radius
)
{
	return ::CheckCollisionPointCircle(
		wr2rl_vector2(point),
		wr2rl_vector2(center),
		radius
	);
}
bool WrRayLib::CheckCollisionPointTriangle(
	WrRayLibVector2 point,
	WrRayLibVector2 p1,
	WrRayLibVector2 p2,
	WrRayLibVector2 p3
)
{
	return ::CheckCollisionPointTriangle(
		wr2rl_vector2(point),
		wr2rl_vector2(p1),
		wr2rl_vector2(p2),
		wr2rl_vector2(p3)
	);
}
bool WrRayLib::CheckCollisionPointLine(
	WrRayLibVector2 point,
	WrRayLibVector2 p1,
	WrRayLibVector2 p2,
	int threshold
)
{
	return ::CheckCollisionPointLine(
		wr2rl_vector2(point),
		wr2rl_vector2(p1),
		wr2rl_vector2(p2),
		threshold
	);
}

WrRayLibRectangle WrRayLib::GetCollisionRec(
	WrRayLibRectangle rec1,
	WrRayLibRectangle rec2
)
{
	return rl2wr_rect(
		::GetCollisionRec(
			wr2rl_rect(
				rec1
			),
			wr2rl_rect(
				rec2
			)
		)
	);
}


// Color/pixel related functions

bool WrRayLib::ColorIsEqual(
	WrRayLibColor col1,
	WrRayLibColor col2
)
{
	return ::ColorIsEqual(
		wr2rl_color(col1),
		wr2rl_color(col2)
	);
}
WrRayLibColor WrRayLib::Fade(
	WrRayLibColor color,
	float alpha
)
{
	return rl2wr_color(
		::Fade(
			wr2rl_color(color),
			alpha
		)
	);
}
int WrRayLib::ColorToInt(
	WrRayLibColor color
)
{
	return ::ColorToInt(
		wr2rl_color(color)
	);
}
WrRayLibVector4 WrRayLib::ColorNormalize(
	WrRayLibColor color
)
{
	return rl2wr_vector4(
		::ColorNormalize(
			wr2rl_color(color)
		)
	);
}
WrRayLibColor WrRayLib::ColorFromNormalized(
	WrRayLibVector4 normalized
)
{
	return rl2wr_color(
		::ColorFromNormalized(
			wr2rl_vector4(normalized)
		)
	);
}
WrRayLibVector3 WrRayLib::ColorToHSV(
	WrRayLibColor color
)
{
	return rl2wr_vector3(
		::ColorToHSV(
			wr2rl_color(color)
		)
	);
}
WrRayLibColor WrRayLib::ColorFromHSV(
	float hue,
	float saturation,
	float value
)
{
	return rl2wr_color(
		::ColorFromHSV(
			hue,
			saturation,
			value
		)
	);
}
WrRayLibColor WrRayLib::ColorTint(
	WrRayLibColor color,
	WrRayLibColor tint
)
{
	return rl2wr_color(
		::ColorTint(
			wr2rl_color(color),
			wr2rl_color(tint)
		)
	);
}
WrRayLibColor WrRayLib::ColorBrightness(
	WrRayLibColor color,
	float factor
)
{
	return rl2wr_color(
		::ColorBrightness(
			wr2rl_color(color),
			factor
		)
	);
}
WrRayLibColor WrRayLib::ColorContrast(
	WrRayLibColor color,
	float contrast
)
{
	return rl2wr_color(
		::ColorContrast(
			wr2rl_color(color),
			contrast
		)
	);
}
WrRayLibColor WrRayLib::ColorAlpha(
	WrRayLibColor color,
	float alpha
)
{
	return rl2wr_color(
		::ColorAlpha(
			wr2rl_color(color),
			alpha
		)
	);
}
WrRayLibColor WrRayLib::ColorAlphaBlend(
	WrRayLibColor dst,
	WrRayLibColor src,
	WrRayLibColor tint
)
{
	return rl2wr_color(
		::ColorAlphaBlend(
			wr2rl_color(dst),
			wr2rl_color(src),
			wr2rl_color(tint)
		)
	);
}
WrRayLibColor WrRayLib::ColorLerp(
	WrRayLibColor color1,
	WrRayLibColor color2,
	float factor
)
{
	return rl2wr_color(
		::ColorLerp(
			wr2rl_color(color1),
			wr2rl_color(color2),
			factor
		)
	);
}
WrRayLibColor WrRayLib::GetColor(
	unsigned int hexValue
)
{
	return rl2wr_color(
		::GetColor(
			hexValue
		)
	);
}


// Text drawing functions

void WrRayLib::DrawFPS(
	int posX,
	int posY
)
{
	::DrawFPS(posX, posY);
}
void WrRayLib::DrawText(
	const char* text,
	int posX,
	int posY,
	int fontsize,
	WrRayLibColor color
)
{
	::DrawText(
		text,
		posX,
		posY,
		fontsize,
		wr2rl_color(color)
	);
}


// Text font info functions

void WrRayLib::SetTextLineSpacing(
	int spacing
)
{
	::SetTextLineSpacing(
		spacing
	);
}
int WrRayLib::MeasureText(
	const char* text,
	int fontSize
)
{
	return ::MeasureText(
		text,
		fontSize
	);
}


// Text strings management functions (no UTF-8 strings, only byte chars)

bool WrRayLib::TextIsEqual(
	const char* text1,
	const char* text2
)
{
	return ::TextIsEqual(
		text1,
		text2
	);
}
unsigned int WrRayLib::TextLength(
	const char* text
)
{
	return ::TextLength(
		text
	);
}

const char* WrRayLib::TextSubtext(
	const char* text,
	int position,
	int length
)
{
	return ::TextSubtext(
		text,
		position,
		length
	);
}
const char* WrRayLib::TextRemoveSpaces(
	const char* text
)
{
	return ::TextRemoveSpaces(
		text
	);
}
char* WrRayLib::GetTextBetween(
	const char* text,
	const char* begin,
	const char* end
)
{
	return ::GetTextBetween(
		text,
		begin,
		end
	);
}
char* WrRayLib::TextReplace(
	const char* text,
	const char* search,
	const char* replacement
)
{
	return ::TextReplace(
		text,
		search,
		replacement
	);
}
char* WrRayLib::TextReplaceAlloc(
	const char* text,
	const char* search,
	const char* replacement
)
{
	return ::TextReplaceAlloc(
		text,
		search,
		replacement
	);
}
char* WrRayLib::TextReplaceBetween(
	const char* text,
	const char* begin,
	const char* end,
	const char* replacement
)
{
	return ::TextReplaceBetween(
		text,
		begin,
		end,
		replacement
	);
}
char* WrRayLib::TextReplaceBetweenAlloc(
	const char* text,
	const char* begin,
	const char* end,
	const char* replacement
)
{
	return ::TextReplaceBetweenAlloc(
		text,
		begin,
		end,
		replacement
	);
}

int WrRayLib::TextFindIndex(
	const char* text,
	const char* search
)
{
	return ::TextFindIndex(
		text,
		search
	);
}
char* WrRayLib::TextToUpper(
	const char* text
)
{
	return ::TextToUpper(
		text
	);
}
char* WrRayLib::TextToLower(
	const char* text
)
{
	return ::TextToLower(
		text
	);
}
char* WrRayLib::TextToPascal(
	const char* text
)
{
	return ::TextToPascal(
		text
	);
}
char* WrRayLib::TextToSnake(
	const char* text
)
{
	return ::TextToSnake(
		text
	);
}
char* WrRayLib::TextToCamel(
	const char* text
)
{
	return ::TextToCamel(
		text
	);
}
int WrRayLib::TextToInteger(
	const char* text
)
{
	return ::TextToInteger(
		text
	);
}
float WrRayLib::TextToFloat(
	const char* text
)
{
	return ::TextToFloat(
		text
	);
}


// Basic geometric 3D shapes drawing functions

void WrRayLib::DrawLine3D(
	WrRayLibVector3 startPos,
	WrRayLibVector3 endPos,
	WrRayLibColor color
)
{
	::DrawLine3D(
		wr2rl_vector3(startPos),
		wr2rl_vector3(endPos),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPoint3D(
	WrRayLibVector3 position,
	WrRayLibColor color
)
{
	::DrawPoint3D(
		wr2rl_vector3(position),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCircle3D(
	WrRayLibVector3 center,
	float radius,
	WrRayLibVector3 rotationAxis,
	float rotationAngle,
	WrRayLibColor color
)
{
	::DrawCircle3D(
		wr2rl_vector3(center),
		radius,
		wr2rl_vector3(rotationAxis),
		rotationAngle,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawTriangle3D(
	WrRayLibVector3 v1,
	WrRayLibVector3 v2,
	WrRayLibVector3 v3,
	WrRayLibColor color
)
{
	::DrawTriangle3D(
		wr2rl_vector3(v1),
		wr2rl_vector3(v2),
		wr2rl_vector3(v3),
		wr2rl_color(color)
	);
}

void WrRayLib::DrawCube(
	WrRayLibVector3 position,
	float width,
	float height,
	float length,
	WrRayLibColor color
)
{
	::DrawCube(
		wr2rl_vector3(position),
		width,
		height,
		length,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCubeV(
	WrRayLibVector3 position,
	WrRayLibVector3 size,
	WrRayLibColor color
)
{
	::DrawCubeV(
		wr2rl_vector3(position),
		wr2rl_vector3(size),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCubeWires(
	WrRayLibVector3 position,
	float width,
	float height,
	float length,
	WrRayLibColor color
)
{
	::DrawCubeWires(
		wr2rl_vector3(position),
		width,
		height,
		length,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCubeWiresV(
	WrRayLibVector3 position,
	WrRayLibVector3 size,
	WrRayLibColor color
)
{
	::DrawCubeWiresV(
		wr2rl_vector3(position),
		wr2rl_vector3(size),
		wr2rl_color(color)
	);
}
void WrRayLib::DrawSphere(
	WrRayLibVector3 centerPos,
	float radius,
	WrRayLibColor color
)
{
	::DrawSphere(
		wr2rl_vector3(centerPos),
		radius,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawSphereEx(
	WrRayLibVector3 centerPos,
	float radius,
	int rings,
	int slices,
	WrRayLibColor color
)
{
	::DrawSphereEx(
		wr2rl_vector3(centerPos),
		radius,
		rings,
		slices,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawSphereWires(
	WrRayLibVector3 centerPos,
	float radius,
	int rings,
	int slices,
	WrRayLibColor color
)
{
	::DrawSphereWires(
		wr2rl_vector3(centerPos),
		radius,
		rings,
		slices,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCylinder(
	WrRayLibVector3 position,
	float radiusTop,
	float radiusBottom,
	float height,
	int slices,
	WrRayLibColor color
)
{
	::DrawCylinder(
		wr2rl_vector3(position),
		radiusTop,
		radiusBottom,
		height,
		slices,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCylinderEx(
	WrRayLibVector3 startPos,
	WrRayLibVector3 endPos,
	float startRadius,
	float endRadius,
	int sides,
	WrRayLibColor color
)
{
	::DrawCylinderEx(
		wr2rl_vector3(startPos),
		wr2rl_vector3(endPos),
		startRadius,
		endRadius,
		sides,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCylinderWires(
	WrRayLibVector3 position,
	float radiusTop,
	float radiusBottom,
	float height,
	int slices,
	WrRayLibColor color
)
{
	::DrawCylinderWires(
		wr2rl_vector3(position),
		radiusTop,
		radiusBottom,
		height,
		slices,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCylinderWiresEx(
	WrRayLibVector3 startPos,
	WrRayLibVector3 endPos,
	float startRadius,
	float endRadius,
	int sides,
	WrRayLibColor color
)
{
	::DrawCylinderWiresEx(
		wr2rl_vector3(startPos),
		wr2rl_vector3(endPos),
		startRadius,
		endRadius,
		sides,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCapsule(
	WrRayLibVector3 startPos,
	WrRayLibVector3 endPos,
	float radius,
	int slices,
	int rings,
	WrRayLibColor color
)
{
	::DrawCapsule(
		wr2rl_vector3(startPos),
		wr2rl_vector3(endPos),
		radius,
		slices,
		rings,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawCapsuleWires(
	WrRayLibVector3 startPos,
	WrRayLibVector3 endPos,
	float radius,
	int slices,
	int rings,
	WrRayLibColor color
)
{
	::DrawCapsuleWires(
		wr2rl_vector3(startPos),
		wr2rl_vector3(endPos),
		radius,
		slices,
		rings,
		wr2rl_color(color)
	);
}
void WrRayLib::DrawPlane(
	WrRayLibVector3 centerPos,
	WrRayLibVector2 size,
	WrRayLibColor color
)
{
	::DrawPlane(
		wr2rl_vector3(
			centerPos
		),
		wr2rl_vector2(
			size
		),
		wr2rl_color(
			color
		)
	);
}
void WrRayLib::DrawRay(
	WrRayLibRay ray,
	WrRayLibColor color
)
{
	::DrawRay(
		wr2rl_ray(
			ray
		),
		wr2rl_color(
			color
		)
	);
}
void WrRayLib::DrawGrid(
	int slices,
	float spacing
)
{
	::DrawGrid(
		slices,
		spacing
	);
}


// Collision detection functions

bool WrRayLib::CheckCollisionSpheres(
	WrRayLibVector3 center1,
	float radius1,
	WrRayLibVector3 center2,
	float radius2
)
{
	return ::CheckCollisionSpheres(
		wr2rl_vector3(center1),
		radius1,
		wr2rl_vector3(center2),
		radius2
	);
}


// Audio device management functions

void WrRayLib::InitAudioDevice(
	void
)
{
	::InitAudioDevice();
}
void WrRayLib::CloseAudioDevice(
	void
)
{
	::CloseAudioDevice();
}
bool WrRayLib::IsAudioDeviceReady(
	void
)
{
	return ::IsAudioDeviceReady();
}
void WrRayLib::SetMasterVolume(
	float volume
)
{
	::SetMasterVolume(
		volume
	);
}
float WrRayLib::GetMasterVolume(
	void
)
{
	return ::GetMasterVolume();
}
