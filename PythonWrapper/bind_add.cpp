
// 在 VSCode 里使用 CMake 配置项目时能正常生成库文件，不过 IntelliSense 提示找不到 Python.h 头文件，
//  这通常是由于 IntelliSense 的配置和 CMake 的配置不一致造成的，而非 CMake 本身配置有误。
#include <pybind11/pybind11.h>

#include "add.hh"

PYBIND11_MODULE(add, m)
{
    m.def("add", &add);
}