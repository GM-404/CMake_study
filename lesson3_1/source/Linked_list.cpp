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