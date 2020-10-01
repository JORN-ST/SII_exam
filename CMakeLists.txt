cmake_minimum_required(VERSION 3.0)
project(SII_exam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -pthread -lm")

add_executable(SII_exam main.c)