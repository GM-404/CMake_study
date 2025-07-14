#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "letter_combination.hh"
PYBIND11_MODULE(bind_letter, m)
{
    // 定义模块的文档字符串
    m.doc() = "pybind11 example plugin for finding two numbers in a list that sum to a target";

    // 绑定 ExampleClass 类到 Python
    pybind11::class_<letter_combination>(m, "letter_combination") //"ExampleClass" 是 Python 中的类名
                                                                  // 定义构造函数
        .def(pybind11::init<>())
        // 绑定 twoSum 方法
        .def("groupAnagrams", &letter_combination::groupAnagrams)
        .def("groupAnagrams1", &letter_combination::groupAnagrams1);
}
