Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Const KEY_S = 83	
	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set LIGHTGRAY = raylib.CreateColor( 200, 200, 200, 255 )
	Set BLACK = raylib.CreateColor( 0, 0, 0, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - scissor test"
	Set scissorArea = raylib.CreateRectangle( 0, 0, 300, 300 )
	scissorMode = True
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		If raylib.IsKeyPressed(KEY_S) Then
			scissorMode =  Not scissorMode
		End If
		scissorArea.x = raylib.GetMouseX() - scissorArea.width/2
		scissorArea.y = raylib.GetMouseY() - scissorArea.height/2
		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		If scissorMode Then
			raylib.BeginScissorMode scissorArea.x, scissorArea.y, scissorArea.width, scissorArea.height
		End If
		raylib.DrawRectangle 0, 0, raylib.GetScreenWidth(), raylib.GetScreenHeight(), RED
		raylib.DrawText "Move the mouse around to reveal this text!", 190, 200, 20, LIGHTGRAY
		If scissorMode Then
			raylib.EndScissorMode
		End If
		raylib.DrawRectangleLinesEx scissorArea, 1, BLACK
		raylib.DrawText "Press S to toggle scissor test", 10, 10, 20, BLACK
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
