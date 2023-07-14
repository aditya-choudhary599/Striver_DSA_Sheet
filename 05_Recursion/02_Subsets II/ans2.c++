// Question Link : https://leetcode.com/problems/subsets-ii/

// This solution is implemented without using the sets

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int index, int n, vector<int> &nums, vector<int> &vec, vector<vector<int>> &ans)
    {

        ans.push_back(vec);
        if (index == n)
        {
            return;
        }

        int i = index;
        while (i < n)
        {
            vec.push_back(nums[i]);
            f(i + 1, n, nums, vec, ans);
            vec.pop_back();

            i += 1;
            while (i < n && nums[i] == nums[i - 1])
            {
                i += 1;
            }
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> vec = {};
        vector<vector<int>> ans = {};
        f(0, n, nums, vec, ans);
        return ans;
    }
};