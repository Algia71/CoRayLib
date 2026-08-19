Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const KEY_R = 82
	Const speed = 10
	Const circleRadius = 32

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set BLUE = raylib.CreateColor( 0, 121, 241, 255 )
	Set DARKGRAY = raylib.CreateColor( 80, 80, 80, 255 )

	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - delta time"
	currentFps = 60
	Set deltaCircle = raylib.CreateVector2( 0, screenHeight / 3 )
	Set frameCircle = raylib.CreateVector2( 0, screenHeight * ( 2 / 3 ) )

	raylib.SetTargetFPS currentFps
	While Not raylib.WindowShouldClose
		' Update
		mouseWheel = raylib.GetMouseWheelMove
		If mouseWheel <> 0 Then
			currentFps = currentFps + CInt(mouseWheel)
			If currentFps < 0 Then
				currentFps = 0
			End If
			raylib.SetTargetFPS currentFps
		End If
		deltaCircle.x = deltaCircle.x + raylib.GetFrameTime() * 6 * speed
		frameCircle.x = frameCircle.x + 0.1 * speed
		If deltaCircle.x > screenWidth Then
			deltaCircle.x = 0
		End If
		If frameCircle.x > screenWidth Then
			frameCircle.x = 0
		End If
		If raylib.IsKeyPressed( KEY_R ) Then
			deltaCircle.x = 0
			frameCircle.x = 0
		End If
		' Draw
		raylib.BeginDrawing
			raylib.ClearBackground RAYWHITE
			raylib.DrawCircleV deltaCircle, circleRadius, RED
			raylib.DrawCircleV frameCircle, circleRadius, BLUE

			fpsText = ""
			If currentFps <= 0 Then
				fpsText = raylib.TextFormat("FPS: unlimited (%i)", raylib.GetFPS())
			Else
				fpsText = raylib.TextFormat("FPS: %i (target: %i)", raylib.GetFPS(), currentFps )
			End If
			raylib.DrawText fpsText, 10, 10, 20, DARKGRAY
			raylib.DrawText raylib.TextFormat("Frame time: %02.02f ms", raylib.GetFrameTime()), 10, 30, 20, DARKGRAY
			raylib.DrawText "Use the scroll wheel to change the fps limit, r to reset", 10, 50, 20, DARKGRAY
			raylib.DrawText "FUNC: x += GetFrameTime()*speed", 10, 90, 20, RED
			raylib.DrawText "FUNC: x += speed", 10, 240, 20, BLUE
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
