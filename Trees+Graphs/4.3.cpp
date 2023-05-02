#include "TreeNode.h"
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

TreeNode* CreateNode(vector<int> array, int low, int high)
{
    if (low > high)
    {
        return nullptr;
    }
    int mid = (low + high) /2;
    TreeNode* root = new TreeNode(array[mid]);
    root->left = CreateNode(array, low, mid-1);
    root->right = CreateNode(array, mid+1, high);
    return root;
}

TreeNode* CreateBST(vector<int> array)
{
    int n = array.size();
    return CreateNode(array, 0, n-1);
}

class ListNode{
public:
    ListNode* next = nullptr;
    TreeNode* value;

public:
    ListNode(TreeNode* treeNode) : value(treeNode) {}
};

unordered_map<int,ListNode*> ListOfDepths(TreeNode* root)
{
    queue<pair<TreeNode*,int> > queue;
    queue.push(make_pair(root,0));
    unordered_map<int,ListNode*> linkedLists;
    unordered_map<int,ListNode*> depthPointers;
    while(!queue.empty())
    {
        auto nodeDepthPair = queue.front();
        queue.pop();
        TreeNode* currentTreeNode = nodeDepthPair.first;
        ListNode* node = new ListNode(currentTreeNode);
        int depth = nodeDepthPair.second;
        if (depthPointers.find(depth) == depthPointers.end())
        {
            linkedLists[depth] = node;
        }
        else
        {
            auto current = depthPointers[depth];
            current->next = node;
        }
        depthPointers[depth] = node;
        if (currentTreeNode->left!=nullptr)
        {
            queue.push(make_pair(currentTreeNode->left,depth+1));
        }
        if (currentTreeNode->right !=nullptr)
        {        
            queue.push(make_pair(currentTreeNode->right,depth+1));
        }
    }
    return linkedLists; 
}

int main()
{
    vector<int> vec;
    for (int i = 0; i < 20; i++)
    {
        vec.push_back(5*i);
    }
    TreeNode* root = CreateBST(vec);
    unordered_map<int,ListNode*> linkedLists = ListOfDepths(root);
    for (auto i : linkedLists)
    {
        cout << i.first << ": ";
        ListNode* ptr = i.second;
        while(ptr!= nullptr)
        {
            cout << ptr->value->value << "-> ";
            ptr = ptr->next;
        }
        cout << endl;

    }
    return 0;
}

