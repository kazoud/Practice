#include "TreeNode.h"
#include <vector>

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

int main()
{
    vector<int> vec = {3,6,8,10,14,20,27,67, 128, 243, 1255, 34578};
    TreeNode* root = CreateBST(vec);
    cout << root->value << endl;
    InOrderTraversal(root);
    cout << endl;
    return 0;
}