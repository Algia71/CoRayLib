' Multiple Bounces
'

Const PI = 3.1415926535897932384626433832795
Const NumberOfBalls = 40
Const RadiusOfBalls = 30
Const TargetFPS = 60
Const WindowWidth = 800
Const WindowHeight = 600

Function GetRandomColor(raylib)
	Dim r
	Dim g
	Dim b

	r = 255 * Rnd
	g = 255 * Rnd
	b = 255 * Rnd
	Set GetRandomColor = raylib.CreateColor(r, g, b, 255)
End Function

Function GetRandomVelocity()
	GetRandomVelocity = 20 * Rnd + 1
End Function

Function GetRandomDirection()
	GetRandomDirection = PI * Rnd
End Function

Function GetRandomPosition(raylib, width, height)
	Dim x
	Dim y

	x = width * Rnd
	y = height * Rnd
	Set GetRandomPosition = raylib.CreateVector2(x, y)
End Function

Class BouncingBall
	Private m_radius
	Private m_color
	Private m_position
	Private m_velocity
	Private m_direction

	Public Sub CTor(raylib, width, height, radius)
		m_radius = radius
		Set m_color = GetRandomColor(raylib)
		Set m_position = GetRandomPosition(raylib, width, height)
		m_velocity = GetRandomVelocity()
		m_direction = GetRandomDirection()
	End Sub

	Public Sub Draw(raylib)
		raylib.DrawCircleV m_position, m_radius, m_color
	End Sub

	Public Sub Move(width, height)
		Dim new_direction
		Dim new_x
		Dim new_y
		Dim half_radius

		new_direction = m_direction
		new_x = m_position.x + Cos(m_direction) * m_velocity
		new_y = m_position.y + Sin(m_direction) * m_velocity

		half_radius = m_radius / 2

		' X
		If (new_x - half_radius <= 0) Or (new_x + half_radius >= width) Then
			new_direction = PI - new_direction
		' Y 
		Elseif (new_y - half_radius <= 0) Or (new_y + half_radius >= height) Then
			new_direction = -new_direction
		End If

		m_direction = new_direction
		m_position.x = m_position.x + Cos(m_direction) * m_velocity
		m_position.y = m_position.y + Sin(m_direction) * m_velocity
	End Sub
End Class

Class BouncingBalls
	Private balls()
	Private m_raylib
	Private m_width
	Private m_height

	Public Sub CTor(raylib, width, height, radius)
		Dim i

		ReDim balls(NumberOfBalls)
		Set m_raylib = raylib
		m_width = width
		m_height = height
		For i = 0 To NumberOfBalls - 1
			Set balls(i) = New BouncingBall
			balls(i).CTor m_raylib, m_width, m_height, radius
		Next
	End Sub

	Public Sub Draw
		Dim i

		For i = 0 To NumberOfBalls - 1
			balls(i).Draw m_raylib
		Next
	End Sub

	Public Sub Move
		Dim i

		For i = 0 To NumberOfBalls - 1
			balls(i).Move m_width, m_height
		Next
	End Sub
End Class

Sub Main
    Dim raylib
	Dim colorBg
	Dim balls

	Randomize
	Set raylib = CreateObject("RayLib")
	Set colorBg = GetRandomColor(raylib)

	Set balls = New BouncingBalls
	balls.CTor raylib, WindowWidth, WindowHeight, RadiusOfBalls

	raylib.SetTargetFPS TargetFPS
	raylib.InitWindow WindowWidth, WindowHeight, "RayLib Bounces (VBScript)"
	While Not raylib.WindowShouldClose
		raylib.BeginDrawing
		raylib.ClearBackground colorBg
		balls.Draw
		raylib.DrawFPS 10, 10
		raylib.EndDrawing
		balls.Move
	Wend
	raylib.CloseWindow

	Set balls = Nothing
    Set raylib = Nothing
End Sub

Main
