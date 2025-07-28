#include <iostream>
#include <stdexcept> // 包含标准异常类

// 定义一个可能抛出异常的函数
int divide(int a, int b)
{
    if (b == 0)
    {
        // 抛出异常：当除数为0时，主动报告错误
        throw std::invalid_argument("除数不能为0");
    }
    return a / b;
}

int main()
{
    int x = 10, y = 0;
    try
    {
        // 尝试执行可能抛出异常的代码
        int result = divide(x, y);
        std::cout << "结果：" << result << std::endl;
    }
    // 捕获并处理特定类型的异常
    catch (const std::invalid_argument &e)
    {
        std::cout << "错误：" << e.what() << std::endl; // 输出异常信息
    }
    return 0;
}