#ifndef MY_STACK_H
#define MY_STACK_H

#include <stdexcept>
#include <iostream>

// 栈的节点结构
template <typename T>
struct StackNode
{
    T data;             // 节点数据
    StackNode<T> *next; // 指向下一个节点的指针

    // 构造函数
    StackNode(const T &val) : data(val), next(nullptr) {}
};

// 栈的类定义
template <typename T>
class MyStack
{
private:
    StackNode<T> *top; // 栈顶指针
    int size;          // 栈的大小

public:
    // 构造函数
    MyStack() : top(nullptr), size(0) {}

    // 析构函数
    ~MyStack()
    {
        clear();
    }

    // 入栈操作
    void push(const T &val)
    {
        // 创建新节点
        StackNode<T> *newNode = new StackNode<T>(val);

        // 新节点指向当前栈顶
        newNode->next = top;

        // 更新栈顶指针
        top = newNode;

        // 栈大小加1
        size++;
    }

    // 出栈操作
    void pop()
    {
        // 检查栈是否为空
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty, cannot pop element");
        }

        // 保存当前栈顶节点
        StackNode<T> *temp = top;

        // 更新栈顶指针
        top = top->next;

        // 释放原栈顶节点的内存
        delete temp;

        // 栈大小减1
        size--;
    }

    // 获取栈顶元素
    T &getTop() // T & 表示函数的返回类型是 引用（reference），如果没有 &，函数会返回栈顶元素的副本，修改返回值不会影响栈中实际存储的元素。
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty, no top element");
        }
        return top->data;
    }

    // 查看栈顶元素(不修改)
    const T &peek() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Stack is empty, no top element");
        }
        return top->data;
    }

    // 检查栈是否为空
    bool isEmpty() const
    {
        return top == nullptr;
    }

    // 获取栈的大小
    int getSize() const
    {
        return size;
    }

    // 清空栈
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // 打印栈元素(从栈顶到栈底)
    void print() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        std::cout << "Stack elements (top to bottom): ";
        StackNode<T> *current = top;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // MY_STACK_H
