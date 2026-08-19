Sub Main
	Const screenWidth = 800
	Const screenHeight = 450

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set GRAY = raylib.CreateColor( 130, 130, 130, 255 )
	Set LIGHTGRAY = raylib.CreateColor( 200, 200, 200, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - input mouse wheel"
	boxPositionY = CInt(screenHeight/2 - 40)
	scrollSpeed = 4
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		boxPositionY = CInt(boxPositionY - (raylib.GetMouseWheelMove()*scrollSpeed))
		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.DrawRectangle screenWidth/2 - 40, boxPositionY, 80, 80, MAROON
		raylib.DrawText "Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY
		raylib.DrawText raylib.TextFormat("Box position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
