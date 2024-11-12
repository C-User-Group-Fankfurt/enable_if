cmake_minimum_required(VERSION 3.10)
project(type_traits)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enable all warnings
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(dependencies/legacy_messages)

add_subdirectory(example_01)
add_subdirectory(example_02)
add_subdirectory(example_03)
add_subdirectory(example_04)
add_subdirectory(example_05)
add_subdirectory(example_06)
