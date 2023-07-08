// Question Link : https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i += 1)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                return {mp[target - nums[i]], i};
            }
            else
            {
                mp[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};