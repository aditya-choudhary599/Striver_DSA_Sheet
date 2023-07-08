// Question Link : https://leetcode.com/problems/longest-consecutive-sequence/description/

// TC : 0(nlog(n))
// SC : 0(n)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i += 1)
        {
            pq.push(nums[i]);
        }
        int ans = 0, temp = 0, prev;
        while (pq.empty() != true)
        {
            if (temp == 0)
            {
                prev = pq.top();
                pq.pop();
                temp = 1;
                continue;
            }
            if (pq.top() == prev)
            {
                // For handling the duplicate values
                pq.pop();
            }
            else if (pq.top() - prev == 1)
            {
                prev = pq.top();
                temp += 1;
                pq.pop();
            }
            else
            {
                ans = max(temp, ans);
                temp = 0;
            }
        }
        // for recording the last iteration as well
        ans = max(temp, ans);
        return ans;
    }
};