#include <iostream>
#include <list>

// 队列的基本 API
template <typename E>
class MyQueue
{
public:
    // 向队尾插入元素，时间复杂度 O(1)
    void push(const E &e);

    // 从队头删除元素，时间复杂度 O(1)
    E pop();

    // 查看队头元素，时间复杂度 O(1)
    E peek() const;

    // 返回队列中的元素个数，时间复杂度 O(1)
    int size() const;
};

// 栈的基本 API
template <typename E>
class MyStack
{
public:
    // 向栈顶插入元素，时间复杂度 O(1)
    void push(const E &e);

    // 从栈顶删除元素，时间复杂度 O(1)
    E pop();

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const;

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const;
};
// 用链表实现栈
template <typename E>
class MyLinkedStack
{
private:
    std::list<E> data; // 使用 std::list 作为底层容器

public:
    // 向栈顶插入元素，时间复杂度 O(1)
    void push(const E &e)
    {
        data.push_back(e);
    }

    // 从栈顶删除元素，时间复杂度 O(1)
    E pop()
    {
        E e = data.back(); // 获取栈顶元素
        data.pop_back();   // 删除栈顶元素
        return e;          // 返回栈顶元素
    }

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const
    {
        return data.back(); // 返回栈顶元素
    }

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const
    {
        return data.size(); // 返回栈中的元素个数
    }
};
int main(int argc, char const *argv[])
{
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << "栈顶元素: " << stack.peek() << std::endl; // 输出栈顶元素
    std::cout << "栈大小: " << stack.size() << std::endl;   // 输出栈大小
    std::cout << "弹出元素: " << stack.pop() << std::endl;  // 弹出栈顶元素
    std::cout << "栈大小: " << stack.size() << std::endl;   // 输出栈大小
    return 0;
}