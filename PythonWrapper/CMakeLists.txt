cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)
include_directories(${CMAKE_PROJECT_ROOT}/lesson2_1/lib)

# 添加 pybind11 子目录
add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/pybind11-2.13.6 ${CMAKE_BINARY_DIR}/thirdpart/pybind11)

# 添加你的目标
pybind11_add_module(add bind_add.cpp ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)
pybind11_add_module(band_class bind_example.cpp ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)
pybind11_add_module(del_ctest bind_del.cpp)

# 链接静态库到 pybind11 模块
target_link_libraries(del_ctest PRIVATE ${CMAKE_PROJECT_ROOT}/lesson2_1/lib/libdel.a)
