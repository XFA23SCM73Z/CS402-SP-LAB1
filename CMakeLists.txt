cmake_minimum_required(VERSION 3.26)
project(CS402_SP_LAB1 C)

set(CMAKE_C_STANDARD 11)

add_executable(CS402_SP_LAB1 main.c
        employee.h
        employee.c
        readfile.h
        readfile.c)
