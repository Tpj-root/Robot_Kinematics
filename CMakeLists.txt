# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(TriangleCalculator)

# Specify the C standard (optional)
set(CMAKE_C_STANDARD 99)

# Enable verbose output in Makefile
set(CMAKE_VERBOSE_MAKEFILE ON)

# Add the executable for pythagoras
add_executable(pythagoras src/pythagoras.c)

# Add the executable for pythagora_angle
add_executable(pythagora_angle src/pythagora_angle.c)

add_executable(rotate_point src/rotate_point.c)

# Link the math library (for using -lm) to both executables
target_link_libraries(pythagoras m)
target_link_libraries(pythagora_angle m)
target_link_libraries(rotate_point m)

