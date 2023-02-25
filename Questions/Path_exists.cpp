/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.


Example 1:

Input: grid = {{3,0,3,0,0},{3,0,0,0,3}
,{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
Output: 0
Explanation: The grid is-
3 0 3 0 0
3 0 0 0 3
3 3 3 3 3
0 2 3 0 0
3 0 0 1 3
There is no path to reach at (3,1) i,e at
destination from (4,3) i,e source.
Example 2:

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1)
i,e destination.
*/

#include <bits/stdc++.h>
using namespace std;

bool func(int row, int col, int n, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    if (row == n || col == n || row == -1 || col == -1) // reached end point
        return false;
    if (visited[row][col] == 1)
        return false;
    if (grid[row][col] == 2) // reached destination
        return true;
    if (grid[row][col] == 0) // reached wall
        return false;

    visited[row][col] = 1;

    bool b = false;
    b = func(row + 1, col, n, grid, visited);
    if (b == true)
        return true;
    b = func(row - 1, col, n, grid, visited);
    if (b == true)
        return true;
    b = func(row, col + 1, n, grid, visited);
    if (b == true)
        return true;
    return func(row, col - 1, n, grid, visited);
}

bool is_Possible(vector<vector<int>> &grid)
{
    // code here
    pair<int, int> source;
    vector<vector<int>> visited;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < grid[i].size(); j++)
        {
            v.push_back(0);
            if (grid[i][j] == 1)
            {
                source.first = i;
                source.second = j;
            }
        }
        visited.push_back(v);
    }
    int n = grid.size();
    return func(source.first, source.second, n, grid, visited);
};

int main()
{
    vector<vector<int>> grid = {{3, 0, 3, 0, 0}, {3, 0, 0, 0, 3}, {3, 3, 3, 3, 3}, {0, 2, 3, 0, 0}, {3, 0, 0, 1, 3}};
    cout << is_Possible(grid);
    return 0;
}