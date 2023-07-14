// Question Link : https://www.codingninjas.com/studio/problems/rat-in-a-maze-_8842357?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

#include <bits/stdc++.h>
using namespace std;

vector<string> f(int i, int j, int n, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    if (i == n - 1 && j == n - 1)
    {
        string temp = "";
        return {temp};
    }

    // Marking the curr cell visited
    vis[i][j] = true;

    vector<string> ans;
    vector<string> rcall;

    // Trying up option
    if (i - 1 >= 0 && grid[i - 1][j] == 1 && vis[i - 1][j] == false)
    {
        rcall = f(i - 1, j, n, grid, vis);
        int m = rcall.size();
        for (int x = 0; x < m; x += 1)
        {
            ans.push_back('U' + rcall[x]);
        }
    }

    // Trying right option
    if (j + 1 < n && grid[i][j + 1] == 1 && vis[i][j + 1] == false)
    {
        rcall = f(i, j + 1, n, grid, vis);
        int m = rcall.size();
        for (int x = 0; x < m; x += 1)
        {
            ans.push_back('R' + rcall[x]);
        }
    }

    // Trying down option
    if (i + 1 < n && grid[i + 1][j] == 1 && vis[i + 1][j] == false)
    {
        rcall = f(i + 1, j, n, grid, vis);
        int m = rcall.size();
        for (int x = 0; x < m; x += 1)
        {
            ans.push_back('D' + rcall[x]);
        }
    }

    // Trying left option
    if (j - 1 >= 0 && grid[i][j - 1] == 1 && vis[i][j - 1] == false)
    {
        rcall = f(i, j - 1, n, grid, vis);
        int m = rcall.size();
        for (int x = 0; x < m; x += 1)
        {
            ans.push_back('L' + rcall[x]);
        }
    }

    // Backtrack step
    vis[i][j] = false;

    return ans;
}

vector<string> ratMaze(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
    {
        return {"-1"};
    }

    vector<string> ans = f(0, 0, n, grid, vis);
    if (ans.size() == 0)
    {
        return {"-1"};
    }
    return ans;
}