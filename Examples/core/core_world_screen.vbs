Sub Main
	Const screenWidth = 800
	Const screenHeight = 450

	Const CAMERA_PERSPECTIVE = 0
	Const CAMERA_THIRD_PERSON = 4

	Set raylib = CreateObject("Raylib")
	Set RAYWHITE = raylib.CreateColor( 245, 245, 245, 255 )
	Set RED = raylib.CreateColor( 230, 41, 55, 255 )
	Set MAROON = raylib.CreateColor( 190, 33, 55, 255 )
	Set BLACK = raylib.CreateColor( 0, 0, 0, 255 )
	Set LIME = raylib.CreateColor( 0, 158, 47, 255 )
	Set GRAY = raylib.CreateColor( 130, 130, 130, 255 )

	raylib.InitWindow screenWidth, screenHeight, "CoRayLib [core] example - world screen"

	Set camera = raylib.CreateCamera3D
	With camera
		Set .position = raylib.CreateVector3( 10, 10, 10 )
		Set .target = raylib.CreateVector3( 0, 0, 0 )
		Set .up = raylib.CreateVector3( 0, 1, 0 )
		.fovy = 45
		.projection = CAMERA_PERSPECTIVE
	End With

	Set cubePosition = raylib.CreateVector3( 0, 0, 0 )
	Set cubeScreenPosition = raylib.CreateVector2( 0, 0 )

	raylib.DisableCursor
	raylib.SetTargetFPS 60
	While Not raylib.WindowShouldClose
		' Update
		raylib.UpdateCamera camera, CAMERA_THIRD_PERSON
		Set cubeScreenPosition = raylib.GetWorldToScreen( raylib.CreateVector3( cubePosition.x, cubePosition.y + 2.5, cubePosition.z ), camera )

		' Draw
		raylib.BeginDrawing
			raylib.ClearBackground RAYWHITE
			raylib.BeginMode3D camera
				raylib.DrawCube cubePosition, 2, 2, 2, RED
				raylib.DrawCubeWires cubePosition, 2, 2, 2, MAROON
				raylib.DrawGrid 10, 1
			raylib.EndMode3D

			raylib.DrawText "Enemy: 100/100", CInt(cubeScreenPosition.x - raylib.MeasureText( "Enemy: 100/100", 20 ) / 2), CInt(cubeScreenPosition.y), 20, BLACK
			raylib.DrawText raylib.TextFormat( "Cube position in screen space coordinates: [%i, %i]", CInt(cubeScreenPosition.x), CInt(cubeScreenPosition.y)), 10, 10, 20, LIME

			raylib.DrawText "Text 2d should be always on top of the cube", 10, 40, 20, GRAY
		raylib.EndDrawing
	Wend
	raylib.CloseWindow
End Sub

Main
