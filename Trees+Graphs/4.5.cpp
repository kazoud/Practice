#include "TreeNode.h"
#include <vector>
using namespace std;

void TraverseAndFill(TreeNode* root, vector<int>& vec)
{
    if (root != nullptr)
    {
        InOrderTraversal(root->left);
        vec.push_back(root->value);
        InOrderTraversal(root->right);
    }
}

bool ValidateBST(TreeNode* root)
{
    vector<int> vec;
    TraverseAndFill(root,vec);
    for (int i = 0; i<vec.size()-1;i++)
    {
        if (vec[i] > vec[i+1])
        {
            return false;
        }
    }
    return true;
}

/////////
bool ValidateSubtree(TreeNode* root, int min, int max)
{
    if (root == nullptr)
    {
        return true;
    }

    bool ValidNode = root->value >= min && root->value <= max;
    return ValidNode && ValidateSubtree(root->left, min,root->value) && ValidateSubtree(root->right, root->value, max);
}

bool Validate(TreeNode* root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return ValidateSubtree(root, min, max);
}

int main()
{
    TreeNode* root = new TreeNode(25);
    root->left = new TreeNode(17);
    root->right = new TreeNode(35);
    root->left->right = new TreeNode(25);
    root->left->left = new TreeNode(5);
    cout << Validate(root) << endl;
    return 0;
}