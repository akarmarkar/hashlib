cmake_minimum_required(VERSION 2.8.4)
project(hashlib)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS "-std=c99")

set(SOURCE_FILES main.c hash.c hash.h list.c list.h)
add_executable(hashlib ${SOURCE_FILES})