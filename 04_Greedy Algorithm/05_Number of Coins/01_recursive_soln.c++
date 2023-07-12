// Question Link : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int f(int index, int m, int t, int coins[])
    {
        if (t == 0)
        {
            return 0;
        }
        if (index == m)
        {
            return -1;
        }
        int not_pick = f(index + 1, m, t, coins);
        int pick = -1;
        if (coins[index] <= t)
        {
            int small_ans = f(index, m, t - coins[index], coins);
            if (small_ans != -1)
                pick = 1 + small_ans;
        }
        if (not_pick == -1 && pick == -1)
        {
            return -1;
        }
        else if (not_pick != -1 && pick == -1)
        {
            return not_pick;
        }
        else if (not_pick == -1 && pick != -1)
        {
            return pick;
        }
        else if (not_pick != -1 && pick != -1)
        {
            return min(pick, not_pick);
        }
    }

    int minCoins(int coins[], int m, int t)
    {
        return f(0, m, t, coins);
    }
};