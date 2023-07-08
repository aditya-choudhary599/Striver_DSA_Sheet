// Question Link : https://leetcode.com/problems/sort-colors/description/

// TC: O(N)
// SC :O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp(n, 1);
        int i = 0, j = n - 1;
        for (int x = 0; x < n; x += 1)
        {
            if (nums[x] == 0)
            {
                temp[i] = 0;
                i += 1;
            }
            else if (nums[x] == 2)
            {
                temp[j] = 2;
                j -= 1;
            }
        }
        nums = temp;
        return;
    }
};