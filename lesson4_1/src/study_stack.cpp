#include <iostream>
#include <string>
#include "my_stack.hh"
// 测试整数栈
// 使用自己编写的一些栈的API来测试栈的基本功能
void testIntStack()
{
    std::cout << "\n=== Testing Integer Stack ===" << std::endl;

    MyStack<int> intStack;

    // 测试入栈
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    std::cout << "After pushing 10, 20, 30: ";
    intStack.print();
    std::cout << "Stack size: " << intStack.getSize() << std::endl;

    // 测试获取栈顶元素
    std::cout << "Top element: " << intStack.peek() << std::endl;

    // 测试出栈
    intStack.pop();
    std::cout << "After popping once: ";
    intStack.print();
    std::cout << "Stack size: " << intStack.getSize() << std::endl;

    // 修改栈顶元素
    intStack.getTop() = 25;
    std::cout << "After modifying top element: ";
    intStack.print();

    // 清空栈
    intStack.clear();
    std::cout << "After clearing stack: ";
    intStack.print();
    std::cout << "Stack size: " << intStack.getSize() << std::endl;
}

// 测试字符串栈
void testStringStack()
{
    std::cout << "\n=== Testing String Stack ===" << std::endl;

    MyStack<std::string> strStack;

    strStack.push("Hello");
    strStack.push("World");
    strStack.push("Stack");
    std::cout << "After pushing strings: ";
    strStack.print();

    std::cout << "Top element: " << strStack.peek() << std::endl;

    strStack.pop();
    std::cout << "After popping once: ";
    strStack.print();
}

// 测试异常处理
void testExceptions()
{
    std::cout << "\n=== Testing Exceptions ===" << std::endl;

    MyStack<int> stack;

    try
    {
        std::cout << "Trying to pop from empty stack... ";
        stack.pop();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to get top from empty stack... ";
        stack.peek();
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

// 栈的应用：检查括号是否匹配
bool isBalancedParentheses(const std::string &s)
{
    MyStack<char> stack;

    for (char c : s)
    {
        // 左括号入栈
        if (c == '(' || c == '{' || c == '[')
        {
            stack.push(c);
        }
        // 右括号处理
        else if (c == ')' || c == '}' || c == ']')
        {
            // 如果栈为空，说明没有匹配的左括号
            if (stack.isEmpty())
            {
                return false;
            }

            char top = stack.peek();
            stack.pop();

            // 检查是否匹配
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // 栈为空说明所有括号都匹配
    return stack.isEmpty();
}

// 测试括号匹配功能
void testParenthesesMatching()
{
    std::cout << "\n=== Testing Parentheses Matching ===" << std::endl;

    std::string test1 = "()[]{}";
    std::string test2 = "([)]";
    std::string test3 = "{[]}";

    std::cout << "Test 1: " << test1 << " => " << (isBalancedParentheses(test1) ? "Balanced" : "Not balanced") << std::endl;
    std::cout << "Test 2: " << test2 << " => " << (isBalancedParentheses(test2) ? "Balanced" : "Not balanced") << std::endl;
    std::cout << "Test 3: " << test3 << " => " << (isBalancedParentheses(test3) ? "Balanced" : "Not balanced") << std::endl;
}

int main()
{
    // 测试基本功能
    testIntStack();
    testStringStack();

    // 测试异常处理
    testExceptions();

    // 测试栈的应用
    testParenthesesMatching();

    return 0;
}
