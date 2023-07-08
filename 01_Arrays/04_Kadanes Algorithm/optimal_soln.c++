// Question link : https://leetcode.com/problems/maximum-subarray/description/

// Kadane's Algorithm Implementation

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i += 1)
        {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum <= 0)
            {
                sum = 0;
            }
        }
        return ans;
    }
};