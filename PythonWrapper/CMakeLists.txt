cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED CMAKE_PROJECT_ROOT)
    message(FATAL_ERROR "CMAKE_PROJECT_ROOT is not defined.")
endif()

# 定义包含目录列表,好像没啥用
set(INCLUDE_DIRS
    ${CMAKE_PROJECT_ROOT}/lesson1_1/include
    ${CMAKE_PROJECT_ROOT}/lesson2_1/lib
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include
)

# 检查包含目录是否存在并添加
foreach(INCLUDE_DIR ${INCLUDE_DIRS})
    if(EXISTS ${INCLUDE_DIR})
        message(STATUS "Adding include directory: ${INCLUDE_DIR}")
    else()
        message(FATAL_ERROR "Include directory not found: ${INCLUDE_DIR}")
    endif()
endforeach()

# 添加 pybind11 子目录
# add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/pybind11-2.13.6 ${CMAKE_BINARY_DIR}/thirdpart/pybind11)
# 添加 pybind11 子目录
set(PYBIND11_DIR ${CMAKE_PROJECT_ROOT}/thirdpart/pybind11-2.13.6)

if(EXISTS ${PYBIND11_DIR})
    add_subdirectory(${PYBIND11_DIR} ${CMAKE_BINARY_DIR}/thirdpart/pybind11)
else()
    message(FATAL_ERROR "pybind11 directory not found: ${PYBIND11_DIR}")
endif()

include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)
include_directories(${CMAKE_PROJECT_ROOT}/lesson2_1/lib)
include_directories(${CMAKE_PROJECT_ROOT}/lesson3_1/include)

# # # 设置输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Test/Python/)
# 设置输出路径
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Test/Python/)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH})
# message(STATUS "Output path for libraries: ${LIBRARY_OUTPUT_PATH}")
pybind11_add_module(add
    bind_add.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp
)

pybind11_add_module(band_class
    bind_class.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp
)

pybind11_add_module(del_ctest
    bind_del.cpp
)
pybind11_add_module(bind_sum
    bind_sum.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/sum.cpp
)
pybind11_add_module(bind_letter
    bind_letter.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/letter_combination.cpp
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
