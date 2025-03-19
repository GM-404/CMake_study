# 给动态库取一个名字
set(dll_name_mul mul)

# 生成动态库
add_library(${dll_name_mul} SHARED mul.cpp)