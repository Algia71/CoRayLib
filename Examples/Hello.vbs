' Hello world
'
Set raylib = CreateObject("RayLib")
Set colorBg = raylib.CreateColor(245, 245, 245, 255) 'RAYWHITE
Set colorFg = raylib.CreateColor(112, 31, 126, 255) 'DARKPURPLE
raylib.SetTargetFPS 60
raylib.InitWindow 800, 600, "Hello RayLib from VBScript"
While Not raylib.WindowShouldClose
	raylib.BeginDrawing
	raylib.ClearBackground colorBg
	raylib.DrawText "Hello, World!", 280, 280, 40, colorFg
	raylib.EndDrawing
Wend
raylib.CloseWindow
