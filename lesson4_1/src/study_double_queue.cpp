#include <iostream>
#include <list>

// template <typename E>
// class MyDeque
// {
// public:
//     // 从队头插入元素，时间复杂度 O(1)
//     void addFirst(E e);

//     // 从队尾插入元素，时间复杂度 O(1)
//     void addLast(E e);

//     // 从队头删除元素，时间复杂度 O(1)
//     E removeFirst();

//     // 从队尾删除元素，时间复杂度 O(1)
//     E removeLast();

//     // 查看队头元素，时间复杂度 O(1)
//     E peekFirst();

//     // 查看队尾元素，时间复杂度 O(1)
//     E peekLast();
// };

// 链表实现队列，时间复杂度 O(1)
template <typename E>
class MyListDeque
{
    std::list<E> list;

public:
    // 从队头插入元素，时间复杂度 O(1)
    void addFirst(const E &e)
    {
        list.push_front(e);
    }

    // 从队尾插入元素，时间复杂度 O(1)
    void addLast(const E &e)
    {
        list.push_back(e);
    }

    // 从队头删除元素，时间复杂度 O(1)
    E removeFirst()
    {
        E firstElement = list.front();
        list.pop_front();
        return firstElement;
    }

    // 从队尾删除元素，时间复杂度 O(1)
    E removeLast()
    {
        E lastElement = list.back();
        list.pop_back();
        return lastElement;
    }

    // 查看队头元素，时间复杂度 O(1)
    E peekFirst()
    {
        return list.front();
    }

    // 查看队尾元素，时间复杂度 O(1)
    E peekLast()
    {
        return list.back();
    }
};

// 使用数组实现队列
template <typename E>
class CycleArray
{
public:
    void addFirst(E e);
    void addLast(E e);
    E removeFirst();
    E removeLast();
    E getFirst();
    E getLast();
};
template <typename E>
class MyArrayDeque
{
private:
    CycleArray<E> arr;

public:
    // 从队头插入元素，时间复杂度 O(1)
    void addFirst(E e)
    {
        arr.addFirst(e);
    }

    // 从队尾插入元素，时间复杂度 O(1)
    void addLast(E e)
    {
        arr.addLast(e);
    }

    // 从队头删除元素，时间复杂度 O(1)
    E removeFirst()
    {
        return arr.removeFirst();
    }

    // 从队尾删除元素，时间复杂度 O(1)
    E removeLast()
    {
        return arr.removeLast();
    }

    // 查看队头元素，时间复杂度 O(1)
    E peekFirst()
    {
        return arr.getFirst();
    }

    // 查看队尾元素，时间复杂度 O(1)
    E peekLast()
    {
        return arr.getLast();
    }
};
int main()
{
    MyListDeque<int> deque;
    deque.addFirst(1);
    deque.addFirst(2);
    deque.addLast(3);
    deque.addLast(4);

    std::cout << deque.removeFirst() << std::endl; // 2
    std::cout << deque.removeLast() << std::endl;  // 4
    std::cout << deque.peekFirst() << std::endl;   // 1
    std::cout << deque.peekLast() << std::endl;    // 3
    return 0;
}