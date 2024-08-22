cmake_minimum_required(VERSION 3.29)
project(game_saves_manager C)
set(CMAKE_C_STANDARD 23)

add_executable(game_saves_manager
        src/main.c
        src/LinkedList/LinkedList.c
        include/LinkedList/LinkedList.h
)

include_directories(include)