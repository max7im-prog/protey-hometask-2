cmake_minimum_required(VERSION 3.10.0)
project(protey-hometask-2-testbench VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(testProgram src/main.cpp)

target_link_libraries(testProgram PRIVATE FileControl)