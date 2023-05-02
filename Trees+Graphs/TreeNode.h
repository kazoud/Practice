#include <iostream>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int a): value(a), left(nullptr), right(nullptr) {}
    TreeNode(int a, TreeNode* l, TreeNode* r): value(a), left(l), right(r) {} 
};

void visit(TreeNode* node)
{
    cout << node->value << "->";
}

void InOrderTraversal(TreeNode* root)
{
    if (root != nullptr)
    {
        InOrderTraversal(root->left);
        visit(root);
        InOrderTraversal(root->right);
    }
}

void PreOrderTraversal(TreeNode* root)
{
    if(root!= nullptr)
    {
        visit(root);
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(TreeNode* root)
{
    if (root!=nullptr)
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        visit(root);
    }
}
// To generate a BST from a vector, use 4.2.cpp