if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/mul")
    add_subdirectory(mul) # 找到mul文件夹下的CMakeLists.txt文件
else()
    message(FATAL_ERROR "The 'mul' directory does not exist. Skipping add_subdirectory.")
endif()

add_executable(lesson2_2 main.cpp)

target_include_directories(lesson2_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/bin) # 设置包含目录

# # 链接动态库
# target_link_libraries(lesson2_2 ${CMAKE_PROJECT_ROOT}/lesson2_2/bin/libmul.dll)
# # 指定库文件,这一句相当于下面的两句
set(LIB_MUL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin/libmul.dll")

# 检查库文件是否存在
if(EXISTS "${LIB_MUL_PATH}")
    target_link_libraries(lesson2_2 "${LIB_MUL_PATH}")
else()
    message(FATAL_ERROR "The library file 'libdel.a' does not exist at ${LIB_MUL_PATH}. Skipping target_link_libraries.")
endif()