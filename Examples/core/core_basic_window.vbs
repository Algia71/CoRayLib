Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set LIGHTGRAY = raylib.CreateColor( 200, 200, 200, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - basic window"
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.DrawText "Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
