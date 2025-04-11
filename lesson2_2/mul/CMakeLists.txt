# # 给动态库取一个名字
# set(dll_name_mul mul)

# set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lesson2_2/bin) # 设置动态库的输出路径

# # 生成动态库
# add_library(${dll_name_mul} SHARED mul.cpp)
# ————————————————————————————————————————————————新版本————————————————————————————————————————————
# 设置动态库的名称
set(DYNAMIC_LIBRARY_NAME mul)

# 检查源文件是否存在
set(MUL_SOURCE_FILE "${CMAKE_CURRENT_SOURCE_DIR}/mul.cpp")

if(NOT EXISTS ${MUL_SOURCE_FILE})
    message(FATAL_ERROR "The source file 'mul.cpp' does not exist at ${MUL_SOURCE_FILE}.")
endif()

# 设置动态库的输出路径
set(DYNAMIC_LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lesson2_2/bin")
set(LIBRARY_OUTPUT_PATH ${DYNAMIC_LIBRARY_OUTPUT_PATH})
message(STATUS "Dynamic library will be output to: ${DYNAMIC_LIBRARY_OUTPUT_PATH}") # 提示

# 生成动态库
add_library(${DYNAMIC_LIBRARY_NAME} SHARED ${MUL_SOURCE_FILE})