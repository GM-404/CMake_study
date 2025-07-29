add_executable(study_letter_combination src/study_letter_combination.cpp)
add_executable(study_list src/study_list.cpp)
add_executable(study_list_pro src/study_list_pro.cpp)
add_executable(study_double_lists src/study_double_lists.cpp)
add_executable(study_double_lists_pro src/study_double_lists_pro.cpp)
add_executable(study_throw src/study_throw.cpp)
add_executable(study_dynamic_array src/study_dynamic_array.cpp)

# 栈的学习
add_executable(study_stack src/study_stack.cpp)
target_include_directories(study_stack PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
