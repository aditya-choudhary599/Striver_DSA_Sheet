// Question Link : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int f(int index, int m, int t, int coins[], vector<vector<int>> &dp)
    {
        if (t == 0)
        {
            return 0;
        }
        if (index == m)
        {
            return -1;
        }
        if (dp[index][t] != -2)
        {
            return dp[index][t];
        }

        int not_pick = f(index + 1, m, t, coins, dp);
        int pick = -1;
        if (coins[index] <= t)
        {
            int small_ans = f(index, m, t - coins[index], coins, dp);
            if (small_ans != -1)
            {
                pick = 1 + small_ans;
            }
        }
        if (not_pick == -1 && pick == -1)
        {
            return dp[index][t] = -1;
        }
        else if (not_pick != -1 && pick == -1)
        {
            return dp[index][t] = not_pick;
        }
        else if (not_pick == -1 && pick != -1)
        {
            return dp[index][t] = pick;
        }
        else if (not_pick != -1 && pick != -1)
        {
            return dp[index][t] = min(pick, not_pick);
        }
    }

    int minCoins(int coins[], int m, int t)
    {
        vector<vector<int>> dp(m, vector<int>(t + 1, -2));
        return f(0, m, t, coins, dp);
    }
};