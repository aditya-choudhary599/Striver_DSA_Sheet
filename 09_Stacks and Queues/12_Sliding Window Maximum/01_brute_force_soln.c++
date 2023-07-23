// Question Link : https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> vec;
        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            dq.push_back(nums[i]);
        }
        for (int i = k; i < n; i++)
        {
            vec.push_back(*max_element(dq.begin(), dq.end()));
            dq.pop_front();
            dq.push_back(nums[i]);
        }
        // For last iteration
        vec.push_back(*max_element(dq.begin(), dq.end()));
        return vec;
    }
};