# 项目最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(lesson1_2)

# 设置C++标准
# set是创建变量，赋值变量的方法
# CMAKE_XX是由CMAKE自动创建的变量
# CMake中用户可以自定义变量
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)

add_executable(lesson1_2
    main.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)
