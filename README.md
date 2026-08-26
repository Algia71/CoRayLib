# A Windows COM raylib wrapper
This is a [Windows Component Object Model (COM)](https://en.wikipedia.org/wiki/Component_Object_Model) **wrapper** of the [raylib](https://github.com/raysan5/raylib) library.

![CoRayLib](https://github.com/Algia71/raylib-COM/blob/master/Images/CoRayLib.png?raw=true)

Through this wrapper, **raylib** functions and structures can be used by any **Windows COM client**, such as [Windows Script Host (WSH)](https://en.wikipedia.org/wiki/Windows_Script_Host) and [Visual Basic For Applications (VBA)](https://en.wikipedia.org/wiki/Visual_Basic_for_Applications). For instance, you can write [VBScript](https://en.wikipedia.org/wiki/VBScript) and [JScript](https://en.wikipedia.org/wiki/JScript) programs (.vbs and .js text files) to create graphical animations, games, etc. with raylib.

### Hello World (VBScript)

```VBScript
' Hello world
'
Set raylib = CreateObject("RayLib")
Set RAYWHITE = raylib.CreateColor(245, 245, 245, 255)
Set DARKPURPLE = raylib.CreateColor(112, 31, 126, 255)
raylib.SetTargetFPS 60
raylib.InitWindow 850, 200, "Hello RayLib from VBScript"
While Not raylib.WindowShouldClose
    raylib.BeginDrawing
    raylib.ClearBackground RAYWHITE
    raylib.DrawText "Hello, World!", 300, 80, 40, DARKPURPLE
    raylib.EndDrawing
Wend
raylib.CloseWindow
```
![VBScript Hello World](https://github.com/Algia71/raylib-COM/blob/master/Images/hello-world-vbs.png?raw=true)

### Hello World (JScript)

```JavaScript
// Hello world
//
raylib = new ActiveXObject("RayLib");
DARKPURPLE = raylib.CreateColor(112, 31, 126, 255);
RAYWHITE = raylib.CreateColor(245, 245, 245, 255);
raylib.SetTargetFPS(60);
raylib.InitWindow(850, 200, "Hello RayLib from JScript");
while (!raylib.WindowShouldClose()) {
	raylib.BeginDrawing();
	raylib.ClearBackground(DARKPURPLE);
	raylib.DrawText("Hello, World!", 300, 80, 40, RAYWHITE);
	raylib.EndDrawing();
}
raylib.CloseWindow();
```
![JScript Hello World](https://github.com/Algia71/raylib-COM/blob/master/Images/hello-world-js.png?raw=true)

### Status
*The wrapper covers only a (small) part of the raylib API. According to my needs and your feedbacks, I will add more raylib APIs to the wrapper. At the moment 274 out of 598 raylib APIs (~46%) are wrapped*.

### raylib version
I wrapped **raylib version 6.0** (23 April 2026). `raylib.lib` binary files (debug and release versions) are included precompiled within the project.

### Visual Studio version
Project files were made with the Community Version **2022** (64-bit, v143), version 17.14.37 (July 2026).

## How to...
### ...build:
It should be simple: open the solution in Visual Studio, choose **Debug** or **Release** and press **F7**. Please ensure that the **x64** platform is selected. The final output of the build process is the `CoRayLib.dll` located in the `x64\Debug` or `x64\Release` folder.

### ...install:
Copy `CoRayLib.dll` to a local directory (e.g. `C:\coraylib`), open a terminal with administrative privileges (e.g. **Windows PowerShell**) and then run the command `regsvr32 c:\coraylib\CoRayLib.dll` .

### ...test:
Double click on one of the .vbs or .js scripts provided in the `Examples` folder.  

### ...uninstall:
Open a terminal with administrative privileges and run the command `regsvr32 /u c:\coraylib\CoRayLib.dll` . Then simply delete `CoRayLib.dll`. 
