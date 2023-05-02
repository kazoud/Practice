#include <iostream>
using namespace std;

string Compression(string s)
{
    string compressed = "";
    int charCount = 0;
    for (int i = 0; i < s.size();i++)
    {
        charCount++;
        if (i+1 >= s.size() || s[i] != s[i+1])
        {
            compressed += s[i];
            compressed += to_string(charCount);
            charCount = 0;
        }
    }
    return compressed;
}

int main()
{
    string s = "aabcccccaaa";
    cout << Compression(s) << endl;
}