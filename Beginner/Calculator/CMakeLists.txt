# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(Calculator)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the compiler if you want to ensure g++ is used (optional)
# This can be skipped if your system's default compiler is g++
set(CMAKE_CXX_COMPILER "g++")

# Add the source files for your project
add_executable(Calculator main.cpp Calculator.cpp)