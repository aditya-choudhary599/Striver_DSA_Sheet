#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(unordered_map<int, bool> &mp, int n, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (n == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == true)
            {
                // Recursive call
                temp.push_back(it->first);
                it->second = false;
                f(mp, n - 1, ans, temp);

                // Backtrack step
                temp.pop_back();
                it->second = true;
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i += 1)
        {
            mp[nums[i]] = true;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        f(mp, n, ans, temp);
        return ans;
    }
};