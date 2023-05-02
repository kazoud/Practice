#include "LinkedList.h"

Node* Sum(Node* head1, Node* head2)
{
    Node* current = nullptr;
    Node* newHead = nullptr;
    bool carry = false;
    while(head1 || head2)
    {
        int operand1 = head1? head1->value:0;
        int operand2 = head2? head2->value:0;
        int sum = operand1 + operand2 + int(carry);
        carry = (sum >= 10);
        Node* node = new Node(sum%10);
        if (!current)
        {
            current = node;
            newHead = node;
        }
        else
        {
            current->next = node;
            current = current->next;
        }
        if (head1)
        {
            head1 = head1->next;
        }
        if (head2)
        {
            head2 = head2->next;
        }
    }
    if (carry)
    {
        Node* one = new Node(1);
        current->next = one;
        current = current->next;
    }
    return newHead;
}

int main()
{
    Node* head1 = GenerateRandomLinkedList(8,10);
    Node* head2 = GenerateRandomLinkedList(5,10);
    Node* sum = Sum(head1,head2);
    PrintLinkedList(head1);
    PrintLinkedList(head2);
    PrintLinkedList(sum);
    return 0;
}