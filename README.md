# Random-Desktop-App
This is a very random desktop app

## 😀
Using this repository for rizz leveling to pick up on some Qt's 😘

## 🤔
I'll need to figure out how to install all my libraries and make this as portable as possible. ¯\\_(ツ)_/¯

Updates to this read me will follow.

## 🧐
Using vcpkg as the C++ package manager in Windows, but if you know what you're doing feel free to use what ever you want. Using CMake in Unix like OSes tend to be easier than on Windows. Of course that could be just a skill issue on my end 😶

### Prereqs
To run on your desktop there are some prerequisites:
* CMake 3.30+
* Ninja 1.12+
* C++ Compiler supporting C++20 >=
    * MSVC 22+ (Recommended)
    * GCC 12+
    * Clang 18+
* vcpkg latest

### First Build and Run
1. Create a `CMakeUserPresets.json` file.
Here's an example
```json
{
    "version": 10,
    "configurePresets": [
        {
            "name": "x64-debug",
            "inherits": "base",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Debug",
            },
            "environment": {
                "VCPKG_ROOT": "C:/path/to/your/dir/vcpkg"
            }
        }
    ]
}
```
2. Set the VCPKG_ROOT environment variable
    * If using the Developer Powershell for VS: `$env:VCPKG_ROOT=C:/path/to/your/dir/vcpkg`
1. Run command `cmake --preset=x64-debug` or other defined preset in your `CMakeUserPresets.json` file. This will take a while since we are building the dependencies from source.
    * ℹ Quick side note: if you're using Windows MSVC, use the Developer Powershell/Command Prompt for VS. I've added the shell command in `Settings.json`
1. `cmake --build build` builds the project
1. Run Deployment executable for your OS, although it might not be required for Unix like operating systems, it depends on how you installed Qt.
    * Windows Debug: `.\build\vcpkg_installed\x64-windows\tools\Qt6\bin\windeployqt.debug.bat .\build\randomdesktopapp.exe`
    * Windows Release: `.\build\vcpkg_installed\x64-windows\tools\Qt6\bin\windeployqt.exe .\build\randomdesktopapp.exe`
1. Run executable
    * Windows `.\build\randomdesktopapp.exe`

### Updates and Run
To run compilation updates are simpler since all the setup is done upfront in the first time run stage.

1. `cmake --build build`
1. `.\build\randomdesktopapp.exe`

## 🤓
If you're not a neovim developer, I don't know what you're doing with your life. If you're like me, though, you probably depend on some type of Code editor.
### VS Code
I'm currently using VS Code as my main editor for this project. Maybe I'll try different IDEs in the future. Or maybe I'll be a Chad one day and use neovim 😉 I mean it's the whole reason why I'm going through this struggle so that I don't have to depend on using Qt Creator or some weird Visual Studio Qt plugin. I am using CMake and vcpkg to avoid any type of vendor lock in. Anyways enough yappin.

* ***AFTER*** your first build and run is successful, install the recommended plugins for C++
* On the CMake plugin, click on a configuration. If you copy and pasta the `CMakeUserPresets.json` you should see the `x64-debug` configuration. You should be able to see a "document" button on the side. 
* Click the button and it should configure the CMake settings on the IDE. This will help with those annoying red squiggly lines and code completion.