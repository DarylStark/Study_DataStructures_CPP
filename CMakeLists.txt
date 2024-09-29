# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyArduinoProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Include directories
include_directories(src)

# Add executable target
add_executable(app ${SOURCES})

# Compiler flags
target_compile_options(app PRIVATE -Wall -Wextra -fdiagnostics-color=always)

# Add debug target
add_executable(app_debug ${SOURCES})
target_compile_options(app_debug PRIVATE -g -O0 -Wall -Wextra -fdiagnostics-color=always)
set_target_properties(app_debug PROPERTIES OUTPUT_NAME "app_debug")