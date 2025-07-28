#include <iostream>
#include <vector>
#include <functional> // std::function
#include <algorithm>  // std::sort

class Doubly_ListNode
{
public:
    int val = 0;
    Doubly_ListNode *next = nullptr;
    Doubly_ListNode *prev = nullptr;
    // 构造函数
    Doubly_ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    // 类函数
    Doubly_ListNode *createDoubleLinkedList(std::vector<int> &arr);
    // 1.查找一个数在双向链表中的位置
    int find(int &find_target, Doubly_ListNode *&arr);
    // 2.增加一个节点
    Doubly_ListNode *insert(int &insert_target, Doubly_ListNode *&head, int &insert_val);
    // 3.删除一个节点
    void deleteNode(int delete_target_pos, Doubly_ListNode *&head);
};
// 0. 创建双向链表
Doubly_ListNode *Doubly_ListNode::createDoubleLinkedList(std::vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }
    Doubly_ListNode *head = new Doubly_ListNode(arr[0]);
    Doubly_ListNode *cur = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        cur->next = new Doubly_ListNode(arr[i]);
        cur->next->prev = cur;
        cur = cur->next;
    }
    return head;
}
// 1.查找一个数在双向链表中的位置
int Doubly_ListNode::find(int &find_target, Doubly_ListNode *&arr)
{
    Doubly_ListNode *cur = arr;
    int count = 1;
    while (cur != nullptr)
    {
        if (cur->val == find_target)
        {
            return count;
        }
        cur = cur->next;
        count++;
    }
    return -1; // 如果未找到，返回-1
}
// 增加一个节点
Doubly_ListNode *Doubly_ListNode::insert(int &insert_target, Doubly_ListNode *&head, int &insert_val)
{
    // 1. 处理空链表：直接创建新节点作为头
    if (head == nullptr)
    {
        head = new Doubly_ListNode(insert_val);
        return head;
    }

    // 2. 计算链表长度（重置cur为head，避免空指针）
    Doubly_ListNode *cur = head;
    int length = 0;
    while (cur != nullptr)
    {
        length++;
        cur = cur->next;
    }
    // std::cout << "length = " << length << std::endl;

    // 3. 检查插入位置合法性（最小为1）
    if (insert_target < 1)
    {
        insert_target = 1; // 强制插入到头部
    }

    // 4. 尾部插入（insert_target超过长度）
    if (insert_target > length)
    {
        cur = head; // 重置cur为head，重新遍历到尾部
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        // 插入新节点到尾部
        Doubly_ListNode *temp = new Doubly_ListNode(insert_val);
        cur->next = temp;
        temp->prev = cur;
        return head;
    }

    // 5. 中间/头部插入（insert_target在合理范围）
    cur = head; // 重置cur为head
    for (int i = 1; i < insert_target - 1; ++i)
    { // 遍历到目标位置的前一个节点
        cur = cur->next;
    }

    Doubly_ListNode *temp = new Doubly_ListNode(insert_val);
    if (insert_target == 1)
    { // 特殊处理头部插入（此时cur仍是head）
        temp->next = head;
        head->prev = temp;
        head = temp; // 更新头节点
    }
    else
    { // 中间插入
        temp->next = cur->next;
        if (cur->next != nullptr)
        { // 若不是尾部前插入，需更新后节点的prev
            cur->next->prev = temp;
        }
        cur->next = temp;
        temp->prev = cur;
    }

    return head;
}
// 删除一个节点
void Doubly_ListNode::deleteNode(int delete_target_pos, Doubly_ListNode *&head)
{
    // 处理空链表
    if (head == nullptr)
    {
        std::cout << "链表为空，无法删除" << std::endl;
        return;
    }
    Doubly_ListNode *cur = head;
    // 1. 特殊处理：删除头节点（delete_target_pos = 1）
    if (delete_target_pos == 1)
    {
        Doubly_ListNode *temp = head; // 保存头节点地址，用于释放
        head = head->next;            // 头节点后移
        if (head != nullptr)
        { // 若链表不止一个节点，更新新头节点的prev
            head->prev = nullptr;
        }
        delete temp; // 释放被删除的头节点
        return;
    }

    // 2. 删除非头节点：找到目标节点的前一个节点（cur）
    int count = 1;
    while (cur != nullptr && count < delete_target_pos - 1)
    {
        cur = cur->next;
        count++;
    }
    // 检查目标位置是否合法（cur存在且cur->next是要删除的节点）
    if (cur == nullptr || cur->next == nullptr)
    {
        std::cout << "删除位置超出链表长度" << std::endl;
        return;
    }
    // 3. 执行删除（释放内存 + 更新指针）
    Doubly_ListNode *temp = cur->next; // 要删除的节点
    cur->next = temp->next;            // 前节点指向后节点的下一个
    if (temp->next != nullptr)
    { // 若删除的不是最后一个节点，更新后节点的prev
        temp->next->prev = cur;
    }
    delete temp; // 释放内存，避免泄漏
}
int main()
{
    // 1.创建双向链表
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Doubly_ListNode cur(0); // 使用默认构造函数创建一个空的头节点
    Doubly_ListNode *head = cur.createDoubleLinkedList(arr);
    // 2.查找一个数在双向链表中的位置
    int find_target = 3;
    std::cout << "2.The position of the find_target is: " << head->find(find_target, head) << std::endl;
    // 3.增加节点
    int insert_target = 3;
    int insert_val = 100;
    head = head->insert(insert_target, head, insert_val);
    // 4.删除节点
    int delete_target_pos = 3;
    head->deleteNode(delete_target_pos, head);
    //.遍历双向链表
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    return 0;
}