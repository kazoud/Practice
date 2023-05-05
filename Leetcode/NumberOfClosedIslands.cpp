//Leetcode 1254
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<bool> row(grid[0].size(),false);
        vector<vector<bool>> visited(grid.size(),row);
        int closedIslands = 0;
        for (int i = 0; i < grid.size();i++)
        {
            for (int j = 0; j < grid[0].size();j++)
            {
                if (grid[i][j] == 0 && !visited[i][j] && CheckForIsland(i,j,grid,visited))
                {
                   closedIslands++; 
                }
            }
        }
        return closedIslands;
    }
    
    bool CheckForIsland(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited)
    {
        stack<pair<int,int>> s;
        s.push(make_pair(i,j));
        bool isClosed = true;
        while(!s.empty())
        {
            pair<int,int> current = s.top();
            s.pop();
            if (grid[current.first][current.second] == 0 && !visited[current.first][current.second])
            {                    
                visited[current.first][current.second] = true;
                if (i > 0 && i < grid.size()-1 && j > 0 && j < grid[0].size()-1)
                {
                    pair<int,int> up = make_pair(current.first-1,current.second);                             s.push(up);
                    pair<int,int> down = make_pair(current.first+1,current.second);                           s.push(down);
                    pair<int,int> left = make_pair(current.first,current.second-1);                           s.push(left);
                    pair<int,int> right = make_pair(current.first,current.second+1);  
                    s.push(right);
                }
                else
                {
                    isClosed = false;
                }
            } 
        }
        return isClosed;
    }
};