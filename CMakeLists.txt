cmake_minimum_required(VERSION 3.15)
project(filecrud VERSION 0.0.1 LANGUAGES C)
set(CMAKE_C_COMPILER gcc)
string(APPEND CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-parameter")

add_executable(filecrud src/main.c)