// Question Link : https://leetcode.com/problems/longest-consecutive-sequence/description/

// This is as per the best solution that striver explained in his solution video for this question.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i += 1)
        {
            mp[nums[i]] = true;
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (mp.find((it->first) - 1) != mp.end())
            {
                // This means this is not the starting point
                continue;
            }
            else
            {
                // This means this is one of the starting point
                int temp = 1, prev = it->first;
                while (mp.find(prev + 1) != mp.end())
                {
                    temp += 1;
                    prev += 1;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};