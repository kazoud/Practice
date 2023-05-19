//Leetcode 208
// The implementation could be improved: A better way would be to ditch the 'val' member and
// index the children according to their alphabetical order 
// (i.e 'children' has fixed size of 26 so we know where each letter should fall).
// Nevertheless, this was my instinctive solution, keeping it for the sake of reference.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
public:
    char val = '\0';
    vector<Trie*> children;
    bool terminal = false;
public:
    Trie() {
    }
    
    Trie(char c): val(c) {}
    
    void insert(string word) {
        Trie* current = this;
        int childrenIndex = 0;
        int wordIndex = 0;
        while (wordIndex < word.size() && childrenIndex < current->children.size())
        {
            if (current->children[childrenIndex]->val == word[wordIndex])
            {
                wordIndex++;
                current = current->children[childrenIndex];
                childrenIndex = 0;
            }
            else
            {
                childrenIndex++;
            }
        }
        
        for (int i = wordIndex; i < word.size(); i++) // if the characters don't already exist, add them
        {
            current->children.push_back(new Trie(word[i])); //create the new node
            current = current->children[children.size()-1]; //go down to the newly created child
        }
        current->terminal = true;
    }
    
    bool search(string word) {
        for (int i = 0; i < this->children.size();i++)
        {
            if (this->children[i]->val == word[0])
            {
                if (word.size() == 1 && this->children[i]->terminal)
                {
                    return true;
                }
                return this->children[i]->search(word.erase(0, 1));
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        for (int i = 0; i < this->children.size();i++)
        {
            if (this->children[i]->val == prefix[0])
            {
                if (prefix.size() == 1)
                {
                    return true;
                }
                return this->children[i]->startsWith(prefix.erase(0,1));
            }
        }
        return false;
    }
};

int main()
{
    string word = "apple";
    string prefix = "app";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith(prefix);
    cout << param_2 << param_3 << endl;
    return 0;
}


 