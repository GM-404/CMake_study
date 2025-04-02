#ifndef ADD_HH
#define ADD_HH
#include <iostream>

int add(int a, int b);

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
    int getData();
    // 设置数据的方法
    void setData(int value);
};
#endif