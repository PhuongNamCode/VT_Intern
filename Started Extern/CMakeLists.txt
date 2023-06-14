cmake_minimum_required(VERSION 3.12)
project(VT_INTERN)

set(CMAKE_C_STANDARD 11)

include_directories(.)
add_executable(program main.c test.c)
