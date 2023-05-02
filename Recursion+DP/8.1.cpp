#include <iostream>
using namespace std;

int TripleStep(int n)
{
    if (n<=3)
    {
        return n;
    }
    int a = 1, b = 2, c = 3, d;

    for (int i = 3; i < n; i++)
    {
        d = a+b+c;
        a = b;
        b = c;
        c = d;
    }
    return d;
}

int main()
{
    cout << TripleStep(36) << endl;
    return 0;
}