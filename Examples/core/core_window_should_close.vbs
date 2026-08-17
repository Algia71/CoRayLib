Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const KEY_NULL = 0
	Const KEY_N = 78
	Const KEY_Y = 89
	Const KEY_ESCAPE = 256
	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set BLACK = raylib.CreateColor( 0, 0, 0, 255 )
	Set LIGHTGRAY = raylib.CreateColor( 200, 200, 200, 255 )
	Set WHITE = raylib.CreateColor( 255, 255, 255, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - window should close"
	raylib.SetExitKey KEY_NULL
	exitWindowRequested = False
	exitWindow = False
	raylib.SetTargetFPS 60
	While Not exitWindow
		' Update
		If raylib.WindowShouldClose Or raylib.IsKeyPressed( KEY_ESCAPE ) Then
			exitWindowRequested = True
		End If
		If exitWindowRequested Then
			If raylib.IsKeyPressed( KEY_Y ) Then
				exitWindow = True
			ElseIf raylib.IsKeyPressed( KEY_N ) Then
				exitWindowRequested = False
			End If
		End If

		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		If exitWindowRequested Then
			raylib.DrawRectangle 0, 100, screenWidth, 200, BLACK
			raylib.DrawText "Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE
		Else
			raylib.DrawText "Try to close the window to get confirmation message!", 120, 200, 20, LIGHTGRAY
		End If
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
