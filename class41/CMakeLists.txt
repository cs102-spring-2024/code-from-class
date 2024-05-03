cmake_minimum_required(VERSION 3.17)
project(stardew)

set(CMAKE_CXX_STANDARD 14)

add_executable(
    stardew
    stardew.cpp
    farmer.cc
    item.cpp
)