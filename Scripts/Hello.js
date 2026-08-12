// Hello world
//
raylib = new ActiveXObject("RayLib");
colorBg = raylib.CreateColor(245, 245, 245, 255); // RAYWHITE
colorFg = raylib.CreateColor(112, 31, 126, 255); // DARKPURPLE
raylib.SetTargetFPS(60);
raylib.InitWindow(800, 600, "Hello RayLib from JScript");
while (!raylib.WindowShouldClose()) {
	raylib.BeginDrawing();
	raylib.ClearBackground(colorBg);
	raylib.DrawText("Hello, World!", 280, 280, 40, colorFg);
	raylib.EndDrawing();
}
raylib.CloseWindow();
