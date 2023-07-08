// Problem Link : https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int n)
    {
        if (n == 1)
        {
            return {{1}};
        }
        if (n == 2)
        {
            return {{1}, {1, 1}};
        }
        vector<vector<int>> ans = {{1}, {1, 1}};
        for (int i = 3; i <= n; i += 1)
        {
            vector<int> temp = {1};

            vector<int> prev = ans[(i - 1) - 1]; // 0 based indexing
            int prev_size = prev.size();
            for (int j = 0; j < prev_size - 1; j++)
            {
                temp.push_back(prev[j] + prev[j + 1]);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }
        return ans;
    }
};