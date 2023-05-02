#include <iostream>
#include <unordered_map>
using namespace std;

bool IsUnique(string s)
{
    unordered_map<char,int> counts;
    for (int i =0; i < s.size();i++)
    {
        if (counts.find(s[i]) == counts.end())
        {
            counts[s[i]] = 1;
        }
        else
        {
            counts[s[i]]++;
        }
    }
    for (auto itr:counts)
    {
        if (itr.second != 1)
        {
            return false;
        }
    }
    return true;
}

bool IsUniqueBetter(string s)
{
    int counts[128] = { 0 };
    for (int i = 0; i < s.size(); i++)
    {
        counts[int(s[i])]++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (counts[i]> 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "Hello";
    string u = "Unik!";
    string a = "1234567890qwertyuiopasdfghjklzxcvbnmm"; 
    cout << IsUniqueBetter(a) << endl;
}