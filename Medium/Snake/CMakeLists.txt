# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(snake)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Specify the compiler if you want to ensure g++ is used (optional)
# This can be skipped if your system's default compiler is g++
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE Debug)

# Add the source files for your project
add_executable(snake main.cpp block.cpp snake.cpp food.cpp snake_game.cpp)

target_link_libraries(snake PRIVATE sfml-graphics sfml-window sfml-system)