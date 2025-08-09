# 一些练习，当想运行的时候再打开，不然编译的太多了
# add_executable(study_letter_combination src/study_letter_combination.cpp)
# add_executable(study_list src/study_list.cpp)
# add_executable(study_list_pro src/study_list_pro.cpp)
# add_executable(study_double_lists src/study_double_lists.cpp)
# add_executable(study_double_lists_pro src/study_double_lists_pro.cpp)
# add_executable(study_throw src/study_throw.cpp)
# add_executable(study_dynamic_array src/study_dynamic_array.cpp)

# 栈的学习
add_executable(study_stack0 src/study_stack0.cpp)

add_executable(study_stack src/study_stack.cpp)
target_include_directories(study_stack PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 堆的学习
add_executable(study_heap src/study_heap.cpp)

#队列的学习
add_executable(study_queue src/study_queue.cpp)
add_executable(study_double_queue src/study_double_queue.cpp)

# 二叉树的学习
add_executable(study_tree src/study_tree.cpp)
target_include_directories(study_tree PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
