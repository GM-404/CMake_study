include(CTest)
enable_testing()
add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/googletest-1.16.0
    ${CMAKE_BINARY_DIR}/thirdpart/googletest) # 非子目录包含的时候需要指定二进制目录

# 添加源文件和测试文件
add_executable(test_add
    test_add.cpp
    ${CMAKE_PROJECT_ROOT}/lesson1_1/add.cpp)

add_executable(test_del
    test_del.cpp
)
target_link_directories(test_del PRIVATE ${CMAKE_PROJECT_ROOT}/lesson2_1/lib) # 链接动态库

# 添加所需目录头文件
target_include_directories(test_add PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson1_1/include)
target_include_directories(test_del PRIVATE
    ${CMAKE_PROJECT_ROOT}/lesson2_1/del)

# 添加链接库
target_link_libraries(test_add
    gtest_main
    gtest)
target_link_libraries(test_del
    gtest_main
    gtest
    del) # 假设库文件名为 libdel.a 或 del.lib

# 添加测试
add_test(NAME test_add COMMAND test_add)
add_test(NAME test_del COMMAND test_del)