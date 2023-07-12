// Question Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.

    int f(int index, int time, int n, vector<pair<int, int>> nums)
    {
        if (index == n)
        {
            return 0;
        }
        int not_pick = (f(index + 1, time, n, nums));
        int pick = 0;
        if (time < nums[index].first)
        {
            pick = 1 + f(index + 1, nums[index].second, n, nums);
        }
        return max(pick, not_pick);
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i += 1)
        {
            nums.push_back({start[i], end[i]});
        }
        sort(nums.begin(), nums.end());
        return f(0, 0, n, nums);
    }
};