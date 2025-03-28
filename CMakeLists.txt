cmake_minimum_required(VERSION 3.30)

project(randomdesktopapp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

qt_add_executable(randomdesktopapp
    main.cpp
)

target_link_libraries(randomdesktopapp PRIVATE Qt6::Core)