#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "sum.h"
PYBIND11_MODULE(bind_sum, m)
{
    // 定义模块的文档字符串
    m.doc() = "pybind11 example plugin";

    // 绑定 ExampleClass 类到 Python
    pybind11::class_<Solution>(m, "Solution") //"ExampleClass" 是 Python 中的类名
                                              // 定义构造函数
        .def(pybind11::init<>())
        // 绑定 twoSum 方法
        .def("twoSum", &Solution::twoSum);
}
