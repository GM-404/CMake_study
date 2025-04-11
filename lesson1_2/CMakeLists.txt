# 如果CMAKE_PROJECT_ROOT变量未定义,这里仅供学习使用，可以注释掉根目录下面的试一下看一下效果
if(NOT DEFINED CMAKE_PROJECT_ROOT)
    message(FATAL_ERROR "CMAKE_PROJECT_ROOT is not defined.")
endif()

# 暂时先仅供学习
# # 收集 lesson1_2 目录下的所有 .cpp 文件
# file(GLOB_RECURSE LESSON1_2_SOURCES "*.cpp")

# # 添加 lesson1_1 目录下的 add.cpp
# list(APPEND LESSON1_2_SOURCES ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)
set(ADD_CPP_PATH ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)

# 如果项目需要在不同的操作系统上编译，需要注意路径分隔符的问题。
# 虽然 CMake 会自动处理一些路径分隔符的差异，但为了确保代码的可移植性，可以使用 file(TO_CMAKE_PATH ...) 函数进行路径转换。
file(TO_CMAKE_PATH "${ADD_CPP_PATH}" ADD_CPP_PATH)

add_executable(lesson1_2
    main.cpp
    ${ADD_CPP_PATH})

# add_executable(lesson1_2
# main.cpp
# ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)

# include_directories(${CMAKE_PROJECT_ROOT}/lesson1_1/include)# 设置 lesson1_2 目标的包含目录
# 将包含目录的设置封装成更易读和可维护的形式。
set(LESSON1_2_INCLUDE_DIR ${CMAKE_PROJECT_ROOT}/lesson1_1/include)
target_include_directories(lesson1_2 PRIVATE ${LESSON1_2_INCLUDE_DIR})

# 根据不同的构建类型设置编译选项
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(lesson1_2 PRIVATE -g -O0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(lesson1_2 PRIVATE -O3)
endif()
