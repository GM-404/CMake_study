#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "four_sum.hh"

PYBIND11_MODULE(bind_four_sum, m)
{
    // 定义模块的文档字符串 在 Python 中通过 help(bind_sum) 可查看。
    m.doc() = "pybind11 example plugin for finding four numbers in a list that sum to a target";

    // 绑定 Solution_four_sum 类到 Python
    pybind11::class_<Solution_four_sum>(m, "Solution_four_Sum") //"ExampleClass" 是 Python 中的类名
                                                                // 定义构造函数
        .def(pybind11::init<>())
        .def("four_Sum", &Solution_four_sum::four_Sum);

    // 绑定 Solution_four_sum_quick 类到 Python
    pybind11::class_<Solution_four_sum_quick>(m, "Solution_four_sum_quick") //"ExampleClass" 是 Python 中的类名
                                                                            // 定义构造函数
        .def(pybind11::init<>())
        .def("four_Sum", &Solution_four_sum_quick::four_Sum);
}
