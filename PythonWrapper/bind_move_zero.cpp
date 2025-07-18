#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "move_zero.hh"

namespace py = pybind11; // 添加命名空间别名，简化代码

PYBIND11_MODULE(bind_move_zero, m)
{
    m.doc() = "pybind11 plugin for moving zeros to the end of array"; // 修正文档字符串，与功能匹配

    // 绑定类时添加详细说明
    py::class_<Solution_Move_Zero>(m, "Solution_Move_Zero", "用于处理移动零问题的类")
        .def(py::init<>(), "默认构造函数") // 为构造函数添加说明
        // 绑定方法时明确参数类型和说明
        .def(
            "Move_Zeroes",
            &Solution_Move_Zero::Move_Zeroes,
            "将数组中的所有零元素移动到末尾，保持非零元素相对顺序不变",
            py::arg("nums"), "要处理的整数数组（原地修改）" // 明确参数名称和说明
        );
}