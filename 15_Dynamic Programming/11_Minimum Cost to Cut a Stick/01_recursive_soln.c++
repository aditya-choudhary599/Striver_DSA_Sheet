// Question Link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> get_boundaries(int x, vector<int> &marked, int n)
    {
        pair<int, int> ans;

        // getting the nearest left boundary
        for (int i = x - 1; i >= 0; i -= 1)
        {
            if (marked[i] == true)
            {
                ans.first = i;
                break;
            }
        }

        // getting the nearest right boundary
        for (int i = x + 1; i <= n; i += 1)
        {
            if (marked[i] == true)
            {
                ans.second = i;
                break;
            }
        }

        return ans;
    }

    int f(unordered_map<int, bool> &mp, vector<int> &marked, int n)
    {
        int ans = INT_MAX;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == true)
            {
                // Recursive call
                pair<int, int> p = get_boundaries(it->first, marked, n);
                int curr_cost = p.second - p.first;
                it->second = false;
                marked[it->first] = true;
                ans = min(ans, curr_cost + f(mp, marked, n));

                // Backtracking step
                it->second = true;
                marked[it->first] = false;
            }
        }

        if (ans == INT_MAX)
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }

    int minCost(int n, vector<int> &cuts)
    {
        vector<int> marked(n + 1, false);
        marked[0] = true;
        marked[n] = true;
        unordered_map<int, bool> mp;
        for (auto cut : cuts)
        {
            mp[cut] = true;
        }
        return f(mp, marked, n);
    }
};