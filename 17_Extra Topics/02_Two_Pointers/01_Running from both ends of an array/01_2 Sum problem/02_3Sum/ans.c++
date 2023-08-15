// Question Link : https://leetcode.com/problems/3sum/description/

// This solution is inspired by the best solution algorithm that striver explained in his solution video of this question

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> twoSum(vector<int> &nums, int start, int n, int target)
    {
        if (start >= n)
        {
            return {};
        }
        int low = start, high = n - 1;
        vector<vector<int>> ans;
        while (low < high)
        {
            if (nums[low] + nums[high] == target)
            {
                ans.push_back({nums[low], nums[high]});

                low += 1;
                while (low < high && nums[low] == nums[low - 1])
                {
                    low += 1;
                }

                high -= 1;
                while (low < high && nums[high] == nums[high + 1])
                {
                    high -= 1;
                }
            }
            else if (nums[low] + nums[high] < target)
            {
                low += 1;
            }
            else if (nums[low] + nums[high] > target)
            {
                high -= 1;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < n)
        {
            vector<vector<int>> small_ans = twoSum(nums, i + 1, n, 0 - nums[i]);
            int size = small_ans.size();
            for (int j = 0; j < small_ans.size(); j += 1)
            {
                ans.push_back({nums[i], small_ans[j][0], small_ans[j][1]});
            }
            i += 1;
            while (i < n && nums[i] == nums[i - 1])
            {
                i += 1;
            }
        }
        return ans;
    }
};