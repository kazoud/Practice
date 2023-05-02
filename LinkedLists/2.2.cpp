#include "LinkedList.h"


int KthToLast(Node* head, int k)
{
    int size = 0;
    Node* n = head;

    while (n != nullptr)
    {
        size++;
        n = n->next;
    }
    n = head;
    for (int i = 0; i < size - k; i++)
    {
        n = n->next;
    }
    return n->value;
}

int KthToLastRecursive(Node* head, int k, int& index)
{
    if (head == nullptr)
    {
        return 0;
    }
    int x = KthToLastRecursive(head->next, k, index);
    index++;
    if (index == k)
    {
        return head->value;
    }
    return x;
}

int KthToLastRecursive(Node* head, int k)
{
    int index = 0;
    return KthToLastRecursive(head, k, index);
}

int KthToLastBetter(Node* head, int k)
{
    Node* p1 = head;
    Node* p2 = head;
    for (int i = 0; i < k; i++)
    {
        p2 = p2->next;
    }
    while(p2 != nullptr)
    {
        p2 = p2->next;
        p1 = p1->next;
    }

    return p1->value;
}

int main()
{
    Node* head = new Node(rand()%100);
    for (int i = 0; i < 10; i++)
    {
        head->appendToTail(rand()%100);
    }

    PrintLinkedList(head);
    cout << KthToLastBetter(head, 3) << endl; 
    cout << KthToLastRecursive(head, 3) << endl; 
}