var screenWidth = 800;
var screenHeight = 450;

raylib = new ActiveXObject("RayLib");
RAYWHITE = raylib.CreateColor(245, 245, 245, 255);
LIGHTGRAY = raylib.CreateColor(200, 200, 200, 255);
raylib.InitWindow(screenWidth, screenHeight, "CoRayLib [core] example - basic window");
raylib.SetTargetFPS(60);
while (!raylib.WindowShouldClose()) {
	raylib.BeginDrawing();
	raylib.ClearBackground(RAYWHITE);
	raylib.DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	raylib.EndDrawing();
}
raylib.CloseWindow();
