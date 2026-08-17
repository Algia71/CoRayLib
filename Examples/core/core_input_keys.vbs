Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const KEY_RIGHT = 262
	Const KEY_LEFT = 263
	Const KEY_DOWN = 264
	Const KEY_UP = 265

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set DARKGRAY = raylib.CreateColor( 80, 80, 80, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - input keys"
	Set ballPosition = raylib.CreateVector2( screenWidth/2, screenHeight/2 )
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		If raylib.IsKeyDown( KEY_RIGHT ) Then
			ballPosition.x = ballPosition.x + 2
		End If
		If raylib.IsKeyDown( KEY_LEFT ) Then
			ballPosition.x = ballPosition.x - 2
		End If
		If raylib.IsKeyDown( KEY_UP ) Then
			ballPosition.y = ballPosition.y - 2
		End If
		If raylib.IsKeyDown( KEY_DOWN ) Then
			ballPosition.y = ballPosition.y + 2
		End If

		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.DrawText "move the ball with arrow keys", 10, 10, 20, DARKGRAY
		raylib.DrawCircleV ballPosition, 50, MAROON
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
