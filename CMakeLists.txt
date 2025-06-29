cmake_minimum_required(VERSION 3.30)

project(randomdesktopapp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia MultimediaWidgets)
find_package(qtadvanceddocking-qt6 REQUIRED)
qt_standard_project_setup()

add_subdirectory(src/app)