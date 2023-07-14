// Question Link : https://leetcode.com/problems/subsets-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> f(int index, int n, vector<int> &nums, set<vector<int>> &st)
    {
        if (index == n)
        {
            return {{}};
        }

        vector<vector<int>> small_ans = f(index + 1, n, nums, st);

        vector<vector<int>> final_ans = small_ans;
        int m = final_ans.size();
        for (int i = 0; i < m; i += 1)
        {
            vector<int> temp = final_ans[i];
            st.insert(temp);

            temp.push_back(nums[index]);
            final_ans.push_back(temp);
            st.insert(temp);
        }

        return final_ans;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;

        f(0, n, nums, st);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};