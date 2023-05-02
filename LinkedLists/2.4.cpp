#include "LinkedList.h"

Node* Partition(Node* head, int x)
{
    Node* leftHead = nullptr;
    Node* rightHead = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* current = head;

    while (current != nullptr)
    {
        if (current->value < x)
        {
            if (leftHead == nullptr)
            {
                leftHead = current;
                left = current;
            }
            else
            {
                left->next = current;
                left = left->next;
            }
        }
        else
        {
            if (rightHead == nullptr)
            {
                rightHead = current;
                right = current;
            }
            else
            {
                right->next = current;
                right = right->next;
            }
        }
        current = current->next;
    }
    left->next = rightHead;
    right->next = nullptr;
    return leftHead;
}

int main()
{
    Node* head = GenerateRandomLinkedList();
    PrintLinkedList(head);
    Node* partition = Partition(head,50);
    PrintLinkedList(partition);
}