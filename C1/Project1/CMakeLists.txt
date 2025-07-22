cmake_minimum_required(VERSION 3.10)
project(Project1 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.c")
add_executable(my_program ${SOURCES})