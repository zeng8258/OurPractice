# 最低要求 CMake 版本号
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(my_program)

file(GLOB SRC_FILES *.cpp)

include_directories(include)

add_executable(OurProject main.cpp ${SRC_FILES})