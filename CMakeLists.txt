cmake_minimum_required(VERSION 3.30)
project(stack_labyrinth)

set(CMAKE_CXX_STANDARD 20)

add_executable(stack_labyrinth src/main.cpp
        include/c_stack.cpp
        include/c_stack.h
        src/test.h
        src/labyrinth.h)
