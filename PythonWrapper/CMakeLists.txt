cmake_minimum_required(VERSION 3.10)

include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)
include_directories(${CMAKE_PROJECT_ROOT}/lesson2_1/lib)

# 添加 pybind11 子目录
add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/pybind11-2.13.6 ${CMAKE_BINARY_DIR}/thirdpart/pybind11)

# # # 设置输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Test/Python/)

# 添加你的目标
pybind11_add_module(add
    bind_add.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp
)

pybind11_add_module(band_class
    bind_class.cpp
)

pybind11_add_module(del_ctest
    bind_del.cpp
)

# # 链接静态库到 pybind11 模块
# target_link_libraries(del_ctest PRIVATE ${CMAKE_PROJECT_ROOT}/lesson2_1/lib/libdel.a)

# 查找静态库
find_library(DEL_LIB del ${CMAKE_PROJECT_ROOT}/lesson2_1/lib)

# DEL_LIB <VAR>：这是一个自定义的变量名。当 find_library 命令成功找到指定名称的库文件时，会把该库文件的完整路径存储到这个变量中。
# 在你的代码里，DEL_LIB 就是这个变量，后续你可以通过引用 DEL_LIB 来获取找到的 libdel.a 库的路径。
# 检查是否找到静态库
if(DEL_LIB)
    # 链接静态库到 pybind11 模块
    target_link_libraries(del_ctest PRIVATE ${DEL_LIB})
else()
    message(FATAL_ERROR "Could not find libdel.a")
endif()