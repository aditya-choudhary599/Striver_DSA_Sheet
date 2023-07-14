// Question Link : https://leetcode.com/problems/combination-sum-ii/description/

// This solution is implemented without using the sets
// This code is inspired from the best solution approach exaplained by striver in his explanantion video of this problem

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int index, int n, vector<int> &nums, int target, vector<int> &vec, vector<vector<int>> &ans)
    {

        if (target == 0)
        {
            ans.push_back(vec);
            return;
            // Here we are returning becoz all the numbers after this are greater than it and it will never add upto that target
        }
        if (index == n)
        {
            return;
        }

        int i = index;

        while (i < n)
        {
            if (nums[i] > target)
                break;

            vec.push_back(nums[i]);
            f(i + 1, n, nums, target - nums[i], vec, ans);
            vec.pop_back();

            i += 1;
            while (i < n && nums[i] == nums[i - 1])
            {
                i += 1;
            }
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> vec = {};
        vector<vector<int>> ans = {};
        f(0, n, nums, target, vec, ans);
        return ans;
    }
};