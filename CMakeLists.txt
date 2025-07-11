# 项目最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(lesson1_2)

# 设置C++标准
# set是创建变量，赋值变量的方法
# CMAKE_XX是由CMAKE自动创建的变量
# CMake中用户可以自定义变量
set(CMAKE_CXX_STANDARD 17)

# 设置项目根目录，后续如果有需要在其他地方引用项目根目录，可以使用这个变量
set(CMAKE_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "Project root directory set to: ${CMAKE_PROJECT_ROOT}")

# 执行 lesson0_1 目录下的 CMakeLists.txt，用于配置 lesson1_1 目录中的可执行文件相关设置
add_subdirectory(lesson0_1)

# 执行 lesson1_1 目录下的 CMakeLists.txt，用于配置 lesson1_1 目录中的可执行文件相关设置
add_subdirectory(lesson1_1)

# 执行 lesson1_2 目录下的 CMakeLists.txt，用于配置 lesson1_2 目录中的多个文件相关的可执行文件或库设置
add_subdirectory(lesson1_2)

# 执行 lesson2_1 目录下的 CMakeLists.txt，用于配置静态库相关设置
add_subdirectory(lesson2_1)

# 执行 lesson2_2 目录下的 CMakeLists.txt，用于配置动态库相关设置
add_subdirectory(lesson2_2)

# 执行 Test 目录下的 CMakeLists.txt，用于配置单元测试相关设置
add_subdirectory(Test)

# 执行 PythonWrapper 目录下的 CMakeLists.txt，用于配置 Python 包相关设置
add_subdirectory(PythonWrapper)

# 执行 lesson3_1 目录下的 CMakeLists.txt，用于配置存储力扣刷题代码相关的可执行文件或测试等设置
add_subdirectory(lesson3_1)

add_subdirectory(lesson3_2_Eigen)

# 设置 C 和 C++ 编译器的 LTO 选项
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

# # 检查编译器是否支持 LTO链接时间优化是一种编译器优化技术，它允许编译器在链接阶段对整个程序进行全局分析和优化，而不仅仅是在编译单个源文件时进行局部优化。
# 通过 LTO，编译器可以在链接时进行更深入的代码分析和转换，例如内联函数调用、消除冗余代码等，从而生成性能更优的可执行文件。
# if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto")
# endif()

# 检查子目录是否存在，如果不存在则给出提示
foreach(subdir lesson1_1 lesson1_2 lesson2_1 lesson2_2 Test PythonWrapper lesson3_1)
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${subdir})
        message(WARNING "Subdirectory ${subdir} does not exist. Skipping...")
    endif()
endforeach()

# 设置构建类型的默认值为 Debug，可根据需要修改
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()
