

add_executable(lesson_Eigen main.cpp)

# 查找 Eigen3 库
find_package(Eigen3 3.4 REQUIRED NO_MODULE)

target_link_libraries(lesson_Eigen
    Eigen3::Eigen) # 链接 Eigen3 库

