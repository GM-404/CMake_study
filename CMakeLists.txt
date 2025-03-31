# 项目最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(lesson1_2)

# 设置C++标准
# set是创建变量，赋值变量的方法
# CMAKE_XX是由CMAKE自动创建的变量
# CMake中用户可以自定义变量
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}) # 项目根目录

add_subdirectory(lesson1_1) # 会执行lesson1_1/CMakeLists.txt，配置单个文件夹下的
add_subdirectory(lesson1_2) # 会执行lesson1_2/CMakeLists.txt，配置多个文件夹下的

add_subdirectory(lesson2_1) # 会执行lesson1_3/CMakeLists.txt，配置静态库
add_subdirectory(lesson2_2) # 会执行lesson1_4/CMakeLists.txt，配置动态库

include(CTest)
enable_testing()
add_subdirectory(thirdpart/googletest-1.16.0)

# 添加源文件和测试文件
add_executable(test_add test/test_add.cpp adds.cpp)
target_link_libraries(test_add gtest_main gtest)

target_include_directories(test_add PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME test_add COMMAND test_add)
