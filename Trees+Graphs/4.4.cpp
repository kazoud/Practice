#include "TreeNode.h"
#include <unordered_set>
using namespace std;

bool CheckBalanced(TreeNode* root)
{
    unordered_set<int> heights;
    FillHeightsVector(root, heights, 0);
    if (heights.size() > 2)
    {
        return false;
    } 
    unordered_set<int>::iterator itr = heights.begin();
    int val1 = *itr;
    itr++;
    int val2 = *itr;
    int diff = abs(val1-val2);
    return (diff <= 1);
}

void FillHeightsVector(TreeNode* root, unordered_set<int>& heights, int height)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        heights.insert(height);
    }
    if (root->left != nullptr && root->right == nullptr)
    {
        FillHeightsVector(root->left,heights,height+1);
    }
    if (root->right != nullptr && root->left == nullptr)
    {
        FillHeightsVector(root->right,heights,height+1);
    }
    else
    {
        FillHeightsVector(root->right,heights,height+1);
        FillHeightsVector(root->left,heights,height+1);
    }
}

int main()
{
    return 0;
}