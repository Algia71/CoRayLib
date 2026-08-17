// Multiple Bounces
//

var PI = 3.1415926535897932384626433832795;
var NumberOfBalls = 40;
var RadiusOfBalls = 30;
var TargetFPS = 60;
var WindowWidth = 800;
var WindowHeight = 600;

function GetRandomColor(raylib) {
	var r, g, b;

	r = 255 * Math.random();
	g = 255 * Math.random();
	b = 255 * Math.random();
	return raylib.CreateColor(r, g, b, 255);
}

function GetRandomVelocity() {
	return 20 * Math.random() + 1;
}

function GetRandomDirection() {
	return PI * Math.random();
}

function GetRandomPosition(raylib, width, height) {
	var x, y;

	x = width * Math.random();
	y = height * Math.random();
	return raylib.CreateVector2(x, y);
}

// Class BouncingBall
function BouncingBall(raylib, width, height, radius) {
	this.m_radius = radius;
	this.m_color = GetRandomColor(raylib);
	this.m_position = GetRandomPosition(raylib, width, height);
	this.m_velocity = GetRandomVelocity();
	this.m_direction = GetRandomDirection();
}

BouncingBall.prototype.Draw = function (raylib) {
	raylib.DrawCircleV(this.m_position, this.m_radius, this.m_color);
};

BouncingBall.prototype.Move = function (width, height) {
	var new_direction;
	var new_x;
	var new_y;
	var half_radius;

	new_direction = this.m_direction;
	new_x = this.m_position.x + Math.cos(this.m_direction) * this.m_velocity;
	new_y = this.m_position.y + Math.sin(this.m_direction) * this.m_velocity;

	half_radius = this.m_radius / 2;

	// X
	if ((new_x - half_radius <= 0) || (new_x + half_radius >= width)) {
		new_direction = PI - new_direction;
	}
	// Y
	else if ((new_y - half_radius <= 0) || (new_y + half_radius >= height)) {
		new_direction = -new_direction;
	}

	this.m_direction = new_direction;
	this.m_position.x = this.m_position.x + Math.cos(this.m_direction) * this.m_velocity;
	this.m_position.y = this.m_position.y + Math.sin(this.m_direction) * this.m_velocity;
};

// Class BouncingBalls
function BouncingBalls(raylib, width, height, radius) {
	var i;

	this.balls = new Array(NumberOfBalls);
	this.m_raylib = raylib;
	this.m_width = width;
	this.m_height = height;
	for (i = 0; i < NumberOfBalls; i++) {
		this.balls[i] = new BouncingBall(this.m_raylib, this.m_width, this.m_height, radius);
	}
}

BouncingBalls.prototype.Draw = function () {
	var i;

	for (i = 0; i < NumberOfBalls; i++) {
		this.balls[i].Draw(this.m_raylib);
	}
};

BouncingBalls.prototype.Move = function () {
	var i;

	for (i = 0; i < NumberOfBalls; i++) {
		this.balls[i].Move(this.m_width, this.m_height);
	}
};

function Main() {
	var raylib;
	var colorBg;
	var balls;

	raylib = new ActiveXObject("RayLib");
	colorBg = GetRandomColor(raylib);

	balls = new BouncingBalls(raylib, WindowWidth, WindowHeight, RadiusOfBalls);

	raylib.SetTargetFPS(TargetFPS);
	raylib.InitWindow(WindowWidth, WindowHeight, "RayLib Bounces (JScript)");
	while (!raylib.WindowShouldClose()) {
		raylib.BeginDrawing();
		raylib.ClearBackground(colorBg);
		balls.Draw();
		raylib.DrawFPS(10, 10);
		raylib.EndDrawing();
		balls.Move();
	}
	raylib.CloseWindow();

	balls = null;
	raylib = null;
}

Main();
