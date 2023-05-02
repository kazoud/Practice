#include "LinkedList.h"

bool DeleteMiddleNode(Node* node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return false;
    }

    Node* ahead = node->next;
    node->value = ahead->value;
    node->next = ahead->next;
    delete ahead;
    return true;
}

int main()
{
    Node* head = GenerateRandomLinkedList();
    PrintLinkedList(head);
    Node* n = head->next->next;
    DeleteMiddleNode(n);
    PrintLinkedList(head);
    return 0;
}