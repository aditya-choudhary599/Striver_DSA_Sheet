// Question Link : https://www.codingninjas.com/studio/problems/920321?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

// TC : o(N)
// SC : 0(N)

#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> vec)
{
    int n = vec.size();
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i += 1)
    {
        // Here we can have two possible scenarios
        sum += vec[i];
        if (sum == 0)
        {
            // Case 1: At some place the sum becomes 0 then at that point the length of the subarray will be (i+1)
            ans = max(ans, i + 1);
            continue;
        }
        if (mp.find(sum) != mp.end())
        {
            // Case 2: At some point we get the same sum value that we obtained earlier. This means in middle their is sub-array whose sum is becoming 0. And for that the length will be (i-the first ocuurence of that sum's index)
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            // Only mark the first occurence of the sum to get the max length sequences
            mp[sum] = i;
        }
    }
    return ans;
}