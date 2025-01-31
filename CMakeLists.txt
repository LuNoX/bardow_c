cmake_minimum_required(VERSION 3.30)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(bardow C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(bardow main.c
        include/variable.h
        include/units.h
        include/decimals.h)

target_compile_options(bardow PRIVATE -Wall -Wextra -pedantic)