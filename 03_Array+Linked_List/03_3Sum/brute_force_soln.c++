// Question Link : https://leetcode.com/problems/3sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i += 1)
        {
            for (int j = i + 1; j < n; j += 1)
            {
                for (int k = j + 1; k < n; k += 1)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        int first_element = min(nums[i], min(nums[j], nums[k]));
                        int third_element = max(nums[i], max(nums[j], nums[k]));
                        int second_element = (nums[i] ^ nums[j] ^ nums[k]) ^ (first_element ^ third_element);
                        st.insert({first_element, second_element, third_element});
                    }
                }
            }
        }

        vector<vector<int>> ans;
        copy(st.begin(), st.end(), back_inserter(ans));
        return ans;
    }
};