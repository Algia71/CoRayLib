Sub Main
	Const screenWidth = 800
	Const screenHeight = 450
	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set LIGHTGRAY = raylib.CreateColor( 200, 200, 200, 255 )
	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - random values"
	randValue = raylib.GetRandomValue( -8, 5 )
	framesCounter = 0
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		framesCounter = framesCounter + 1
		If ( ( framesCounter / 120 ) Mod 2 ) = 1 Then
			randValue = raylib.GetRandomValue( -8, 5 )
			framesCounter = 0
		End If
		' Draw
		raylib.BeginDrawing
		raylib.ClearBackground RAYWHITE
		raylib.DrawText "Every 2 seconds a new random value is generated:", 130, 100, 20, MAROON
		raylib.DrawText raylib.TextFormat( "%i", CInt(randValue) ), 360, 180, 80, LIGHTGRAY
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
