cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)

# 添加 pybind11 子目录
add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/pybind11-2.13.6 ${CMAKE_BINARY_DIR}/thirdpart/pybind11)

# 添加你的目标
pybind11_add_module(lesson bind_add.cpp ../lesson1_1/add.cpp)
