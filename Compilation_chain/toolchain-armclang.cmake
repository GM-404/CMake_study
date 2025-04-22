# -DCMAKE_TOOLCHAIN_FILE=CMake/armclang.cmake    //这里与工作区配置文件中的toolchain.cmake文件一致

set(CMAKE_SYSTEM_NAME Generic) # 将目标系统的名称设置为 Generic，表示这是一个通用的嵌入式系统，
set(CMAKE_SYSTEM_PROCESSOR cortex-m0plus) # 指定目标处理器为 cortex-m0plus，用于确定编译时的目标架构。

# 强制使用指定的C/C++编译器
set(CMAKE_C_COMPILER_FORCED TRUE) # 强制使用后续指定的 C 和 C++ 编译器，避免 CMake 自动检测。打开强制开关
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_C_COMPILER_ID ARMCLANG) # 设置编译器ID为 ARMCLANG，表示使用 ARM 的 C 编译器。
set(CMAKE_CXX_COMPILER_ID ARMCLANG) # 设置编译器ID为 ARMCLANG，表示使用 ARM 的 C 编译器。

# 查找工具链路径
set(TOOLCHAIN_PATH "D:ARM/ARMCLANG") # 设置工具链路径为 D:ARM/ARMCLANG，表示 ARM 编译器的安装目录。
set(TOOLCHAIN_PREFIX "") # 设置工具链前缀为空字符串，表示不使用特定的前缀。
list(APPEND CMAKE_PREFIX_PATH "${TOOLCHAIN_PATH}/bin") # 将工具链的 bin 目录添加到 CMake 的搜索路径中，以便后续查找工具链命令。

# find_program 用于在 CMAKE_PREFIX_PATH 中查找指定名称的程序。
# 这里分别查找 C 编译器、汇编编译器、C++ 编译器、链接器和 fromelf 工具。
find_program(CUSTOM_C_COMPILER NAMES ${TOOLCHAIN_PREFIX}armclang)
find_program(CUSTOM_ASM_COMPILER NAMES ${TOOLCHAIN_PREFIX}armclang)
find_program(CUSTOM_CXX_COMPILER NAMES ${TOOLCHAIN_PREFIX}armclang)
find_program(CUSTOM_LINKER NAMES ${TOOLCHAIN_PREFIX}armlink)
find_program(CUSTOM_FROMELF NAMES ${TOOLCHAIN_PREFIX}fromelf)

# 将找到的工具链命令分别赋值给 CMake 对应的变量，以便在后续编译和链接过程中使用。
set(CMAKE_C_COMPILER ${CUSTOM_C_COMPILER})
set(CMAKE_ASM_COMPILER ${CUSTOM_ASM_COMPILER})
set(CMAKE_CXX_COMPILER ${CUSTOM_CXX_COMPILER})
set(CMAKE_LINKER ${CUSTOM_LINKER})
set(CMAKE_OBJCOPY ${CUSTOM_FROMELF})
set(CMAKE_FROMELF ${CUSTOM_FROMELF})

# 设置生成的可执行文件的后缀为 .axf，这是 ARM 工具链生成的可执行文件的常见后缀。
set(CMAKE_EXECUTABLE_SUFFIX ".axf ")

# 设置汇编编译器的标志，指定目标架构、处理器、汇编语法等，并抑制特定的警告信息。
set(CMAKE_ASM_FLAGS "--target=arm-arm-none-eabi -mcpu=cortex-m0plus -masm=auto -c -Wa,armasm,--diag_suppress=A1950W -c")

# set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -xc -std=c99")
# 后续几行逐步添加 C 编译器的标志，包括目标架构、处理器、禁用 RTTI、设置字符类型、生成调试信息、启用链接时优化等，并抑制一系列警告信息。
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} --target=arm-arm-none-eabi -mcpu=cortex-m0plus -c  ")
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -fno-rtti  -funsigned-char -fshort-enums -fshort-wchar")
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -gdwarf-4 -ffunction-sections -fdata-sections -flto")
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -Wno-packed -Wno-missing-variable-declarations -Wno-missing-prototypes -Wno-missing-noreturn -Wno-sign-conversion -Wno-nonportable-include-path -Wno-reserved-id-macro -Wno-unused-macros -Wno-documentation-unknown-command -Wno-documentation -Wno-license-management -Wno-parentheses-equality -Wno-reserved-identifier")

# 将 C++ 编译器的标志设置为与 C 编译器相同。
set(CMAKE_CXX_FLAGS " ${CMAKE_C_FLAGS}")

# 添加链接选项，包括启用链接时优化、移除未使用的代码、指定目标处理器、抑制特定警告信息、输出链接摘要信息等。
add_link_options(
    --lto --remove --cpu Cortex-M0+ --diag_suppress 6314,6329 --summary_stderr --load_addr_map_info --xref --callgraph --symbols --info=summarysizes,sizes
)

# 添加编译指令
# 根据不同的构建配置（Debug、Release、MinSizeRel、RelWithDebInfo）添加不同的编译选项。
# 例如，Debug 配置下使用 -O0 禁用优化，-g3 生成详细的调试信息，并定义 DEBUG 宏；Release 配置下使用 -Ofast 进行快速优化，并定义 NDEBUG 宏。
add_compile_options(
    "$<$<CONFIG:Debug>:-O0;-g3;-DDEBUG>"
    "$<$<CONFIG:Release>:-Ofast;-DNDEBUG>"
    "$<$<CONFIG:MinSizeRel>:-Os;-DNDEBUG>"
    "$<$<CONFIG:RelWithDebInfo>:-O2;-g;-DDEBUG>"
)
