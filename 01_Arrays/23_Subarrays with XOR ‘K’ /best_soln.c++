// Problem Link : https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

// This solution is inspired from the best solution algorithm that striver explained in solution video of this problem

#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> vec, int b)
{
    int n = vec.size();
    int ans = 0;
    unordered_map<int, int> mp;
    int helper = 0;
    for (int i = 0; i < n; i += 1)
    {
        helper = helper ^ vec[i];
        if (helper == b)
        {
            ans += 1;
        }
        if (mp.find(helper ^ b) != mp.end())
        {
            ans += mp[helper ^ b];
        }
        mp[helper] += 1;
    }
    return ans;
}