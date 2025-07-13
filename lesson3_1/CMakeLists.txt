include_directories(${CMAKE_PROJECT_ROOT}/lesson3_1/include) # 添加头文件目录

# 执行 lesson3_1 目录下的 CMakeLists.txt，用于配置存储力扣刷题代码相关的可执行文件或测试等设置
# 力扣两数之和(暂时测试放在了source/sum.cpp中，运行时将下面测试代码复制到 temporary_test.cpp 中即可)
# add_executable(temporary_test_sum temporary_test.cpp source/sum.cpp)
add_executable(study_two_sum source/sum.cpp)

# 力扣三数之和(暂时测试放在了source/three_sum.cpp中，运行时将下面测试代码复制到 temporary_test.cpp 中即可)
add_executable(temporary_test_three_sum temporary_test.cpp source/three_sum.cpp)

# add_executable(lesson3_1 temporary_test.cpp source/letter_combination.cpp)
