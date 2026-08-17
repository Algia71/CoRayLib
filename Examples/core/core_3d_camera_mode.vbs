Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const CAMERA_PERSPECTIVE = 0

	Set raylib = CreateObject("Raylib")
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - 3d camera mode"

	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set DARKGRAY = raylib.CreateColor( 80, 80, 80, 255 )

	Set camera = CreateObject("Raylib.Camera3D")
	Set camera.position = raylib.CreateVector3( 0, 10, 10 )
	Set camera.target = raylib.CreateVector3( 0, 0, 0 )
	Set camera.up = raylib.CreateVector3( 0, 1, 0 )
	camera.fovy = 45
	camera.projection = CAMERA_PERSPECTIVE

	Set cubePosition = raylib.CreateVector3( 0, 0, 0 )

	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.BeginMode3D camera
		raylib.DrawCube cubePosition, 2, 2, 2, RED
		raylib.DrawCubeWires cubePosition, 2, 2, 2, MAROON
		raylib.DrawGrid 10, 1
		raylib.EndMode3D
		raylib.DrawText "Welcome to the third dimension!", 10, 40, 20, DARKGRAY
		raylib.DrawFPS 10, 10
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
