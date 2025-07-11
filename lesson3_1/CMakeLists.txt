include_directories(${CMAKE_PROJECT_ROOT}/lesson3_1/include) # 添加头文件目录

# 执行 lesson3_1 目录下的 CMakeLists.txt，用于配置存储力扣刷题代码相关的可执行文件或测试等设置
# 力扣两数之和(注意，运行temporary_test_sum时候需要注释掉source/sum.cpp中的main函数)
# add_executable(temporary_test_sum temporary_test.cpp source/sum.cpp)
add_executable(study_temporary_test_sum source/sum.cpp)

#
# add_executable(lesson3_1 source/three_sum.cpp)

# add_executable(lesson3_1 temporary_test.cpp source/letter_combination.cpp)
