#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "subarray.hh"

PYBIND11_MODULE(bind_subarray, m)
{
    m.doc() = "pybind11 plugin for subarray max sum count";

    pybind11::class_<Solution_subarray>(m, "Solution_subarray")
        .def(pybind11::init<>())
        // 绑定函数（确保与C++函数名一致）
        .def("maxSubArray", &Solution_subarray::maxSubArray);
}