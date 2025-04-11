# 老版本
# include_directories 是比较旧的 CMake 命令，它会将包含目录应用到整个项目。现代 CMake 更推荐使用目标属性，这样可以更精确地控制哪些目标使用这些包含目录。

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_executable(lesson1_1 main.cpp add.cpp)

# 新版本
# 添加可执行文件
add_executable(lesson1_1 main.cpp add.cpp)

# 设置目标的包含目录
# 这里的 PRIVATE 表示该包含目录仅用于 lesson1_1 目标的编译，不会传递给依赖它的其他目标。
# 输出包含目录信息
# set(CMAKE_MESSAGE_LOG_LEVEL "STATUS")// 设置日志级别，显示下面的message信息,但没啥必要显示状态信息，这里仅供学习参考
# 还可以在.vscode中设置 CMake 的日志级别，具体方法是打开.vscode/settings.json 文件，添加如下内容：
# "cmake.logging.level": "DEBUG" // 设置日志级别为 DEBUG，显示所有信息
message(STATUS "Adding include directory: ${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(lesson1_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 根据编译器设置编译选项，这里我们使用了 GNU 和 Clang 编译器的特定选项。可以根据需要添加其他编译器的选项。
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lesson1_1 PRIVATE -Wall -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(lesson1_1 PRIVATE -Weverything)
endif()

# 根据构建类型设置编译选项，在根目录下面的 CMakeLists.txt 中已经设置了 CMAKE_BUILD_TYPE 变量
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(lesson1_1 PRIVATE -g -O0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(lesson1_1 PRIVATE -O3)
endif()