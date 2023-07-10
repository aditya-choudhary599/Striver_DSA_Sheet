// Question Link : https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0, temp = 0;
        for (int i = 0; i < n; i += 1)
        {
            if (nums[i] == 1)
            {
                temp += 1;
            }
            else
            {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        ans = max(ans, temp);
        return ans;
    }
};