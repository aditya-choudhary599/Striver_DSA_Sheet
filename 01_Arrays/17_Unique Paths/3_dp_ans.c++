// Question Link : https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        return dp[i][j] = f(i + 1, j, m, n, dp) + f(i, j + 1, m, n, dp);
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i -= 1)
        {
            for (int j = n - 1; j >= 0; j -= 1)
            {
                if (i + 1 < m)
                {
                    dp[i][j] += dp[i + 1][j];
                }
                if (j + 1 < n)
                {
                    dp[i][j] += dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};