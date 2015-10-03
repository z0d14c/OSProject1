cmake_minimum_required(VERSION 3.3)
project(OSConceptsP1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES main.cpp CPU.cpp CPU.h Memory.cpp Memory.h)
add_executable(OSConceptsP1 ${SOURCE_FILES})