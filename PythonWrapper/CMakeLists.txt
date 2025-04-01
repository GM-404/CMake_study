cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

include_directories(../lesson1_1)

# 添加 pybind11 子目录
add_subdirectory(../thirdpart/pybind11-2.13.6 ${CMAKE_BINARY_DIR}/thirdpart/pybind11)

# 添加你的目标
pybind11_add_module(lesson bind_add.cpp ../lesson1_1/add.cpp)
