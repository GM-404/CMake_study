include(CTest)
enable_testing()
add_subdirectory(../thirdpart/googletest-1.16.0 ${CMAKE_BINARY_DIR}/thirdpart/googletest) # 非子目录包含的时候需要指定二进制目录

# 添加源文件和测试文件
add_executable(test_add test_add.cpp ../lesson1_1/add.cpp)
target_link_libraries(test_add gtest_main gtest)

target_include_directories(test_add PRIVATE ../lesson1_1) # 添加lesson1_1目录头文件
add_test(NAME test_add COMMAND test_add)