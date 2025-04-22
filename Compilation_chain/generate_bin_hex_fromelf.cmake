function(generate_bin_hex_fromelf target_name)
	# 获取输出文件名（不含路径/扩展名）
	get_target_property(target_output_name ${target_name} OUTPUT_NAME)

	if(NOT target_output_name)
		set(target_output_name ${target_name}) # 如果未设置 OUTPUT_NAME，则用原始名
	endif()

	if(CMAKE_C_COMPILER_ID MATCHES "ARMClang") # 检查当前使用的 C 编译器 ID 是否为 ARMClang。 matches
		add_custom_command(TARGET ${target_name}
			POST_BUILD
			COMMAND ${CMAKE_FROMELF} --i32 $<TARGET_FILE:${target_name}> --output $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.hex # 运用 CMAKE_FROMELF 工具将目标文件转换为 Intel Hex 格式的文件。
			COMMAND ${CMAKE_FROMELF} --bin $<TARGET_FILE:${target_name}> --output $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.bin
			COMMAND ${CMAKE_FROMELF} -c $<TARGET_FILE:${target_name}> --output $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.list
			COMMAND ${CMAKE_COMMAND} -E echo "Generated files: ${target_output_name}.hex/bin/list" # 输出一条信息，表明已经生成了 .hex、.bin 和 .list 文件。
		)
	elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
		add_custom_command(TARGET ${target_name}
			POST_BUILD
			COMMAND ${CMAKE_OBJDUMP} -h -S $<TARGET_FILE:${target_name}> > $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.list
			COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${target_name}> $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.hex
			COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${target_name}> $<TARGET_FILE_DIR:${target_name}>/${target_output_name}.bin
			COMMAND ${CMAKE_COMMAND} -E echo "Generated files: ${target_output_name}.hex/bin/list"
		)
	endif()
endfunction()
