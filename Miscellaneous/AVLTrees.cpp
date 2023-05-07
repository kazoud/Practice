#include <iostream>
#include <algorithm>

//Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
    node() {}
    node(int a, int height): val(a),ht(height),left(nullptr),right(nullptr) {}
} node; 

int height(node* root)
{
    return (root == nullptr)?-1:root->ht;
}

void recomputeHeight(node* root)
{
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    root->ht = std::max(leftHeight,rightHeight)+1;
}

int balanceFactor(node* root)
{
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return leftHeight - rightHeight;
}
node* rotate(node* root, std::string rotation)
{
    if (rotation == "RL")
    {
        node* child = root->right;
        node* grandChild = child->left;
        node* right = grandChild->right;
        root->right = grandChild;
        grandChild->right = child;
        child->left = right;
        recomputeHeight(grandChild);
        recomputeHeight(child);
        recomputeHeight(root);
        return rotate(root, "RR");
    }
    if (rotation == "RR")
    {
        node* child = root->right;
        node* left = child->left;
        child->left = root;
        root->right = left;
        recomputeHeight(root);
        recomputeHeight(child);
        return child;
    }
    
    if (rotation == "LR")
    {
        node* child = root->left;
        node* grandChild = child->right;
        node* left = grandChild->left;
        root->left = grandChild;
        grandChild->left = child;
        child->right = left;
        recomputeHeight(grandChild);
        recomputeHeight(child);
        recomputeHeight(root);
        return rotate(root, "LL");
    }
    else //LL
    {
        node* child = root->left;
        node* right = child->right;
        child->right = root;
        root->left = right;
        recomputeHeight(root);
        recomputeHeight(child);
        return child;
    }
}

node* balance(node* root, bool increaseHeight)
{    
    if (!increaseHeight)
    {
        return root;
    }
    root->ht++;
    if (balanceFactor(root) == 2)
    {
        if(balanceFactor(root->left) == -1)
        {
            return rotate(root, "LR");
        }
        else if(balanceFactor(root->left) == 1)
        {
            return rotate(root, "LL");
        }
    }
    else if(balanceFactor(root) == -2)
    {
        if(balanceFactor(root->right) == 1)
        {
            return rotate(root, "RL");
        }
        else if(balanceFactor(root->right) == -1)
        {
            return rotate(root, "RR");
        }
    }
    return root;
}

node* traverseAndInsert(node* root, node* newNode, bool& increaseHeight)
{
    if (root == nullptr)
    {
        return newNode;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        increaseHeight = true;
    }
    if (newNode->val > root->val)
    {
        root->right = traverseAndInsert(root->right, newNode,increaseHeight);
        return balance(root, increaseHeight);
    }
    else
    {
        root->left = traverseAndInsert(root->left, newNode,increaseHeight);
        return balance(root, increaseHeight);
    }
}

node* insert(node * root,int val)
{
	node* newNode = new node;
    newNode->val = val;
    newNode->ht = 0;
    newNode->left = nullptr;
    newNode->right = nullptr;
    bool increaseHeight = false;
    return traverseAndInsert(root, newNode, increaseHeight);  
}

int main()
{
    node* root = new node(3,2);
    root->left = new node(2,0);
    root->right = new node(4,1);
    root->right->right = new node(5,0);
    node* newRoot = insert(root,6);
    std::cout << newRoot->left->val << " " << newRoot->val << " " << newRoot->right->val <<  " " << newRoot->right->left->val << " " << newRoot->right->right->val << std::endl;
    return 0;
}