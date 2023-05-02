#include <iostream>
using namespace std;

//Reference: https://www.geeksforgeeks.org/multiple-inheritance-in-c/

class Entity{
private:
    int id;
public:
    Entity(int i): id(i) 
    {   
        cout << "Entity created" << endl;
    }
};

class Ghost: virtual public Entity{
private:
    int health;
public:
    Ghost(int i, int h): Entity(i), health(h) 
    {
        cout << "Ghost created" << endl;
    }
};

class Tree: virtual public Entity{
private:
    int height;
public:
    Tree(int i, int h): Entity(i), height(h)
    {
        cout << "Tree created" << endl;
    }
};

class HauntedTree: public Tree, public Ghost{
public:
    HauntedTree(int i, int height, int health):Entity(i), Tree(i,height), Ghost(i,health)
    {
        cout << "Haunted Tree created" << endl;
    }
};

int main()
{
    HauntedTree hauntedTree(1,10,10);
    return 0;
}

/*
Explanation:

This is the output without using the "virtual" keyword:
    Entity created
    Tree created
    Entity created
    Ghost created
    Haunted Tree created

Note that "Entity created" is printed twice. This is because the constructor of Entity is called twice.

By adding the "virtual" keyword in lines 16 and 26, the problem is solved. HOWEVER, we HAD to explicitly call
the constructor of Entity in line 38, or else the code would not have compiled. This is because in this case,
the Entity class does not have a default constructor.

Conversely, without adding the "virtual" keyword, explicitly calling the constructor of Entity on line 38 would have 
also created a compilation error because it is not a direct or virtual parent of HauntedTree.
*/