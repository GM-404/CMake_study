#include <iostream>
#include <vector>
#include <string>
#include <functional> // std::function
#include <algorithm>  // std::sort

// 输入一个数组，转换为一条单链表
class List_first
{
public:
    int val;
    List_first *next;
    // 构造函数
    // 1. 单个节点的构造函数
    List_first(int x) : val(x), next(nullptr) {};
    // 2. 新增：接收vector数组的构造函数，直接生成链表
    // 注意：这个构造函数会创建整个链表，当前对象作为头节点
    List_first(std::vector<int> &arr) : val(0), next(nullptr)
    {
        if (arr.empty())
        {
            return; // 空数组时，当前节点作为空链表的占位（可根据需求调整）
        }

        // 当前对象作为头节点，初始化第一个值
        this->val = arr[0];
        List_first *cur = this;

        // 循环创建后续节点
        for (size_t i = 1; i < arr.size(); ++i)
        {
            cur->next = new List_first(arr[i]);
            cur = cur->next;
        }
    }
    List_first *createLinkedList(std::vector<int> &arr);                        // 输入一个数组，转换为一条单链表
    int find(int &find_target, std::vector<int> &arr);                          // 查找一个数在单链表中的位置
    List_first *insert(int &insert_target, List_first *&head, int &insert_val); // 增加一个节点
    void deleteNode(int &delete_target_pos, List_first *&head);                 // 删除一个节点

    // 析构函数
};
// 2. 新增：接收vector数组的构造函数，直接生成链表
List_first *List_first::createLinkedList(std::vector<int> &arr)
{
    if (arr.empty())
    {
        // return nullptr;
    }
    List_first *head = new List_first(arr[0]);
    List_first *cur = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        cur->next = new List_first(arr[i]);
        cur = cur->next;
    }
    return head;
};
// 3.查找一个数在单链表中的位置
int List_first::find(int &find_target, std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == find_target)
        {
            return i;
        }
    }
    return -1;
}
// 4.增加节点
List_first *List_first::insert(int &insert_target, List_first *&head, int &insert_val)
{
    List_first *cur = head;
    int count = 1;
    int insert_flag = 0;
    while (cur->next != nullptr)
    {
        count++;
        if (count == insert_target)
        {
            List_first *insert_node = new List_first(insert_val);
            insert_node->next = cur->next;
            cur->next = insert_node;
            insert_flag = 1;
            return head;
        }
        cur = cur->next;
    }
    if (insert_flag == 0)
    {
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        std::cout << "4.the target position is greater than the length of the singly linked list "
                  << insert_val << "  will be added at the end of the list.\n"
                  << std::endl;
        cur->next = new List_first(insert_val);
        insert_flag == 1;
        return head;
    }
    return head;
}
// 5.删除节点
void List_first::deleteNode(int &delete_target_pos, List_first *&head)
{
    List_first *cur = head;
    int count = 1;
    while (cur->next != nullptr)
    {
        count++;
        if (count == delete_target_pos)
        {
            cur->next = cur->next->next;
            return;
        }
        cur = cur->next;
    }
}
int main()
{
    // 定义一个二维向量（多个字符串组）
    std::vector<int> arr = {1, 2, 3, 4, 5};
    // 1. 单个节点的构造函数
    List_first listHelper(10);
    List_first *curs = listHelper.createLinkedList(arr);
    std::cout << "1.Output the value of the head node is:" << listHelper.val << std::endl; // 输出头节点的值
    // 2. 新增：接收vector数组的构造函数，直接生成链表
    List_first *cur = new List_first(arr);
    std::cout << "2.The returned value is that of the head node is:" << cur->val << std::endl; // 返回的是头节点的值
    // 3.查找一个数在单链表中的位置
    int find_target = 3;
    std::cout << "3.The position of the find_target is:" << cur->find(find_target, arr) << std::endl;
    // 4.增加节点
    int insert_target = 5;
    int insert_val = 100;
    cur = cur->insert(insert_target, cur, insert_val);
    // 5.删除节点
    int delete_target_pos = 3;
    cur->deleteNode(delete_target_pos, cur);
    // . 遍历单链表
    while (cur != nullptr)
    {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}