// Question Link : https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while (q.empty() != true)
        {
            bool entered = false;
            int size = q.size();

            for (int i = 0; i < size; i += 1)
            {
                pair<int, int> p = q.front();

                q.pop();

                if (vis[p.first][p.second] == false)
                {
                    // Checking the top
                    if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == 1)
                    {
                        grid[p.first - 1][p.second] = 2;
                        q.push({p.first - 1, p.second});
                        entered = true;
                    }

                    // Checking the right
                    if (p.second + 1 < n && grid[p.first][p.second + 1] == 1)
                    {
                        grid[p.first][p.second + 1] = 2;
                        q.push({p.first, p.second + 1});
                        entered = true;
                    }

                    // Checking the down
                    if (p.first + 1 < m && grid[p.first + 1][p.second] == 1)
                    {
                        grid[p.first + 1][p.second] = 2;
                        q.push({p.first + 1, p.second});
                        entered = true;
                    }

                    // Checking the left
                    if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == 1)
                    {
                        grid[p.first][p.second - 1] = 2;
                        q.push({p.first, p.second - 1});
                        entered = true;
                    }
                }
                vis[p.first][p.second] = true;
            }

            if (entered == true)
            {
                time += 1;
            }
        }

        for (int i = 0; i < m; i += 1)
        {
            for (int j = 0; j < n; j += 1)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return time;
    }
};