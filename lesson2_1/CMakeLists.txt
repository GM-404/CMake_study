# 检查 del 目录是否存在，存在则添加子目录，否则输出警告信息
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/del")
    add_subdirectory(del)
else()
    message(FATAL_ERROR "The 'del' directory does not exist. Skipping add_subdirectory.")
endif()

add_executable(lesson2_1 main.cpp)
target_include_directories(lesson2_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib) # 设置包含目录

# target_link_libraries(lesson2_1 ${CMAKE_PROJECT_ROOT}/lesson2_1/lib/libdel.a) # 指定库文件,这一句相当于下面的两句
# 构建库文件的完整路径
set(LIB_DEL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/libdel.a")

# 检查库文件是否存在
if(EXISTS "${LIB_DEL_PATH}")
    target_link_libraries(lesson2_1 "${LIB_DEL_PATH}")
else()
    message(FATAL_ERROR "The library file 'libdel.a' does not exist at ${LIB_DEL_PATH}. Skipping target_link_libraries.")
endif()