Option Explicit

Sub Main()
	Dim raylib
	Dim colorBg
	Dim colorFg
	Dim center3
	Dim center4
	Dim center5
	Dim center6
	Dim rotation

	Set raylib = CreateObject("RayLib")
	Set colorBg = raylib.CreateColor(245, 245, 245, 255)	' RAYWHITE
	Set colorFg = raylib.CreateColor(112, 31, 126, 255)	' DARKPURPLE
	Set center3 = raylib.CreateVector2(800 / 4, 600 / 4)
	Set center4 = raylib.CreateVector2(800 / 4 * 3, 600 / 4)
	Set center5 = raylib.CreateVector2(800 / 4, 600 / 4 * 3)
	Set center6 = raylib.CreateVector2(800 / 4 * 3, 600 / 4 * 3)

	raylib.SetTargetFPS 60
	raylib.InitWindow 800, 600, "RayLib Polygons"
	While Not raylib.WindowShouldClose
		raylib.BeginDrawing
		raylib.ClearBackground colorBg
		
		raylib.DrawPoly center3, 3, 130, rotation, colorFg
		raylib.DrawPoly center4, 4, 130, rotation, colorFg
		raylib.DrawPoly center5, 5, 130, rotation, colorFg
		raylib.DrawPoly center6, 6, 130, rotation, colorFg

		raylib.EndDrawing

		rotation = rotation + 0.5
	Wend
	raylib.CloseWindow

	Set center6 = Nothing
	Set center5 = Nothing
	Set center4 = Nothing
	Set center3 = Nothing
	Set colorFg = Nothing
	Set colorBg = Nothing
	Set raylib = Nothing
End Sub

Main
