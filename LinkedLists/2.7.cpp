#include "LinkedList.h"

Node* intersection(Node* head1, Node* head2)
{
    int size1 = 0;
    int size2 = 0;
    Node* curr1 = head1;
    Node* curr2 = head2;
    while (curr1)
    {
        curr1 = curr1->next;
        size1++;
    }
    while (curr2)
    {
        curr2 = curr2->next;
        size2++;
    }
    curr1 = head1;
    curr2 = head2;
    if (size1 > size2)
    {
        for (int i = 0; i < size1-size2;i++)
        {
            curr1 = curr1->next;
        }
    }
    else
    {
        for (int i = 0;i < size2-size1;i++)
        {
            curr2 = curr2->next;
        }
    }
    while (curr1 != curr2 && curr1 != nullptr)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return curr1;
}

int main()
{
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2;i<6;i++)
    {
        curr->next = new Node(i);
        curr = curr->next;
    }

    Node* secondHead = new Node(6);
    secondHead->next = head->next->next;
    PrintLinkedList(head);
    PrintLinkedList(secondHead);
    cout << intersection(head,secondHead)->value<<endl;
    return 0;
}