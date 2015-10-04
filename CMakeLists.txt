cmake_minimum_required(VERSION 3.3)
project(LCTHW)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c99")

set(SOURCE_FILES Ex10/ex10.c)
add_executable(Ex10 ${SOURCE_FILES})