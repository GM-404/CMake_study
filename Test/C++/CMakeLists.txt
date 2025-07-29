# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 包含 CTest 模块并启用测试功能
include(CTest)
enable_testing()

# add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/googletest-1.16.0
# ${CMAKE_BINARY_DIR}/thirdpart/googletest) # 非子目录包含的时候需要指定二进制目录

# 定义 Google Test 目录
set(GTEST_DIR ${CMAKE_PROJECT_ROOT}/thirdpart/googletest-1.16.0)

# 检查 Google Test 目录是否存在
if(EXISTS ${GTEST_DIR})
    # 添加 Google Test 子目录
    add_subdirectory(${GTEST_DIR} ${CMAKE_BINARY_DIR}/thirdpart/googletest)
else()
    message(FATAL_ERROR "Google Test directory not found: ${GTEST_DIR}")
endif()

# 第一步：
# 添加源文件和测试文件
# 测试一般文件
add_executable(test_add
    test_add.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)

add_executable(test_sum
    test_sum.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/sum.cpp)

add_executable(test_three_sum
    test_three_sum.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/three_sum.cpp)

add_executable(test_four_sum
    test_four_sum.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/four_sum.cpp)

add_executable(test_letter_combination
    test_letter_combination.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/letter_combination.cpp)
add_executable(test_subarray
    test_subarray.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/subarray.cpp)
add_executable(test_move_zero
    test_move_zero.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/move_zero.cpp)
add_executable(test_collect_rainwater
    test_collect_rainwater.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/collect_rainwater.cpp)
add_executable(test_hasCycle
    test_hasCycle.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/Linked_list.cpp)
add_executable(test_intersect_list
    test_intersect_list.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/Linked_list.cpp)
add_executable(test_reverse_list
    test_reverse_list.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/Linked_list.cpp)
add_executable(test_palindrome_list
    test_palindrome_list.cpp
    ${CMAKE_PROJECT_ROOT}/lesson3_1/source/Linked_list.cpp)

# 测试动态库文件
add_executable(test_del
    test_del.cpp
)
target_link_directories(test_del PRIVATE ${CMAKE_PROJECT_ROOT}/lesson2_1/lib) # 链接动态库

# 第二步：
# 添加所需目录头文件
target_include_directories(test_add PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson1_1/include)
target_include_directories(test_del PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson2_1/del)
target_include_directories(test_sum PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_four_sum PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_letter_combination PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_three_sum PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_subarray PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_move_zero PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_collect_rainwater PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_hasCycle PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_intersect_list PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_reverse_list PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)
target_include_directories(test_palindrome_list PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson3_1/include)

# 第三步：
# 添加 Google Test 头文件目录
# 添加链接库
target_link_libraries(test_add
    gtest_main
    gtest)
target_link_libraries(test_del
    gtest_main
    gtest
    del) # 假设库文件名为 libdel.a 或 del.lib
target_link_libraries(test_sum
    gtest_main
    gtest)
target_link_libraries(test_three_sum
    gtest_main
    gtest)
target_link_libraries(test_four_sum
    gtest_main
    gtest)
target_link_libraries(test_letter_combination
    gtest_main
    gtest)
target_link_libraries(test_subarray
    gtest_main
    gtest)
target_link_libraries(test_move_zero
    gtest_main
    gtest)
target_link_libraries(test_collect_rainwater
    gtest_main
    gtest)
target_link_libraries(test_hasCycle
    gtest_main
    gtest)
target_link_libraries(test_intersect_list
    gtest_main
    gtest)
target_link_libraries(test_reverse_list
    gtest_main
    gtest)
target_link_libraries(test_palindrome_list
    gtest_main
    gtest)

# 第四步：
# 添加测试
add_test(NAME test_add COMMAND test_add)
add_test(NAME test_del COMMAND test_del)
add_test(NAME test_sum COMMAND test_sum)
add_test(NAME test_three_sum COMMAND test_three_sum)
add_test(NAME test_four_sum COMMAND test_four_sum)
add_test(NAME test_letter_combination COMMAND test_letter_combination)
add_test(NAME test_subarray COMMAND test_subarray)
add_test(NAME test_move_zero COMMAND test_move_zero)
add_test(NAME test_collect_rainwater COMMAND test_collect_rainwater)
add_test(NAME test_hasCycle COMMAND test_hasCycle)
add_test(NAME test_intersect_list COMMAND test_intersect_list)
add_test(NAME test_reverse_list COMMAND test_reverse_list)
add_test(NAME test_palindrome_list COMMAND test_palindrome_list)