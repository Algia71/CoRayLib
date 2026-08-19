' Hello world
'
Set raylib = CreateObject("RayLib")
Set RAYWHITE = raylib.CreateColor(245, 245, 245, 255)
Set DARKPURPLE = raylib.CreateColor(112, 31, 126, 255)
raylib.SetTargetFPS 60
raylib.InitWindow 800, 600, "Hello RayLib from VBScript"
While Not raylib.WindowShouldClose
	raylib.BeginDrawing
	raylib.ClearBackground RAYWHITE
	raylib.DrawText "Hello, World!", 280, 280, 40, DARKPURPLE
	raylib.EndDrawing
Wend
raylib.CloseWindow
