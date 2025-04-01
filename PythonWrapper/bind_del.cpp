#include <pybind11/pybind11.h>

#include "del.hh"
PYBIND11_MODULE(del_ctest, m)
{
    m.def("subdel", &del);
}