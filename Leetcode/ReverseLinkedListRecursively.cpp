//Leetcode 206
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverse(ListNode* head, ListNode*& newHead)
    {
        if (head->next == nullptr)
        {
            newHead = head;
            return head;
        }
        ListNode* curr = reverse(head->next, newHead);
        curr->next = head;
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        ListNode* lastElem = reverse(head,newHead);
        if (lastElem != nullptr)
        {
            lastElem->next = nullptr;
        }
        return newHead;
        
    }

};

void printList(ListNode* head)
{
    if (head != nullptr)
    {
        std::cout << head->val << " ";
        printList(head->next);
    }
    else
    {
        std::cout << std::endl;
    }
}

int main()
{
    ListNode* root = new ListNode(1);
    ListNode* curr = root;
    for (int i = 2; i < 6; i++)
    {
        curr->next = new ListNode(i);
        curr = curr->next;
    }
    Solution sol;
    printList(root);
    ListNode* newRoot = sol.reverseList(root);
    printList(newRoot);
    return 0;
}