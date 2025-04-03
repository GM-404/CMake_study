# 本文档集合了该仓库实现的一些功能如下：
## lesson1_1
文件夹下面包含的cmake文件里面只有包含include文件夹下面的头文件目录，然后使用add_exe（）调用main和add生成可执行文件，include文件夹下包含了add.hh,
在add.hh中加入一个类的举例，用于学习绑定，声明在add.hh函数实现在add.cpp。
## lesson1_2
文件夹下面包含的cmake文件里面只包含调用1_1的include头文件，
在根目录下面设置了根目录的字符串${CMAKE_PROJECT_ROOT},表示整个项目的根目录，也可以用../代指上一集目录
使用本文件夹下面的main和1_1的add生成可执行文件，演示如何跨文件调用，
## lesson2_1
文件夹下面包含del文件和lib文件，其中的cmake文件中包含链接到del文件夹下面的cmake文件夹，然后使用${CMAKE_CURRENT_SOURCE_DIR}/代指当前目录，使用include_directories命令包含静态库中的头文件，然后用main生成可执行文件lesson2_1，之后再使用target_link_libraries将del文件夹下cmake配置生成的libdel.a链接到这个可执行文件中去生成最终的可执行文件，
### del文件夹
其中的cmake文件配置生成了del静态库文件，
使用set为静态库起名字，
使用add_library()使用del.cpp生成static库${lib_name_del} 
这个库文件生成默认在build里面，可以打开注释生成到指定位置
使用set定义要复制的路径，将这个路径变成字符串
然后调价自定义命令，复制静态库到目标路径
## lesson2_2
该文件包含mul动态库生成文件夹和bin文件夹
其中的cmake文件先链接到mul的cmake中去生成指定的动态库
然后包含当前目标下面bin文件夹下面的头文件
之后先用main生成lesson2_2可执行文件
然后使用target_link_libraries()将mul文件夹下cmake配置生成的libmul.dll链接其中生成最终的可执行文件
### mul文件夹
先使用set给动态库起名字，变成字符串方便后期更改
然后设置动态库输出的路径
之后add_library()使用mul.cpp生成名为${dll_name_mul}的SHARED动态库
## lesson3_1
存储力扣刷的题目
## PythonWrapper
该文件加下面主要功能是将c++代码封装为python库，供python调用调式函数实现可视化
首先包含将要封装的c++函数的头文件，然后添加 pybind11 子目录，由于不在同一文件夹下面，所以需要指定输出的二进制文件位置，${CMAKE_BINARY_DIR}指的是在bulid文件夹下面
然后使用pybind11_add_moodule()使用bind_add.cpp和原C++函数一起绑定为lesson
注意添加c++静态库的时候，可以指定目录（已注释），也可也使用find_package()查找，看一下类的绑定只需要.cpp文件，
供给test文件夹下面使用
## Test文件夹
包含Python测试和c++测试两种，
他的cmake文件只向下索引到C++的cmake文件
C++的cmake文件包含
include(CTest)
include(CTest) 用于引入 CMake 自带的 CTest 模块。CTest 是 CMake 提供的一个测试驱动程序，它可以帮助你管理和运行项目中的各种测试。通过引入这个模块，你就可以使用 CTest 提供的一系列命令和功能，例如定义测试、运行测试、生成测试报告等。
enable_testing()
enable_testing() 用于启用当前项目的测试功能。在调用这个命令之后，你就可以使用 add_test() 命令来定义具体的测试用例。
add_subdirectory(${CMAKE_PROJECT_ROOT}/thirdpart/googletest-1.16.0
    ${CMAKE_BINARY_DIR}/thirdpart/googletest) # 非子目录包含的时候需要指定二进制目录
包含测试所需要的第三方库代码
然后添加源文件和测试文件，注意看如何添加静态库文件
然后为生成的文件添加所需头文件，
然后连接到测试库，之后添加测试即可
### Python文件夹
添加导入好的模块使用交互窗口联合编译即可，有时候会报找不到静态库文件，这是因为静态检测不会看添加链接，在doc里面有解决方案
## thridpary
包含的封装c++的pybind11和测试用的c++