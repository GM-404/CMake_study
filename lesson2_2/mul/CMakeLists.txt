# 给动态库取一个名字
set(dll_name_mul mul)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lesson2_2/bin) # 设置动态库的输出路径

# 生成动态库
add_library(${dll_name_mul} SHARED mul.cpp)