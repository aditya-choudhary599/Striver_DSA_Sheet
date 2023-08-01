// Question Link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 1)
        {
            for (int j = i; j < n; j += 1)
            {
                ans = max(ans, nums[i] ^ nums[j]);
            }
        }
        return ans;
    }
};