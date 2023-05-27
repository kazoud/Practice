class AugmentedNode{
public:
    int value;
    AugmentedNode* left;
    AugmentedNode* right;
    AugmentedNode* parent;

public:
    AugmentedNode(int a): value(a), left(nullptr), right(nullptr),parent(nullptr) {}
    AugmentedNode(int a, AugmentedNode* l, AugmentedNode* r): value(a), left(l), right(r),parent(nullptr) {} 
};

AugmentedNode* Successor(AugmentedNode* node)
{
    AugmentedNode* curr = node;
    if (curr->right)
    {
        curr = curr->right;
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }
    else
    {
        while(curr->parent->left != curr && curr->parent != nullptr)
        {
            curr = curr->parent;
        }
        return curr->parent;
    }
}

int main()
{
    return 0;
}