cmake_minimum_required(VERSION 3.7)
project(fancy_prints)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES func_prints_test.c func_prints.c func_prints.h)
add_executable(fancy_prints ${SOURCE_FILES})