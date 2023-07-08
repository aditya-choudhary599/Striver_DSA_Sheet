// Question Link : https://leetcode.com/problems/merge-intervals/description/

// TC : 0(nlogn)+0(n)
// SC : 0(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        vector<int> prev_interval = intervals[0];
        int ans_size = 1;
        for (int i = 1; i < n; i += 1)
        {
            vector<int> curr_interval = intervals[i];
            if (prev_interval[1] >= curr_interval[0])
            {
                ans[ans_size - 1] = {prev_interval[0], max(prev_interval[1], curr_interval[1])};
                prev_interval = ans[ans_size - 1];
            }
            else
            {
                ans.push_back(curr_interval);
                ans_size += 1;
                prev_interval = curr_interval;
            }
        }

        return ans;
    }
};