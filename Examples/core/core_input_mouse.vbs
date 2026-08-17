Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const KEY_H = 72
	Const MOUSE_BUTTON_LEFT = 0
	Const MOUSE_BUTTON_RIGHT = 1
	Const MOUSE_BUTTON_MIDDLE = 2
	Const MOUSE_BUTTON_SIDE = 3
	Const MOUSE_BUTTON_EXTRA = 4
	Const MOUSE_BUTTON_FORWARD = 5
	Const MOUSE_BUTTON_BACK = 6

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set DARKGRAY = raylib.CreateColor( 80, 80, 80, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set LIME = raylib.CreateColor( 0, 158, 47, 255 )
	Set DARKBLUE = raylib.CreateColor( 0, 82, 172, 255 )
	Set PURPLE = raylib.CreateColor( 200, 122, 255, 255 )
	Set YELLOW = raylib.CreateColor( 253, 249, 0, 255 )
	Set ORANGE = raylib.CreateColor( 255, 161, 0, 255 )
	Set BEIGE = raylib.CreateColor( 211, 176, 131, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - input mouse"
	Set ballPosition = raylib.CreateVector2( -100, -100 )
	Set ballColor = DARKBLUE
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		If raylib.IsKeyPressed( KEY_H ) Then
			If raylib.IsCursorHidden() Then
				raylib.ShowCursor
			Else
				raylib.HideCursor
			End If
		End If
		Set ballPosition = raylib.GetMousePosition()

		If raylib.IsMouseButtonPressed( MOUSE_BUTTON_LEFT ) Then
			Set ballColor = MAROON
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_MIDDLE ) Then
			Set ballColor = LIME
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_RIGHT ) Then
			Set ballColor = DARKBLUE
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_SIDE ) Then
			Set ballColor = PURPLE
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_EXTRA ) Then
			Set ballColor = YELLOW
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_FORWARD ) Then
			Set ballColor = ORANGE
		ElseIf raylib.IsMouseButtonPressed( MOUSE_BUTTON_BACK ) Then
			Set ballColor = BEIGE
		End If

		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.DrawCircleV ballPosition, 40, ballColor
		raylib.DrawText "move ball with mouse and click mouse button to change color", 10, 10, 20, DARKGRAY
		raylib.DrawText "Press 'H' to toggle cursor visibility", 10, 30, 20, DARKGRAY

		If raylib.IsCursorHidden() Then
			raylib.DrawText "CURSOR HIDDEN", 20, 60, 20, RED
		Else
			raylib.DrawText "CURSOR VISIBLE", 20, 60, 20, LIME
		End If
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
