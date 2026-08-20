Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const CAMERA_FREE = 1
	Const CAMERA_PERSPECTIVE = 0
	Const KEY_Z = 90

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set SKYBLUE = raylib.CreateColor( 102, 191, 255, 255 )
	Set BLUE = raylib.CreateColor( 0, 121, 241, 255 )
	Set BLACK = raylib.CreateColor( 0, 0, 0, 255 )
	Set DARKGRAY = raylib.CreateColor( 80, 80, 80, 255 )
	Set camera = raylib.CreateCamera3D
	With camera
		Set .position = raylib.CreateVector3( 10, 10, 10 )
		Set .target = raylib.CreateVector3( 0, 0, 0 )
		Set .up = raylib.CreateVector3( 0, 1, 0 )
		camera.fovy = 45
		camera.projection = CAMERA_PERSPECTIVE
	End With
	Set cubePosition = raylib.CreateVector3( 0, 0, 0 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - 3d camera free"
	raylib.DisableCursor
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		raylib.UpdateCamera camera, CAMERA_FREE
		If raylib.IsKeyPressed( KEY_Z ) Then
			Set camera.target = raylib.CreateVector3( 0, 0, 0 )
		End If
		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.BeginMode3D camera
		raylib.DrawCube cubePosition, 2, 2, 2, RED
		raylib.DrawCubeWires cubePosition, 2, 2, 2, MAROON
		raylib.DrawGrid 10, 1
		raylib.EndMode3D
		raylib.DrawRectangle 10, 10, 320, 93, raylib.Fade( SKYBLUE, 0.5 )
		raylib.DrawRectangleLines 10, 10, 320, 93, BLUE

		raylib.DrawText "Free camera default controls:", 20, 20, 10, BLACK
		raylib.DrawText "- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY
		raylib.DrawText "- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY
		raylib.DrawText "- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
