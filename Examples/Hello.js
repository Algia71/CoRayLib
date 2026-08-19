// Hello world
//
raylib = new ActiveXObject("RayLib");
RAYWHITE = raylib.CreateColor(245, 245, 245, 255);
DARKPURPLE = raylib.CreateColor(112, 31, 126, 255);
raylib.SetTargetFPS(60);
raylib.InitWindow(800, 600, "Hello RayLib from JScript");
while (!raylib.WindowShouldClose()) {
	raylib.BeginDrawing();
	raylib.ClearBackground(RAYWHITE);
	raylib.DrawText("Hello, World!", 280, 280, 40, DARKPURPLE);
	raylib.EndDrawing();
}
raylib.CloseWindow();
