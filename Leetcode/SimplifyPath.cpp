//Leetcode 71
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>
using namespace std;


    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> directories;
        string dir = "";
        char delimiter = '/';
        string ans = "";
        unordered_set<string> unwanted = {".","/","",".."};
        while (!ss.eof())
        {
            getline(ss,dir,delimiter);
            if (dir == ".." && directories.size()>0)
            {
                directories.pop_back();
            }
            else if (unwanted.find(dir) == unwanted.end())
            {
                directories.push_back(dir);
            }
        }
        for (int i = 0; i < directories.size();i++)
        {
            ans += '/'+directories[i];
        }
        
        return (ans == "")? "/" : ans;
    }

int main()
{
    cout << simplifyPath("/home/") << endl;
    return 0;
}