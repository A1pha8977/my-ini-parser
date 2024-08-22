cmake_minimum_required(VERSION 3.29)
project(ini-parser C)
set(CMAKE_C_STANDARD 23)

add_executable(ini-parser
        src/main.c
        src/LinkedList/LinkedList.c
        include/LinkedList/LinkedList.h
)

include_directories(include)