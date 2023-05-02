#include <iostream>
#include <unordered_map>

using namespace std;

bool IsPalindromePermutation(string s)
{
    unordered_map<char,int> counts;
    bool foundOdd = false;
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

    for (auto itr : counts)
    {
        if (itr.second%2 != 0)
        {
            if (foundOdd)
            {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

bool IsPalindromePermutationBitset(string s) //assuming 26 letters alphabet only
{
    bitset<32> counts;
    for (int i = 0; i< s.size();i++)
    {
        int index = int(s[i] - 'a');
        counts[index] = !counts[index];
    }

    return counts.count() < 2;
}

int main()
{
    string palindromePermutation = "tacatco";
    string incorrect = "tacatcoc";
    cout << IsPalindromePermutationBitset(palindromePermutation) << " " << IsPalindromePermutationBitset(incorrect) << endl;
}