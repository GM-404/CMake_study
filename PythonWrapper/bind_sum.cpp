#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "sum.h"

/*PYBIND11_MODULE：pybind11 宏，用于定义一个 Python 可导入的模块。
第一个参数 bind_sum：生成的 Python 模块名（导入时用 import bind_sum）。
第二个参数 m：pybind11::module_ 类型的变量，代表模块本身，用于绑定类、函数等。*/
PYBIND11_MODULE(bind_sum, m) // // 定义 Python 模块，模块名为 "bind_sum"，变量 m 是模块对象
{
    // 定义模块的文档字符串 在 Python 中通过 help(bind_sum) 可查看。
    m.doc() = "pybind11 example plugin for finding two numbers in a list that sum to a target";

    // 绑定 ExampleClass 类到 Python
    /*
    pybind11::class_<Solution>：模板类，用于绑定 C++ 类 Solution。
    第一个参数 m：指定绑定到哪个模块（即前面定义的 bind_sum 模块）。
    第二个参数 "Solution"：在 Python 中显示的类名（使用时为 bind_sum.Solution）。*/
    pybind11::class_<Solution>(m, "Solution") //"ExampleClass" 是 Python 中的类名
                                              // 定义构造函数

        /*def：class_ 对象的方法，用于绑定类的成员（构造函数、成员函数等）。
            pybind11::init<>()：表示绑定 C++ 中的默认构造函数 Solution::Solution()，使得 Python 可以通过 Solution() 创建对象。 */
        .def(pybind11::init<>())
        // 绑定 twoSum 方法
        /*第一个参数 "twoSum"：在 Python 中调用该方法时的名称（即 obj.twoSum(...)）。
          第二个参数 &Solution::twoSum：C++ 中 twoSum 方法的地址，指定要绑定的函数*/
        .def("twoSum", &Solution::twoSum);
}
