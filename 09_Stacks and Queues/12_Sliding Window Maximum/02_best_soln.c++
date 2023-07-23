// Question Link : https://leetcode.com/problems/sliding-window-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // Deque to store indices of elements in descending order of their values

        for (int i = 0; i < n; ++i)
        {
            // Remove elements from the front of the deque that are outside the current window
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            // Remove elements from the back of the deque that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // The front of the deque will always point to the maximum element's index within the window
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};
