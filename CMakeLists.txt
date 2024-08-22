cmake_minimum_required(VERSION 3.29)
project(ini-parser C)
set(CMAKE_C_STANDARD 23)

add_executable(ini-parser
        src/main.c
        src/linked-list/linked_list.c
        include/linked-list/linked_list.h
        include/ini-parser/ini-parser.h
)

include_directories(include)