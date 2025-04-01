# 为编译的静态库起名字
set(lib_name_del del)

# # 指定生成静态库的输出路径
# set(LIBRARY_OUTPUT_PATH ${CMAKE_PROJECT_ROOT}/lesson2_1/lib)

# 生成静态库
add_library(${lib_name_del} STATIC del.cpp)

# # 设置静态库的输出路径属性
# set_target_properties(${lib_name_del} PROPERTIES
# ARCHIVE_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
# )

# 定义要复制到的目标路径
set(COPY_TARGET_PATH ${CMAKE_PROJECT_ROOT}/lesson2_1/lib)

# 添加自定义命令，在静态库构建完成后进行复制操作
add_custom_command(TARGET ${lib_name_del} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "$<TARGET_FILE:${lib_name_del}>"
    "${COPY_TARGET_PATH}/${CMAKE_STATIC_LIBRARY_PREFIX}${lib_name_del}${CMAKE_STATIC_LIBRARY_SUFFIX}"
    COMMENT "Copying ${lib_name_del} library to ${COPY_TARGET_PATH}"
)