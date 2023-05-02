#include <iostream>
using namespace std;

bool IsPermutation(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    int counts[128] = { 0 };
    for (int i = 0; i < s1.size(); i++)
    {
        counts[int(s1[i])]++;
    }

    for (int i = 0; i < s2.size();i++)
    {
        counts[int(s2[i])]--;
        if (counts[int(s2[i])] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s1 = "Hello";
    string s2 = "eHlol";
    string s3 = " Hello";
    cout << IsPermutation(s1,s2) << " " << IsPermutation(s1,s3) << " " << IsPermutation(s2,s3) << endl;
}