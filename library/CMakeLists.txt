cmake_minimum_required(VERSION 3.10.0)
project(protey-hometask-2-lib VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(FileControl SHARED src/fileControl.cpp)

target_include_directories(FileControl PUBLIC src)

