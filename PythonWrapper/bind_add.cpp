#include <pybind11/pybind11.h>

#include "add.hh"

PYBIND11_MODULE(lesson, m)
{
    m.def("add", &add);
}