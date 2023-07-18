// Question Link : https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i += 1)
        {
            freq[nums[i]] += 1;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            pq.push({it->second, it->first});
        }

        vector<int> ans;
        while (k != 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k -= 1;
        }
        return ans;
    }
};