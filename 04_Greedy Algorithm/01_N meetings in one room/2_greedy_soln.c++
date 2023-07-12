// Question Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i += 1)
        {
            nums.push_back({end[i], start[i]});
        }
        sort(nums.begin(), nums.end());

        int curr_time = -1;
        int ans = 0;
        for (int i = 0; i < n; i += 1)
        {
            if (curr_time < nums[i].second)
            {
                ans += 1;
                curr_time = nums[i].first;
            }
        }
        return ans;
    }
};