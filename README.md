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

### Running
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