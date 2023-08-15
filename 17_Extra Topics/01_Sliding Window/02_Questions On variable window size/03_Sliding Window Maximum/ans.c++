// Question Link : https://leetcode.com/problems/sliding-window-maximum/description/

// Solution Refrence Link : https://www.youtube.com/watch?v=LiSdD3ljCIE

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i+=1)
        {
            pq.push({nums[i],i});
        }
        
        int n=nums.size();
        vector<int> ans;
        
        int left=0,right=k-1;
        for(int i=k;i<n;i+=1)
        {
            // First calculate for the previous window
            while(pq.top().second<left || pq.top().second>right)
            {
                pq.pop();
            }

            ans.push_back(pq.top().first);

            // Sliding the window
            left+=1;
            right+=1;
            pq.push({nums[i],i});
        }

        // For last window
        while(pq.top().second<left || pq.top().second>right)
        {
            pq.pop();
        }

        ans.push_back(pq.top().first);

        return ans;
    }
};