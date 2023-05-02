#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int a) : val(a) {}
};

TreeNode* ConstructSubtree(const vector<int>& PreOrder, int& index)
{
    if (PreOrder[index] == -1)
    {
        return nullptr;
    }
    TreeNode* root = new TreeNode(PreOrder[index]);
    index++;
    root->left = ConstructSubtree(PreOrder, index);
    index++;
    root->right = ConstructSubtree(PreOrder, index);
    return root;
}


TreeNode* Reconstruct(vector<int>& PreOrder)
{
    int index = 0;
    TreeNode* root = ConstructSubtree(PreOrder, index);
    return root;
}

void PreOrder(TreeNode* root)
{
    if (root == nullptr)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << root->val << endl;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int main()
{
    vector<int> pre {17,32,7,-1,-1,-1,5,21,-1,-1,-1};
    TreeNode* ans = Reconstruct(pre);
    PreOrder(ans);
    return 0;
}