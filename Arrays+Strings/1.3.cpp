#include <iostream>
using namespace std;

char* URLify(char* s, int n) //Since we are using pointers, we can even get rid of the 'n' input and derive it on our own
{
    int whiteSpaceCounter = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            whiteSpaceCounter++;
        }
    }

    int newSize = n + 2*whiteSpaceCounter;
    newSize--;
    for (int i = n-1; i > 0;i--)
    {
        if (s[i] == ' ')
        {
            s[newSize] = '0';
            s[newSize-1] = '2';
            s[newSize-2] = '%';
            newSize -=3;
        }
        else
        {
            s[newSize] = s[i];
            newSize--;
        }
    }
    return s;
}

void printCharArray(char* s)
{
    while(*s != '\0')
    {
        cout << *s;
        s++;
    }
    cout << endl;
}
int main()
{
    char hello[] = {'H','e',' ','l','l','o','\0'};
    char* url = URLify(hello,7);
    printCharArray(url);

}