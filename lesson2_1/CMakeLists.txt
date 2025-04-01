add_subdirectory(del) # 找到del文件夹下的CMakeLists.txt文件

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

# link_libraries(C:\\Users\\19513\\Desktop\\text\\lesson2_1\\lib\\libdel.a)    #如果不在build下，则需要绝对路径
# link_directories(C:\\Users\\19513\\Desktop\\text\\lesson2_1\\lib)  #得加一行target_link_libraries(lesson2_1 libdel.a) 指定库文件
add_executable(lesson2_1 main.cpp)

target_link_libraries(lesson2_1 ${CMAKE_PROJECT_ROOT}/lesson2_1/lib/libdel.a) # 指定库文件

# target_link_libraries(lesson2_1 C:\\Users\\19513\\Desktop\\cmake\\lesson2_1\\lib\\libdel.a)
