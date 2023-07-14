// Question Link : https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> f(int index, int n, vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return {{}};
        }
        if (index == n)
        {
            return {};
        }
        vector<vector<int>> not_pick = f(index + 1, n, nums, target);

        vector<vector<int>> pick = {};
        if (nums[index] <= target)
        {
            vector<vector<int>> small_ans = f(index, n, nums, target - nums[index]);

            int m = small_ans.size();
            for (int i = 0; i < m; i += 1)
            {
                vector<int> temp = small_ans[i];
                temp.push_back(nums[index]);
                pick.push_back(temp);
            }
        }

        vector<vector<int>> op;
        op.insert(op.end(), not_pick.begin(), not_pick.end());
        op.insert(op.end(), pick.begin(), pick.end());

        return op;
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        return f(0, n, nums, target);
    }
};