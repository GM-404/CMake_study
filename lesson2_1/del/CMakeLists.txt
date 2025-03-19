# 为编译的静态库起名字
set(lib_name_del del)

# 生成静态库
add_library(${lib_name_del} STATIC del.cpp)
