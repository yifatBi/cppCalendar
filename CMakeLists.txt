cmake_minimum_required(VERSION 3.3)
project(firstEx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    tests/newsimpletest.cpp
    MyDate.cpp
    MyDate.h
    myMain.cpp)

add_executable(firstEx ${SOURCE_FILES})