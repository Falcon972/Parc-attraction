cmake_minimum_required(VERSION 3.23)
project(spritesmr C)

set(CMAKE_C_STANDARD 99)

add_executable(spritesmr main.c)

target_link_libraries(spritesmr -lmingw32 -lalleg44)