#include "Linked_list.hh"

bool Linked_Node::hasCycle(Linked_Node *head)
{
    Linked_Node *fast = head;
    Linked_Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
bool Linked_Node::hasCycle2(Linked_Node *head)
{
    std::unordered_map<Linked_Node *, int> map;
    while (head != nullptr)
    {
        if (map.find(head) != map.end())
        {
            return true;
        }
        map[head] = head->val; // 存储节点地址和对应的值
        head = head->next;
    }
    return false;
}