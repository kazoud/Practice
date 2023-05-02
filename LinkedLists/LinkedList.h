#include <iostream>
using namespace std;

class Node{
 public:
    Node* next = nullptr;
    int value;

 public:
    Node(int a): value(a) {}
    
    void appendToTail(int d)
    {
        Node* end = new Node(d);
        Node* n = this;
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = end;
    }
};

Node* DeleteNode(Node* head, int d)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node* n = head;
    if (n->value == d)
    {
        Node* newHead = n->next;
        delete n;
        return newHead;
    }

    while(n->next !=nullptr)
    {
        if (n->next->value == d)
        {
            Node* found = n->next;
            n->next = n->next->next;
            delete found;
            return head;
        }
        n = n->next;
    }
    return head;
}

void PrintLinkedList(Node* head)
{
    Node* n = head;
    while(n!= nullptr)
    {
        cout << n->value << "->";
        n = n->next;
    }
    cout << endl;
}

Node* GenerateRandomLinkedList(int size = 10, int upperBound = 100)
{
    Node* head = new Node(rand()%upperBound);
    for (int i = 0; i < size - 1; i++)
    {
        head->appendToTail(rand()%upperBound);
    }
    return head;
}
