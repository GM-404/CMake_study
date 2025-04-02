#include <pybind11/pybind11.h>

// 定义一个简单的 C++ 类
class exampleClass
{
private:
    int data;

public:
    // 构造函数，接受一个整数参数
    exampleClass(int value)
        : data(value) {}
    // 获取数据的方法
    int getData() const
    {
        return data;
    }
    // 设置数据的方法
    void setData(int value)
    {
        data = value;
    }
};

// 使用 pybind11 绑定 C++ 类到 Python
PYBIND11_MODULE(band_class, m)
{
    // 定义模块的文档字符串
    m.doc() = "pybind11 example plugin";

    // 绑定 ExampleClass 类到 Python
    pybind11::class_<exampleClass>(m, "ExampleClass") //"ExampleClass" 是 Python 中的类名
                                                      // 定义构造函数
        .def(pybind11::init<int>())
        // 绑定 getData 方法
        .def("getData", &exampleClass::getData)
        // 绑定 setData 方法
        .def("setData", &exampleClass::setData);
}
