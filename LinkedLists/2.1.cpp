#include "LinkedList.h"
#include <unordered_set>
#include <vector>
using namespace std;

void RemoveDuplicates(Node* head)
{
    vector<Node*> garbage;
    unordered_set<int> values;
    Node* previous = nullptr;
    Node* n =head;
    
    while (n != nullptr)
    {
        if (values.find(n->value) != values.end())
        {
            Node* garbageNode = n;
            previous->next = n->next;
            garbage.push_back(garbageNode);
        }

        else
        {
            values.insert(n->value);
            previous = n;
        }
        n = n->next;
    }

    for (int i = 0; i < garbage.size();i++)
    {
        delete garbage[i];
    }
}

void RemoveDuplicatesNoSpace(Node* head)
{
    Node* n = head;
    vector<Node*> garbage;
    while (n != nullptr)
    {
        Node* previous = n;
        Node* current = n->next;
        while (current != nullptr)
        {
            if (current->value == n->value)
            {
                previous->next = current->next;
                Node* garbageNode = current;
                garbage.push_back(garbageNode);
            }
            else
            {
                previous = current;
            }
            current = current->next;
        }
        n = n->next;
    }
    for (int i = 0; i < garbage.size(); i++)
    {
        delete garbage[i];
    }
}

int main()
{
    Node* head = new Node(rand()%3);
    for (int i = 0; i<10;i++)
    {
        int value = rand()%5;
        head->appendToTail(value);
    }

    PrintLinkedList(head);
    RemoveDuplicatesNoSpace(head);
    PrintLinkedList(head);
}