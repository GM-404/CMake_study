#include <iostream>
#include <stack>
// 使用标准库中的栈
int main()
{
    std::stack<int> s;

    // 入栈
    s.push(10);
    s.push(20);
    s.push(30);

    // 访问栈顶元素
    std::cout << "栈顶元素: " << s.top() << std::endl; // 输出 30

    // 修改栈顶元素（通过 top() 返回的引用）
    s.top() = 35;
    std::cout << "修改后栈顶元素: " << s.top() << std::endl; // 输出 35

    // 出栈
    s.pop();
    std::cout << "出栈后栈顶元素: " << s.top() << std::endl; // 输出 20

    // 栈状态查询
    std::cout << "栈是否为空: " << (s.empty() ? "是" : "否") << std::endl; // 输出 否
    std::cout << "栈中元素数量: " << s.size() << std::endl;                // 输出 2

    return 0;
}