add_subdirectory(mul) # 找到mul文件夹下的CMakeLists.txt文件

include_directories(./bin)

add_executable(lesson2_2 main.cpp)

# 链接动态库
target_link_libraries(lesson2_2 ${CMAKE_SOURCE_DIR}/lesson2_2/bin/libmul.dll)

# target_link_libraries(lesson2_2 C:\\Users\\19513\\Desktop\\cmake\\lesson2_2\\bin\\libmul.dll)