#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
using namespace std;

struct pair_hash {
    inline size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

bool getPath(vector<vector<bool> > grid,vector<pair<int,int> >& points, int row, int col)
{
    if (row < 0 || col < 0 || !grid[row][col])
    {
        return false;
    }

    bool origin = (row == 0) && (col == 0);
    if (origin || getPath(grid,points,row-1,col) || getPath(grid,points,row,col-1))
    {
        pair<int,int> point = make_pair(row,col);
        points.push_back(point);
        return true;
    }
    return false;
}

vector<pair<int,int> > Path(vector<vector<bool> > grid)
{
    vector<pair<int,int> > points;
    getPath(grid,points, grid.size()-1, grid[0].size()-1);
    return points;
}

///////

bool getPathMemoized(vector<vector<bool> > grid, vector<pair<int,int> >& points, unordered_set<pair<int,int> ,pair_hash> failedPoints, int row, int col)
{
    if (row < 0 || col < 0 || !grid[row][col])
    {
        return false;
    }
    pair<int,int> point = make_pair(row,col);
    if (failedPoints.find(point) != failedPoints.end())
    {
        return false;
    }
    bool origin = (row == 0) && (col == 0);

    if (origin || getPathMemoized(grid, points, failedPoints, row-1,col) ||getPathMemoized(grid, points, failedPoints, row,col-1))
    {
        points.push_back(point);
        return true;
    }
    failedPoints.insert(point);
    return false;
}

vector<pair<int,int> > PathMemoized(vector<vector<bool> > grid)
{
    vector<pair<int, int> > points;
    unordered_set<pair<int,int> ,pair_hash> failedPoints;
    getPathMemoized(grid, points, failedPoints, grid.size()-1, grid[0].size()-1);
    return points;
}

/////////

void PrintPath(vector<pair<int,int> > pairs)
{
    for (int i = 0; i < pairs.size(); i++)
    {
        cout << "(" << pairs[i].first << ", " << pairs[i].second << "), "; 
    }
    cout << endl;
}

int main()
{
    vector<vector<bool> > grid {{1,1,0},{1,0,1},{1,1,1}};
    vector<pair<int,int> > path = Path(grid);
    vector<pair<int,int> > pathMemoized = PathMemoized(grid);
    PrintPath(path);
    PrintPath(pathMemoized);
    return 0;
}