#include <iostream>
#include <cmath>
using namespace std; 

bool OneAway(string s1, string s2)
{
    int sizeDiff = s1.size() -s2.size();
    if (abs(sizeDiff)> 1)
    {
        return false;
    }
    string smaller = s1.size() < s2.size()? s1:s2;
    string larger = s1.size() < s2.size()? s2:s1;

    int smallerIndex = 0, largerIndex = 0;
    bool difference = false;
    while (smallerIndex < smaller.size() && largerIndex < larger.size())
    {
        if (smaller[smallerIndex] != larger[largerIndex])
        {
            if (difference)
            {
                return false;
            }
            difference = true;
            if (s1.size() != s2.size())
            {
                largerIndex++;
            }
        }
        largerIndex++;
        smallerIndex++;
    } 
    return true;
}

int main()
{
    string s1 = "apple";
    string s2 = "aple";
    string s3 = "baple";

    cout << OneAway(s1,s2) << " " << OneAway(s2,s3) << " " << OneAway(s1,s3) << " " << endl;
}