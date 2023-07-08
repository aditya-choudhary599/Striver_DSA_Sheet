// Question link : https://leetcode.com/problems/majority-element/description/

// TC : 0(N)
// SC : 0(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n=nums.size();
        int target=n/2; 
        // the c++ int gets automatically the floor

        for(int i=0;i<n;i+=1)
        {
            freq[nums[i]]+=1;
            if(freq[nums[i]]>target)
            {
                return nums[i];
            }
        }

        return -1;
    }
};