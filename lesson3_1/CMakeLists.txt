include_directories(${CMAKE_PROJECT_ROOT}/lesson3_1/include) # 添加头文件目录

# 执行 lesson3_1 目录下的 CMakeLists.txt，用于配置存储力扣刷题代码相关的可执行文件或测试等设置
# 力扣两数之和(暂时测试放在了source/sum.cpp中，运行时将下面测试代码复制到 temporary_test.cpp 中即可)
# add_executable(temporary_test_sum temporary_test.cpp source/sum.cpp)
add_executable(study_two_sum source/sum.cpp)

# 力扣三数之和(暂时测试放在了source/three_sum.cpp中，运行时将下面测试代码复制到 temporary_test.cpp 中即可)
# 每次全部运行的时候，只能开一个，不然 temporary_test.cpp之会链接到第一个
# 目标都使用了temporary_test.cpp作为源文件，但每个源文件只能属于一个可执行目标。

# add_executable(temporary_test_three_sum temporary_test.cpp source/three_sum.cpp)

# 力扣四数之和(暂时测试放在了source/four_sum.cpp中，运行时将下面测试代码复制到 temporary_test.cpp 中即可)
add_executable(temporary_test_four_sum temporary_test.cpp source/four_sum.cpp)

# add_executable(lesson3_1 temporary_test.cpp source/letter_combination.cpp)
